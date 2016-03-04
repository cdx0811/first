#include "MxMainInterface.h"
#include <QApplication>
#include <QScreen>
#include <QLibrary>
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QObject::connect(&w,SIGNAL(closeEXE()),&a,SLOT(quit()));

    w.show();

    return a.exec();
}
