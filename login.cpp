#include "login.h"
#include "ui_login.h"
#include <QIcon>
#include "mainwindow.h"
#include <QSqlQuery>
#include "historique.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}
Login::Login(QString user,QString pass){
    username=user;
    password=pass;


}


void Login::on_pushButton_conn_clicked()
{
    QString user = ui->lineEdit_usernamee->text();
    QString pass = ui->lineEdit_passwordd->text();
    Login L(user,pass);
    if (L.auth()){
               hide();
       pilote = new pilotee(this);
       pilote->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

   pilote ->show();
        }
   if (L.auth1()){
       hide();
         mainwindow = new MainWindow(this);
         mainwindow->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

       mainwindow ->show();}
}
bool Login::auth(){
        bool test = false;
        QSqlQuery query,qry;
        query.prepare("select * from pilote where id_pilote=:email");
        query.bindValue(":email",username);
        if(query.exec()){
            query.next();
            if(query.value(5).toString() == password){
                 test = true;
                 int action=1;
                 QString res=QString::number(action);
                 query.prepare("UPDATE pilote "" SET action=:action  where id_pilote='"+username+"' ");


                   query.bindValue(":action",res);
                   query.exec();
                   historique h(username,"connecter ",QDateTime::currentDateTime());
                   qry.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
                   qry.bindValue(":USERNAME", h.getuser());
                   qry.bindValue(":ACTION", h.getaction());
                   qry.bindValue(":DATEH", h.getdateh());
                   qry.exec();

            }else {
                 test = false;

            }
        }else {
            test = false;
      }

        return test;
    }


bool Login::auth1(){
    bool test = false;
    QSqlQuery query1,qry;
    printf("possible");
query1.prepare("select * from admins where username=:email");
query1.bindValue(":email",username);
if(query1.exec()){
    query1.next();
    if(query1.value(1).toString() == password){
         test = 2;
         int action=1;
         QString res=QString::number(action);
         query1.prepare("UPDATE admins "" SET action=:action  where username='"+username+"' ");
           query1.bindValue(":action",res);
           query1.exec();
           historique h(username,"connecter ",QDateTime::currentDateTime());
           qry.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
           qry.bindValue(":USERNAME", h.getuser());
           qry.bindValue(":ACTION", h.getaction());
           qry.bindValue(":DATEH", h.getdateh());
           qry.exec();

    }else {
         test = 0;

    }
}else {
    test = 0;
}
return test;

}






