#ifndef PISTE_H
#define PISTE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDate>


class piste
{
    int Num_piste;
    int prix_piste;
    int largeurpiste;
public:



    piste();
    piste(int,int,int);
    //Gett
    int getNum_piste();
    int getprix_piste();
    int getLlargeurpiste();

    //Sett
    void setNum_piste(int);
    void setprix_piste(int);
    void setlargeurpiste(int);
    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * afficher();
};
#endif // PISTE_H
