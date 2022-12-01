#include "pilotee.h"
#include"login.h"
#include"ui_login.h"
#include "historique.h"
#include "ui_pilotee.h"
#include <QSqlQuery>
#include <QTextStream>
#include <QTextDocument>
#include <QDesktopWidget>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
pilotee::pilotee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pilotee)
{
    ui->setupUi(this);

    QSqlQuery qry;
    int action=1;
    QString res=QString::number(action);
ui->label_2->setText("Bienvenue"+getid());
//    qry.prepare("select * from pilote where action='"+res+"' " );


//    if(qry.exec())
//    {
//        while(qry.next())
//        {
//            ui->label_2->setText(qry.value(1).toString());

//        }
//}
//ui->pushButton->clicked();
}
pilotee::~pilotee()
{
    delete ui;
}

void pilotee::on_pushButton_1322_clicked()
{
//    QSqlQuery qry;
//    int action=1;
//    QString res=QString::number(action);

//    qry.prepare("select * from pilote where action='"+res+"' " );
//    if(qry.exec())
//    {
//        while(qry.next())
//        {
//            ui->label_2->setText(qry.value(0).toString());

//        }
//    }
    pilotee p;


    bool test=supprimer(p.getid());
    if (test)
    {

hide();
    }
}
bool pilotee::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from pilote where id_pilote=:id");
query.bindValue(":id",id);
return query.exec();
}
QString pilotee::getid(){
    QSqlQuery qry;
    int action=1;
    QString res1,res=QString::number(action);

    qry.prepare("select * from pilote where action='"+res+"' " );
    if(qry.exec())
    {
        while(qry.next())
        {
            res1=qry.value(0).toString();

        }
    }


    return res1;
}


void pilotee::on_pushButton_disc_clicked()
{
    QSqlQuery query,qry;

    pilotee p;
   QString id=p.getid();
   int action=0;
   QString res=QString::number(action);
   query.prepare("UPDATE pilote "" SET action=:action  where id_pilote='"+id+"' ");
     query.bindValue(":action",res);
     query.exec();
     historique h(id,"disconnecter ",QDateTime::currentDateTime());
     qry.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
     qry.bindValue(":USERNAME", h.getuser());
     qry.bindValue(":ACTION", h.getaction());
     qry.bindValue(":DATEH", h.getdateh());
     qry.exec();
     hide();

}

void pilotee::on_pushButton_clicked()
{
    pilotee p;
   QString id=p.getid();

    hismp1.afficherpilo(ui,id);

}

void pilotee::on_pushButton_pdfhistorique_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_4->model()->rowCount();
    const int columnCount = ui->tableView_4->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("col1")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_4->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_4->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_4->isColumnHidden(column)) {
                QString data = ui->tableView_4->model()->data(ui->tableView_4->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

        document->print(&printer);


    delete document;
}

void pilotee::on_comboBox_trihistorique_currentTextChanged(const QString &arg1)
{
    pilotee p;
   QString id=p.getid();

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString type="hfq";//ui->comboBox_trihistorique->currentText();
    if (type=="Par defaut"){
        qry->prepare("select * from historique where username=:id");
        qry->bindValue(":id",id);

        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
        modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
         modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

        ui->tableView_4->setModel(modal);}
        else if (type=="User"){
            qry->prepare("select * from historique where username=:id order by username");
            qry->bindValue(":id",id);

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
             modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

            ui->tableView_4->setModel(modal);


        }
        else if (type=="Date"){
            qry->prepare("select * from historique where username=:id order by dateh");
            qry->bindValue(":id",id);

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
             modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

            ui->tableView_4->setModel(modal);


        }
}
bool pilotee::modifier(QString id,QString nom,QString prenom,QString mdp)
{

    QSqlQuery query;


          query.prepare("UPDATE pilote "" SET id_pilote=:id_pilote, nom=:nom, prenom=:prenom, mdp=:mdp  where id_pilote='"+id+"' ");


          query.bindValue(":id_pilote", id);
                  query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":mdp", mdp);

        return    query.exec();
}
