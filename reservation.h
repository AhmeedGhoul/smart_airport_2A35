#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDate>


class reservation
{
    QString num_reser,Num_pass,classe;
    int prix,id;
public:



    reservation();
    reservation(QString,int, QString , QString,int);
    QString getnum_reser(){return num_reser;}
    QString getNUM_PASS(){return Num_pass;}
    int getID(){return id;}
    QString getCLASSE(){return classe;}
int getPRIX(){return prix;}


    void setnum_reser(QString d){num_reser=d;}
    void setNum_pass(QString t){Num_pass=t;}
    void setID(int id){this->id=id;}
    void setclasse(QString classe){this->classe=classe;}

     void setprix(int prix){this->prix=prix;}
     ///calendrier
    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * afficher();
};

#endif // RESERVATION_H
