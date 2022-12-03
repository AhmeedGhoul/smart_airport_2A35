#include "admins.h"
#include <QSqlQuery>
admins::admins()
{
username="";
pass="";
type="";
action="";
}
admins::admins(QString u ,QString p,QString t,QString a)
{
username=u;
pass=p;
type=t;
action=a;
}
QString admins::getid(){
    QSqlQuery qry;
    int action=1;
    QString res1,res=QString::number(action);

    qry.prepare("select * from admins where action='"+res+"' " );
    if(qry.exec())
    {
        while(qry.next())
        {
            res1=qry.value(0).toString();

        }
    }


    return res1;
}
int admins::role(){
                  QString res1,r=getid();
                  QSqlQuery qry;
                  qry.prepare("select * from admins where username='"+r+"' " );
                  if(qry.exec())
                  {
                      while(qry.next())
                      {
                          res1=qry.value(2).toString();

                      }
                  }
if(res1=="Agent de piste"){
return 0;
//    ui->pushButton_15->hide();
//    ui->pushButton_11->hide();
//    ui->pushButton_16->hide();
//    ui->pushButton_13->hide();
//    ui->pushButton_12->hide();
//    ui->pushButton_14->setGeometry(-55,209,308,100);
//    ui->pushButton_17->setGeometry(-109,307,362,100);
//ui->line->hide();
//ui->line_3->hide();
//ui->line_4->hide();
//ui->line_5->hide();
//ui->line_8->hide();
//ui->pushButton_supphistorique->hide();
//ui->frame_5->hide();


}
if(res1=="Agent de vente"){
    return 1;

//    ui->pushButton_15->hide();
//    ui->pushButton_14->hide();
//    ui->pushButton_16->hide();
//    ui->pushButton_13->hide();
//    ui->pushButton_12->hide();
//    ui->pushButton_17->setGeometry(-109,308,362,100);
//    ui->line->hide();
//    ui->line_3->hide();
//    ui->line_4->hide();
//    ui->line_5->hide();
//    ui->line_8->hide();
//    ui->pushButton_supphistorique->hide();
//    ui->frame_5->hide();

}
if(res1=="Agent d'avion"){
    return 2;

//    ui->pushButton_15->hide();
//    ui->pushButton_11->hide();
//    ui->pushButton_16->hide();
//    ui->pushButton_13->hide();
//    ui->pushButton_14->hide();
//    ui->pushButton_12->setGeometry(-50,209,303,100);
//    ui->pushButton_17->setGeometry(-109,308,362,100);
//    ui->line->hide();
//    ui->line_3->hide();
//    ui->line_4->hide();
//    ui->line_5->hide();
//    ui->line_8->hide();
//    ui->pushButton_supphistorique->hide();
//    ui->frame_5->hide();

}
if(res1=="Agent de passager"){
    return 3;

//    ui->pushButton_14->hide();
//    ui->pushButton_11->hide();
//    ui->pushButton_16->hide();
//    ui->pushButton_13->hide();
//    ui->pushButton_12->hide();
//    ui->pushButton_15->setGeometry(-10,209,263,100);
//    ui->pushButton_17->setGeometry(-109,308,362,100);
//    ui->line->hide();
//    ui->line_3->hide();
//    ui->line_4->hide();
//    ui->line_5->hide();
//    ui->line_8->hide();
//    ui->pushButton_supphistorique->hide();
//    ui->frame_5->hide();

}
if(res1=="Agent de pilote"){
    return 4;

//    ui->pushButton_14->hide();
//    ui->pushButton_11->hide();
//    ui->pushButton_15->hide();
//    ui->pushButton_13->hide();
//    ui->pushButton_12->hide();
//    ui->pushButton_16->setGeometry(-60,209,313,100);
//    ui->pushButton_17->setGeometry(-109,308,362,100);
//    ui->line->hide();
//    ui->line_3->hide();
//    ui->line_4->hide();
//    ui->line_5->hide();
//    ui->line_8->hide();
//    ui->pushButton_supphistorique->hide();
//    ui->frame_5->hide();

}
if(res1=="Agent de vol"){
    return 5;

//    ui->pushButton_14->hide();
//    ui->pushButton_11->hide();
//    ui->pushButton_15->hide();
//    ui->pushButton_13->hide();
//    ui->pushButton_12->hide();
//    ui->pushButton_16->setGeometry(-60,209,313,100);
//    ui->pushButton_17->setGeometry(-109,308,362,100);
//    ui->line->hide();
//    ui->line_3->hide();
//    ui->line_4->hide();
//    ui->line_5->hide();
//    ui->line_8->hide();
//    ui->pushButton_supphistorique->hide();
//    ui->frame_5->hide();

}
else
    return -1;
}
bool admins::ajouter()
{
    QSqlQuery query;
    query.prepare("insert into admins (USERNAME,PASSWORD,type,ACTION)""values(:USERNAME,:PASSWORD,:type,:ACTION)");
    query.bindValue(":USERNAME", username);
    query.bindValue(":PASSWORD", pass);
    query.bindValue(":type", type);
    query.bindValue(":ACTION", action);
return query.exec();
}


bool admins::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from admins where USERNAME=:USERNAME");
query.bindValue(":USERNAME",id);
return query.exec();
}
bool admins::modifier()
{

    QSqlQuery query;

          query.prepare("UPDATE admins "" SET USERNAME=:USERNAME,PASSWORD=:PASSWORD,type=:type where USERNAME='"+username+"' ");

          query.bindValue(":USERNAME", username);
          query.bindValue(":PASSWORD", pass);
          query.bindValue(":type", type);

        return    query.exec();
}

  QSqlQueryModel * admins::afficher()
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select USERNAME,PASSWORD,type from admins");
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Username"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Password"));
     modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
return modal;

}
