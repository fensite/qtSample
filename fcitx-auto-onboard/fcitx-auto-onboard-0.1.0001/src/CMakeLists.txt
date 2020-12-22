PKG_CHECK_MODULES(DBUS "dbus-1>=1.1.0" )

include_directories(${DBUS_INCLUDE_DIRS})
link_directories(${DBUS_LIBRARY_DIRS})

set(FCITX_AUTO_ONBOARD_SOURCES
  auto-onboard.c)

fcitx_add_addon_full(auto-onboard
  SOURCES ${FCITX_AUTO_ONBOARD_SOURCES})

