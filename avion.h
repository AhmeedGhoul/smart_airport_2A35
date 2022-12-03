#ifndef AVION_H
#define AVION_H


#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>


class avion
{
    QString etat,num_serie;
    int num_piste,poid;
public:



    avion();
    avion(QString,int,QString,int);
    int getpoid(){return poid;}
    int getnum_piste(){return num_piste;}
    void setnum_piste(int np){num_piste=np;}
    QString getetat(){return etat;}
    QString getnum(){return num_serie;}
    void setpoid(int n){poid=n;}
    void setetat(QString p){etat=p;}
    void setnum(QString num){this->num_serie=num;}
    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * afficher();
};
#endif // AVION_H
