#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDate>


class passager
{
    QString num_pass,nom,prenom,num_serie;
    int age;
    QDate dateexp;
public:



    passager();
    passager(QString,QString, QString,int,QDate, QString);
    QString getnum_pass(){return num_pass;}
    QString getnum_serie(){return num_serie;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QDate getdateexp(){return dateexp;}
    int getage(){return age;}
    void setnum_pass(QString d){num_pass=d;}
    void setnum_serie(QString t){num_serie=t;}
    void setnom(QString nom){this->nom=nom;}
    void setprenom(QString nom){this->prenom=nom;}
     void setage(int nbp){this->age=nbp;}
     void setdateexp(QDate nbp){this->dateexp=nbp;}

    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * afficher();
};
#endif // VOL_H
