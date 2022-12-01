#include "historique.h"
#include "ui_mainwindow.h"
#include "ui_pilotee.h"
#include <QSqlQuery>

historique::historique()
{
     user="";action="";
}
historique::historique(QString user,QString action,QDateTime date){
    this->user=user;
    this->dateh=date;
    this->action=action;

}
void historique::afficher(Ui::MainWindow *ui)
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from historique");
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
     modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

    ui->tableView_4->setModel(modal);

    ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
bool historique::supprimer(QDateTime d)
{
QSqlQuery query;

query.prepare("Delete from historique where dateh=:id");
query.bindValue(":id",d);
return query.exec();
}
void historique::afficherpilo(Ui::pilotee *ui,QString id_pilote)
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from historique where username=:name");
    qry->bindValue(":name",id_pilote);

    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
     modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

    ui->tableView_4->setModel(modal);

    ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
void historique::afficheradmin(Ui::MainWindow *ui,QString admin)
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from historique where username=:name");
    qry->bindValue(":name",admin);

    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
     modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

    ui->tableView_4->setModel(modal);

    ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
