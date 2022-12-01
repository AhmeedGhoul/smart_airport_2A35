#include "admins.h"
#include <QSqlQuery>
#include "ui_mainwindow.h"
#include "mainwindow.h"
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
void admins::role(Ui::MainWindow *ui){
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

    ui->pushButton_15->hide();
    ui->pushButton_11->hide();
    ui->pushButton_16->hide();
    ui->pushButton_13->hide();
    ui->pushButton_12->hide();
    ui->pushButton_14->setGeometry(-55,209,308,100);
    ui->pushButton_17->setGeometry(-109,307,362,100);
ui->line->hide();
ui->line_3->hide();
ui->line_4->hide();
ui->line_5->hide();
ui->line_8->hide();
ui->pushButton_supphistorique->hide();


}
if(res1=="Agent de vente"){

    ui->pushButton_15->hide();
    ui->pushButton_14->hide();
    ui->pushButton_16->hide();
    ui->pushButton_13->hide();
    ui->pushButton_12->hide();
    ui->pushButton_17->setGeometry(-109,308,362,100);
    ui->line->hide();
    ui->line_3->hide();
    ui->line_4->hide();
    ui->line_5->hide();
    ui->line_8->hide();
    ui->pushButton_supphistorique->hide();

}
if(res1=="Agent d'avion"){

    ui->pushButton_15->hide();
    ui->pushButton_11->hide();
    ui->pushButton_16->hide();
    ui->pushButton_13->hide();
    ui->pushButton_14->hide();
    ui->pushButton_12->setGeometry(-50,209,303,100);
    ui->pushButton_17->setGeometry(-109,308,362,100);
    ui->line->hide();
    ui->line_3->hide();
    ui->line_4->hide();
    ui->line_5->hide();
    ui->line_8->hide();
    ui->pushButton_supphistorique->hide();

}
if(res1=="Agent de passager"){

    ui->pushButton_14->hide();
    ui->pushButton_11->hide();
    ui->pushButton_16->hide();
    ui->pushButton_13->hide();
    ui->pushButton_12->hide();
    ui->pushButton_15->setGeometry(-10,209,263,100);
    ui->pushButton_17->setGeometry(-109,308,362,100);
    ui->line->hide();
    ui->line_3->hide();
    ui->line_4->hide();
    ui->line_5->hide();
    ui->line_8->hide();
    ui->pushButton_supphistorique->hide();
}
if(res1=="Agent de pilote"){

    ui->pushButton_14->hide();
    ui->pushButton_11->hide();
    ui->pushButton_15->hide();
    ui->pushButton_13->hide();
    ui->pushButton_12->hide();
    ui->pushButton_16->setGeometry(-60,209,313,100);
    ui->pushButton_17->setGeometry(-109,308,362,100);
    ui->line->hide();
    ui->line_3->hide();
    ui->line_4->hide();
    ui->line_5->hide();
    ui->line_8->hide();
    ui->pushButton_supphistorique->hide();

}
}
