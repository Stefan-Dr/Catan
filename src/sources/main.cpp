#include "../headers/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::cerr<<"Looking for bugs\n";

    return a.exec();
}
