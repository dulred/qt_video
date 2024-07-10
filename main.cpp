#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //使用第三方字库，用来作为UI图片 ://res/fa-solid-900.ttf
    QFontDatabase::addApplicationFont("://res/fontawesome-webfont.ttf");
    //QFontDatabase::addApplicationFont("://res/fa-solid-900.ttf");

    MainWindow w;
    if (w.Init() == false)
    {
        return -1;
    }
    w.show();
    return a.exec();
}
