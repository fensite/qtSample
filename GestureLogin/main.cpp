#include "qwhgesturelogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWHGestureLogin w;
    w.show();
    return a.exec();
}
