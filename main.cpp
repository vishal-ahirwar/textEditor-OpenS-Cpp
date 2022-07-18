#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window(std::string("OpenS Text Editor"));
    window.show();
    return a.exec();
}
