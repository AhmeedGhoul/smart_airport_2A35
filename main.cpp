
#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QFontDatabase>
#include <QMessageBox>
#include <QDesktopWidget>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;


    bool test=c.createconnection();
    if(test)
    {w.show();


}
    return a.exec();
}
