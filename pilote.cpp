#include "pilote.h"
#include <QSqlQuery>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <iostream>
#include <QDate>
using namespace std;


pilote::pilote()
{
   id_pilote="";
    prenom="";
    nom="";
    salaire=0;
    periode=0;
    mdp="";
}
pilote::pilote(QString id_pilote, QString nom,QString prenom, int salaire,int periode,QString mdp)
{
this->id_pilote=id_pilote;
    this->prenom=prenom;
this->nom=nom;
this ->salaire=salaire;
   this ->periode=periode;
    this ->mdp=mdp;

}
bool pilote::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(salaire);
QString res2=QString::number(periode);
    query.prepare("insert into pilote (id_pilote,nom,prenom,salaire,periode,mdp)""values(:id_pilote,:nom,:prenom,:salaire,:periode,:mdp)");
    query.bindValue(":id_pilote", id_pilote);
            query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":salaire", res);
    query.bindValue(":periode", res2);
 query.bindValue(":mdp", mdp);
return query.exec();
}


bool pilote::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from pilote where id_pilote=:id");
query.bindValue(":id",id);
return query.exec();
}
bool pilote::modifier()
{

    QSqlQuery query;
    QString res=QString::number(salaire);
    QString res2=QString::number(periode);

          query.prepare("UPDATE pilote "" SET id_pilote=:id_pilote, nom=:nom, prenom=:prenom, salaire=:salaire, periode=:periode , mdp=:mdp  where id_pilote='"+id_pilote+"' ");


          query.bindValue(":id_pilote", id_pilote);
                  query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":salaire", res);
          query.bindValue(":periode", res2);
          query.bindValue(":mdp", mdp);

        return    query.exec();
}

void pilote::afficher(Ui::MainWindow *ui)
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote");
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifant de pilote"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Salaire"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
     modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
       modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Periode"));

    ui->tableView->setModel(modal);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}





