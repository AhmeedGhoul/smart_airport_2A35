#include "passager.h"
#include <QSqlQuery>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <iostream>
#include <QDate>
using namespace std;


passager::passager()
{
    num_pass="";
    age=0;
    prenom="";
    nom="";
    num_serie="";
}
passager::passager(QString num_pass,QString nom,QString prenom,int age,QDate dateexp, QString num_serie)
{
this->num_pass=num_pass;
    this->age=age;
this->nom=nom;
this ->prenom=prenom;
   this ->dateexp=dateexp;
    this ->num_serie=num_serie;
}
bool passager::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(age);
    query.prepare("insert into passager (num_pass,nom,prenom,age,DATE_EXPR,num_serie)""values(:num_pass,:nom,:prenom,:age,:dateexp,:num_serie)");
            query.bindValue(":num_pass", num_pass);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    query.bindValue(":age", res);
    query.bindValue(":dateexp", dateexp);
    query.bindValue(":num_serie", num_serie);
return query.exec();
}


bool passager::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from passager where num_pass=:id");
query.bindValue(":id",id);
return query.exec();
}
bool passager::modifier()
{

    QSqlQuery query;
    QString res=QString::number(age);

          query.prepare("UPDATE passager "" SET num_pass=:num_pass, nom=:nom, prenom=:prenom, age=:age, DATE_EXPR=:dateexp,num_serie=:num_serie where num_pass='"+num_pass+"' ");
          query.bindValue(":num_pass", num_pass);
  query.bindValue(":nom", nom);
  query.bindValue(":prenom", prenom);

  query.bindValue(":age", res);
  query.bindValue(":dateexp", dateexp);
  query.bindValue(":num_serie", num_serie);
        return    query.exec();
}

QSqlQueryModel * passager::afficher()
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from passager");
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de passport"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
     modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
       modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de exp"));
       modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Num d'avion"));
       return modal;

}





