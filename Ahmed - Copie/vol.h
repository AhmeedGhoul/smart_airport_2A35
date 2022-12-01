#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
#include <QDate>


class vol
{
    QString dest,type,id_pilote,num_serie;
    int nbp,id;
    QDate date;
public:



    vol();
    vol(int,int, QString, QString,QDate, QString, QString);
    QString getdest(){return dest;}
    QString gettype(){return type;}
    int getID(){return id;}
    int getnbp(){return nbp;}
//int statvol(int month);
    void setdest(QString d){dest=d;}
    void settype(QString t){type=t;}
    void setID(int id){this->id=id;}
     void setnbp(int nbp){this->nbp=nbp;}
    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    void afficher(Ui::MainWindow *ui);
void trie(Ui::MainWindow *ui);
void initBrowserView(Ui::MainWindow *ui);
};
#endif // VOL_H
