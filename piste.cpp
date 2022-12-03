#include "piste.h"
#include <QSqlQuery>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <iostream>
#include <QDate>
using namespace std;


piste::piste()
{
 Num_piste=0;
 prix_piste=0;
 largeurpiste=0;
}
piste::piste(int Num_piste,int prix_piste,int largeurpiste)
{

this->Num_piste=Num_piste;
this->prix_piste=prix_piste;
this->largeurpiste=largeurpiste;

}
bool piste::ajouter()
{
    QSqlQuery query;
    QString test=QString::number(Num_piste);
    QString test2=QString::number(prix_piste);
    QString test3=QString::number(largeurpiste);
        query.prepare(  "insert into piste (NUM_PISTE,PRIX_LOCATION,LARGEUR_PISTE )" "values(:num_piste,:prix_piste,:largeurpiste)");
        query.bindValue(":num_piste",test);
        query.bindValue(":largeurpiste", test3);
       query.bindValue(":prix_piste", test2);
return query.exec();
}


bool piste::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from piste where num_piste=:id");
query.bindValue(":id",id);
return query.exec();
}
bool piste::modifier()
{

    QSqlQuery query;
           QString test1=QString::number(Num_piste);
           QString test2=QString::number(prix_piste);
           QString test3=QString::number(largeurpiste);

             query.prepare("UPDATE piste "" SET NUM_PISTE=:num_piste, PRIX_LOCATION=:prix, LARGEUR_PISTE=:largeur where NUM_PISTE='"+test1+"' ");


                   query.bindValue(":num_piste", test1);
                   query.bindValue(":prix", test2);
                   query.bindValue(":largeur", test3);
        return    query.exec();
}

QSqlQueryModel * piste::afficher()
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from piste");
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de piste"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Largeur de piste"));
     modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Prix de location"));
     return modal;


}





