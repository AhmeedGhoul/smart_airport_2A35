#include "reservation.h"
#include <QSqlQuery>
#include <iostream>
#include <QDate>
#include "qrcode.h"

using namespace std;


reservation::reservation()
{
    num_reser="";
    id=0;
    Num_pass="";
    classe="";
prix=0;
}
reservation::reservation(QString num_reser, int id, QString Num_pass, QString classe,int prix)
{
this->num_reser=num_reser;
    this->id=id;
this->Num_pass=Num_pass;
this ->classe=classe;
   this ->prix=prix;


}
bool reservation::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(prix);
    QString res1=QString::number(id);

    query.prepare("insert into reservation (NUM_RESER,NUM_PASS,ID,CLASSE,PRIX)""values(:NUM_RESER,:NUM_PASS,:ID,:CLASSE,:PRIX)");
    query.bindValue(":NUM_RESER", num_reser);
            query.bindValue(":NUM_PASS", Num_pass);
    query.bindValue(":ID", res1);
    query.bindValue(":CLASSE", classe);
    query.bindValue(":PRIX", res);

return query.exec();
}


bool reservation::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from reservation where NUM_RESER=:id");
query.bindValue(":id",id);
return query.exec();
}
bool reservation::modifier()
{

    QSqlQuery query;
    QString res=QString::number(prix);

          query.prepare("UPDATE reservation "" SET NUM_RESER=:NUM_RESER, NUM_PASS=:NUM_PASS, ID=:ID, CLASSE=:CLASSE, PRIX=:PRIX where NUM_RESER='"+num_reser+"' ");


          query.bindValue(":NUM_RESER", num_reser);
                  query.bindValue(":NUM_PASS", Num_pass);
          query.bindValue(":ID", id);
          query.bindValue(":CLASSE", classe);
          query.bindValue(":PRIX", res);

        return    query.exec();
}

QSqlQueryModel * reservation::afficher()
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from reservation");
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de reservation"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Num de passport"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("ID vol"));
     modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Classe"));
       modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));

       return modal;


}



