/***************************************************************************
 *   Copyright (C) 2002~2005 by Yuking                                     *
 *   yuking_net@sohu.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <libintl.h>
#include <dbus/dbus.h>

#include "fcitx/module.h"
#include "fcitx/fcitx.h"
#include "fcitx/hook.h"
#include "fcitx/ime.h"
#include "fcitx-config/xdg.h"
#include "fcitx-utils/log.h"
#include "fcitx-utils/utils.h"
#include "fcitx/keys.h"
#include "fcitx/frontend.h"
#include "fcitx/instance.h"
#include <fcitx/context.h>

static void* AutoOnboardCreate(FcitxInstance* instance);
static void ReloadAutoOnboard(void* arg);
static void FcitxInstanceInputFocus(void* arg);
static void FcitxInstanceInputUnFocus(void* arg);

typedef struct _FcitxAutoOnboard {
    FcitxInstance* owner;
    bool mOnboardRealShow;
} FcitxAutoOnboard;

FCITX_DEFINE_PLUGIN(fcitx_auto_onboard, module, FcitxModule) = {
    AutoOnboardCreate,
    NULL,
    NULL,
    NULL,
    ReloadAutoOnboard
};

FCITX_EXPORT_API int ABI_VERSION = FCITX_ABI_VERSION;

#define ONBOARD_DBUS_SERVICE "org.onboard.Onboard"
#define ONBOARD_DBUS_PATH "/org/onboard/Onboard/Keyboard"
#define ONBOARD_DBUS_INTERFACES "org.onboard.Onboard.Keyboard"
static bool dbus_linkOnboardDbusServer()
{
    bool ret_value;
    DBusError err;

    dbus_error_init(&err);
    DBusConnection *conn = dbus_bus_get(DBUS_BUS_SESSION, &err);
    if(dbus_error_is_set(&err)) {
    //        FcitxLog(WARNING, "dbus_bus_get Error (%s)", err.message);
     dbus_error_free(&err);
     return false;    //dbus出错时默认为开启
    }

    dbus_error_init(&err);
    bool ret = dbus_bus_name_has_owner(conn, ONBOARD_DBUS_SERVICE,&err);
    if (dbus_error_is_set(&err)) {
        FcitxLog(WARNING, "dbus_bus_name_has_owner Error (%s)\n", err.message);
        dbus_error_free(&err);

        return false;    //dbus出错时默认为开启
    }
    else
    {
        if (ret)
            ret_value = true;
        else
        {
            ret_value = false;
            //char* argv_exec[]= {"/usr/bin/onboard","-t","Droid","--hide",NULL};
            //fcitx_utils_start_process(argv_exec);
        }
    }

    // free the message
    dbus_connection_unref(conn);
    //dbus_connection_close(conn);

    FcitxLog(WARNING, "dbus_linkOnboardDbusServer: %d", ret_value);
    return ret_value;
}

static bool dbus_setOnboardVisible(bool bFlg)
{
    bool ret_value;
    DBusError err;

    dbus_error_init(&err);
    DBusConnection *conn = dbus_bus_get(DBUS_BUS_SESSION, &err);
    if(dbus_error_is_set(&err)) {
     FcitxLog(WARNING, "dbus_bus_get Error (%s)\n", err.message);
     dbus_error_free(&err);
     return false;
    }

    dbus_error_init(&err);
    bool ret = dbus_bus_name_has_owner(conn, ONBOARD_DBUS_SERVICE, &err);
    if (dbus_error_is_set(&err)) {
        FcitxLog(WARNING, "dbus_bus_name_has_owner Error (%s)\n", err.message);
        dbus_error_free(&err);
        ret_value = false;
    }
    else
    {
     if (ret)
         ret_value = true;
     else
     {
         ret_value = false;
     }
    }

    if (ret_value == false) {
        dbus_connection_unref(conn);
        FcitxLog(WARNING, "dbus_setOnboardVisible-11: %d\n", ret_value);
        return false;
    }

    DBusMessage * msg = NULL;
    if(bFlg)
    {
        msg = dbus_message_new_method_call (ONBOARD_DBUS_SERVICE ,
                     ONBOARD_DBUS_PATH, ONBOARD_DBUS_INTERFACES, "show_without_keyboard");
    }
    else
    {
        FcitxLog(WARNING, "dbus_setOnboardVisible-hide: %d\n", ret_value);
        msg = dbus_message_new_method_call (ONBOARD_DBUS_SERVICE ,
                     ONBOARD_DBUS_PATH, ONBOARD_DBUS_INTERFACES, "Hide");
        FcitxLog(WARNING, "dbus_setOnboardVisible-hide: %d\n", ret_value);
    }

    if (msg == NULL) {
        dbus_connection_unref(conn);
        FcitxLog(WARNING, "dbus_setOnboardVisible-22: %d\n", ret_value);
        return false;
    }
    if (NULL == dbus_connection_send_with_reply_and_block (conn , msg ,10000, NULL)) {
//    dbus_connection_send(conn , msg ,-1);
//    dbus_connection_flush(conn);
        dbus_connection_unref(conn);
        dbus_message_unref (msg);
        FcitxLog(WARNING, "dbus_setOnboardVisible-33: %d\n", ret_value);
    }
    dbus_message_unref (msg);
    msg = NULL;

    // free the message
    dbus_connection_unref(conn);
    //dbus_connection_close(conn);

    FcitxLog(WARNING, "dbus_setOnboardVisible: %d\n", ret_value);
    return ret_value;
}

/**
* onBoard State
**/
typedef enum _OnbaordState {
    IS_HIDE = 0,
    IS_SHOW,
    IS_LINK,
    IS_UNLINK
} OnbaordState;

