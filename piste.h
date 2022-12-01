#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
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
    void afficher(Ui::MainWindow *ui);
void trie(Ui::MainWindow *ui);
};
#endif // VOL_H
