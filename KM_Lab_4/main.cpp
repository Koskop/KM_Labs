#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1900, 900);
    w.setWindowTitle("KM_Lab_4 by Kopelets K. R.");
    w.setFocus();
    w.show();

    return a.exec();
}
