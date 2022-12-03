#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
#include <QDate>


class pilote
{
    QString id_pilote,nom,prenom,mdp;
    int salaire , periode;
    QDate date;
public:



    pilote();
    pilote(QString,QString,QString, int, int,QString);
    QString getid_pilote(){return id_pilote;}
    QString getmdp(){return mdp;}

    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    int getsalaire(){return salaire;}
    int getperiode(){return periode;}
    void setmdp(QString d){mdp=d;}

    void setid_pilote(QString d){id_pilote=d;}
    void setnom(QString t){nom=t;}
     void setprenom(QString t){prenom=t;}
    void setsalaire(int salaire){this->salaire=salaire;}
     void setperiode(int nbp){this->periode=nbp;}
    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    void afficher(Ui::MainWindow *ui);
void trie(Ui::MainWindow *ui);
};
#endif // VOL_H
