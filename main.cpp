
#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QFontDatabase>
#include <QMessageBox>
#include <QDesktopWidget>
#include <iostream>
#include <QDialog>
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login L;
    connection c;


    bool test=c.createconnection();
    if(test)
    {L.show();


}
    return a.exec();
}
