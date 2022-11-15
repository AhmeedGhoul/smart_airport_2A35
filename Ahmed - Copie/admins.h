#ifndef ADMINS_H
#define ADMINS_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
class admins
{

   QString username,pass,action,type;
public:
   admins();
   admins(QString, QString,QString,QString);
   QString getusername(){return username;}
   QString getpass(){return pass;}
   QString getaction(){return action;}
   QString gettype(){return type;}
   void setusername(QString u){username=u;}
   void setpass(QString upass){pass=upass;}
   void setaction(QString uaction){action=uaction;}
   void settype(QString utype){type=utype;}
   QString getid();
   void role(Ui::MainWindow *ui);
   bool ajouter();
   bool supprimer(QString);
   bool modifier();
   void afficher(Ui::MainWindow *ui);
};

#endif // ADMINS_H
