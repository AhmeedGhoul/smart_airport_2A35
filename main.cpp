
#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QFontDatabase>
#include <QMessageBox>
#include <QDesktopWidget>
#include <iostream>
#include <QDialog>
#include "login.h"
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login L;
    connection c;
QTranslator T;
QStringList languages;
      languages <<"French"<<"English";
      const QString lang=QInputDialog::getItem(NULL,"Select language ","Language",languages);
      if (lang=="English")

    {
         T.load(":/translate/english.qm");
    }
    if (lang !="French")
    {
        a.installTranslator(&T);
    }
    L.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    bool test=c.createconnection();
    if(test)

    {L.show();


}
    else qDebug()<<"pas possible";
    return a.exec();
}
