#ifndef ADMINS_H
#define ADMINS_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
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
   int role();
   bool ajouter();
   bool supprimer(QString);
   bool modifier();
   QSqlQueryModel * afficher();
};

#endif // ADMINS_H
