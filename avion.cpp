#include "avion.h"
#include <QSqlQuery>
#include <iostream>
using namespace std;


avion::avion()
{
    num_piste=0;
    poid=0;
    etat="";
    num_serie="";
}
avion::avion(QString num_serie,int poid, QString etat, int num_piste)
{
this->poid=poid;
this->num_serie=num_serie;
this ->etat=etat;
    this ->num_piste=num_piste;
}
bool avion::ajouter()
{
    QSqlQuery query;

    query.prepare("insert into avion (NUM_SERIE,POIDS_BAGAGE,ETAT,num_piste)""values(:num_serie,:poid,:etat,:num_piste)");
    query.bindValue(":num_serie", num_serie);
    query.bindValue(":poid", poid);
    query.bindValue(":etat", etat);
    query.bindValue(":num_piste", num_piste);

return query.exec();
}


bool avion::supprimer(QString val)
{
QSqlQuery query;
query.prepare("Delete from avion where NUM_SERIE=:num");
query.bindValue(":num",val);
return query.exec();
}
bool avion::modifier(){

    QSqlQuery query;
        QString res=QString::number(num_piste);


          query.prepare("update avion"" set NUM_SERIE=:num_serie, POIDS_BAGAGE=:poid, ETAT=:etat , num_piste=:num_piste where NUM_SERIE='"+num_serie+"' ");


                query.bindValue(":num_piste", res);
                query.bindValue(":poid", poid);
                query.bindValue(":etat", etat);
                    query.bindValue(":num_serie", num_serie);

            return query.exec();

}

QSqlQueryModel * avion::afficher()
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from avion");
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num_avion"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Poids_bagage"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Num_piste"));
return modal;

}





