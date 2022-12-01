#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
#include <QDate>


class reservation
{
    QString num_reser,Num_pass,id,classe;
    int prix;
public:



    reservation();
    reservation(QString, QString, QString, QString,int );
    QString getnum_reser(){return num_reser;}
    QString getNUM_PASS(){return Num_pass;}
    QString getID(){return id;}
    QString getCLASSE(){return classe;}
int getPRIX(){return prix;}
    void setnum_reser(QString d){num_reser=d;}
    void setNum_pass(QString t){Num_pass=t;}
    void setID(QString id){this->id=id;}
    void setclasse(QString classe){this->classe=classe;}

     void setprix(int prix){this->prix=prix;}
    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    void afficher(Ui::MainWindow *ui);
void trie(Ui::MainWindow *ui);
};
#endif // VOL_H
