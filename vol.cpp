#include "vol.h"
#include <QSqlQuery>
#include <iostream>
#include <QDate>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include<QtCharts>
#include <vector>

using namespace std;


vol::vol()
{
    id=0;
    nbp=0;
    type="";
    dest="";
    num_serie="";
    id_pilote="";
}
vol::vol(int id,int nbp, QString type, QString dest,QDate date, QString num_serie, QString id_pilote)
{
this->id=id;
    this->nbp=nbp;
this->dest=dest;
this ->type=type;
   this ->date=date;
    this ->id_pilote=id_pilote;
       this ->num_serie=num_serie;
}
bool vol::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
QString res2=QString::number(nbp);
    query.prepare("insert into vol (id,type,dest,NB_PASSAGERS,datev,NUM_SERIE,ID_PILOTE)""values(:id,:type,:dest,:nbp,:date,:num_serie,:id_pilote)");
    query.bindValue(":id", res);
            query.bindValue(":nbp", res2);
    query.bindValue(":type", type);
    query.bindValue(":dest", dest);
    query.bindValue(":date", date);
    query.bindValue(":num_serie", num_serie);
    query.bindValue(":id_pilote", id_pilote);
return query.exec();
}


bool vol::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from vol where ID=:id");
query.bindValue(":id",id);
return query.exec();
}
bool vol::modifier()
{

    QSqlQuery query;
    QString res=QString::number(id);
    QString res2=QString::number(nbp);

          query.prepare("UPDATE vol "" SET id=:id,type=:type,  dest=:dest, NB_PASSAGERS=:nbp, datev=:date , num_serie=:num_serie, id_pilote=:id_pilote  where ID='"+res+"' ");


          query.bindValue(":id", res);
                  query.bindValue(":nbp", res2);
          query.bindValue(":type", type);
          query.bindValue(":dest", dest);
          query.bindValue(":date", date);
            query.bindValue(":num_serie", num_serie);
            query.bindValue(":id_pilote", id_pilote);
        return    query.exec();
}

QSqlQueryModel * vol::afficher()
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from vol");
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
     modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
       modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
       modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Avion"));
       modal->setHeaderData(6,Qt::Horizontal,QObject::tr("Pilote"));
       return modal;


}