static OnbaordState dbus_onboardState()
{
    OnbaordState ret_value;
    DBusError err;

    dbus_error_init(&err);
    DBusConnection *conn = dbus_bus_get(DBUS_BUS_SESSION, &err);
    if(dbus_error_is_set(&err)) {
        FcitxLog(WARNING, "dbus_bus_get Error (%s)", err.message);
        dbus_error_free(&err);
        return IS_UNLINK;
    }

    dbus_error_init(&err);
    bool ret = dbus_bus_name_has_owner(conn, ONBOARD_DBUS_SERVICE,&err);
    if (dbus_error_is_set(&err)) {
        FcitxLog(WARNING, "dbus_bus_name_has_owner Error (%s)", err.message);
        dbus_error_free(&err);
        ret_value = IS_UNLINK;
    }
    else
    {
     if (ret)
         ret_value = IS_LINK;
     else
     {
         ret_value = IS_UNLINK;
     }
    }

    if (ret_value == IS_UNLINK) {
     return IS_UNLINK;
    }

    DBusMessage * msg = NULL;
    msg = dbus_message_new_method_call (ONBOARD_DBUS_SERVICE ,
                 ONBOARD_DBUS_PATH, ONBOARD_DBUS_INTERFACES, "Get");
    if (msg == NULL) {
        dbus_connection_unref(conn);
        return IS_UNLINK;
    }

    /*为消息添加函数的参数
    第一个参数：字符串类型的，用来显示对话框的提醒内容
    第二个参数：整数类型的，用来标志对话框的类型
    第三个参数：字符串类型的，用来显示确认按钮的内容
    注意：传递的都是参数值的地址
    */
    const char * interface = ONBOARD_DBUS_INTERFACES;
    const char * propertieName = "Visible";
    if (! dbus_message_append_args (msg ,
        DBUS_TYPE_STRING , &interface ,
        DBUS_TYPE_STRING , &propertieName ,
        DBUS_TYPE_INVALID )) {
        FcitxLog(FATAL,"Ran out of memory while constructing args/n");
        exit( EXIT_FAILURE );
    }
    DBusMessage *reply;
    reply = dbus_connection_send_with_reply_and_block (conn, msg, -1, &err);
    if (NULL == reply)
    {
        FcitxLog(FATAL,"couldn't send message: %s\n", err.message);
        dbus_connection_unref(conn);
        dbus_message_unref (msg);
        return IS_UNLINK;
    }
    boolean level = 0;
    DBusMessageIter args;
    // read the parameters
    if (!dbus_message_iter_init(reply, &args))
        FcitxLog(FATAL, "reply has no arguments!\n");
    else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args))
        FcitxLog(FATAL, "Argument is not int!\n");
    else
    {
        dbus_message_iter_get_basic(&args, &level);
        if(level)
        ret_value = IS_SHOW;
        else
        ret_value = IS_HIDE;
    }

    dbus_message_unref (msg);
    dbus_connection_unref(conn);
    msg = NULL;

    FcitxLog(WARNING, "dbus_setOnboardVisible: %d-%d", ret_value,level);
    return ret_value;
}

void ReloadAutoOnboard(void* arg)
{
    FcitxLog(WARNING, "ReloadFullWidthChar");
}

void* AutoOnboardCreate(FcitxInstance* instance)
{
    FcitxAutoOnboard* autoOnboard = fcitx_utils_malloc0(sizeof(FcitxAutoOnboard));

    autoOnboard->owner = instance;
    autoOnboard->mOnboardRealShow = false;

    FcitxIMEventHook focusHk;
    focusHk.arg = autoOnboard;
    focusHk.func = FcitxInstanceInputFocus;
    FcitxInstanceRegisterInputFocusHook(instance, focusHk);

    FcitxIMEventHook unfocusHk;
    unfocusHk.arg = autoOnboard;
    unfocusHk.func = FcitxInstanceInputUnFocus;
    FcitxInstanceRegisterInputUnFocusHook(instance, unfocusHk);

    dbus_linkOnboardDbusServer();
    FcitxGlobalConfig *mGlobalConfig = FcitxInstanceGetGlobalConfig(instance);
    // mGlobalConfig->iSwitchKey = 18;//禁用
    mGlobalConfig->_defaultIMState = 1;
    //mGlobalConfig->bIMSwitchIncludeInactive = true;
    // mGlobalConfig->bShowInputWindowTriggering = false;

    FcitxGlobalConfigSave(mGlobalConfig);
    FcitxGlobalConfigLoad(mGlobalConfig);
    return autoOnboard;
}


void FcitxInstanceInputFocus(void* arg)
{
    FcitxLog(WARNING, "FcitxInstanceInputFocus");
    FcitxAutoOnboard* autoOnboard = (FcitxAutoOnboard *)arg;
    autoOnboard->mOnboardRealShow = true;
    dbus_setOnboardVisible(true);
}

void FcitxInstanceInputUnFocus(void* arg)
{
    FcitxLog(WARNING, "FcitxInstanceInputUnFocus");
    FcitxAutoOnboard* autoOnboard = (FcitxAutoOnboard *)arg;

    //bool  onboardRealShow = autoOnboard->mOnboardRealShow;

    dbus_setOnboardVisible(false);
}
