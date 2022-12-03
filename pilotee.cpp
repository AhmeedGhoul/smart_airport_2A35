#include "pilotee.h"
#include <QGraphicsDropShadowEffect>
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
//pilotee p;
    QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect;
    effect2->setBlurRadius(20);
    effect2->setXOffset(2);
    effect2->setYOffset(2);
    effect2->setColor(Qt::lightGray);
    ui->frame->setGraphicsEffect(effect2);
    QGraphicsDropShadowEffect *effect3 = new QGraphicsDropShadowEffect;
    effect3->setBlurRadius(20);
    effect3->setXOffset(2);
    effect3->setYOffset(2);
    effect3->setColor(Qt::lightGray);
    QGraphicsDropShadowEffect *effect1 = new QGraphicsDropShadowEffect;
    effect1->setBlurRadius(20);
    effect1->setXOffset(2);
    effect1->setYOffset(2);
    effect1->setColor(Qt::lightGray);
    ui->frame_2->setGraphicsEffect(effect1);
    ui->frame_historique->setGraphicsEffect(effect3);
    QSqlQuery qry;
    int action=1;
    QString res=QString::number(action);
ui->label_2->setText("Bienvenue "+getid());
   qry.prepare("select * from pilote where id_pilote='"+getid()+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_idpilotee->setText(qry.value(0).toString());
            ui->lineEdit_nompilotee->setText(qry.value(1).toString());
            ui->lineEdit_prenompilotee->setText(qry.value(2).toString());

            ui->lineEdit_salairepilotee->setText(qry.value(3).toString());
            ui->lineEdit_periodepilotee->setText(qry.value(4).toString());


        }
}
    choix_bar();
afficherchatboxx();
afficher(getid());
ui->tableView_4->setModel(hismp1.afficherpilo(getid()));

ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

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
     qApp->quit();

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
    QString type=ui->comboBox_trihistorique->currentText();
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






void pilotee::on_pushButton_modpilotee_clicked()
{

    QString id1=ui->lineEdit_idpilotee->text();
    QString nom1=ui->lineEdit_nompilotee->text();
    QString prenom1=ui->lineEdit_prenompilotee->text();
    QString md1p=ui->lineEdit_mdppilotee->text();
    int salaire1=ui->lineEdit_salairepilotee->text().toInt();
    int periode1=ui->lineEdit_periodepilotee->text().toInt();
    bool test=modifier(id1,nom1,prenom1,salaire1,periode1,md1p);
if(test){
QSqlQuery query;

       historique h(id1,"modifier son profile de id : "+id1,QDateTime::currentDateTime());
query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
query.bindValue(":USERNAME", h.getuser());
query.bindValue(":ACTION", h.getaction());
query.bindValue(":DATEH", h.getdateh());
// query.bindValue(":num_serie", num_serie);
//query.bindValue(":id_pilote", id_pilote);
query.exec();}
ui->lineEdit_mdppilotee->clear();
}
bool modifier(QString id,QString nom,QString prenom,int salaire,int periode,QString mdp)
{

    QSqlQuery query;
    QString res=QString::number(salaire);
        QString res2=QString::number(periode);

    query.prepare("UPDATE pilote "" SET id_pilote=:id_pilote, nom=:nom, prenom=:prenom, salaire=:salaire, periode=:periode , mdp=:mdp  where id_pilote='"+id+"' ");


          query.bindValue(":id_pilote", id);
                  query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":mdp", mdp);
          query.bindValue(":salaire", res);
                   query.bindValue(":periode", res2);


        return    query.exec();
}
void pilotee::closeEvent (QCloseEvent *event)
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
void pilotee::afficher(QString id_pilote)
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    qry->prepare("select * from vol where ID_PILOTE=:id");
    qry->bindValue(":id",id_pilote);

    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
     modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
       modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
       modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Avion"));
       modal->setHeaderData(6,Qt::Horizontal,QObject::tr("Pilote"));
    ui->tableView->setModel(modal);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}



void pilotee::on_pushButton_pdfvolpilotee_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

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
        if (!ui->tableView->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView->isColumnHidden(column)) {
                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void pilotee::on_comboBox_trivolpilotee_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString type=ui->comboBox_trivolpilotee->currentText();
    if (type=="Par defaut"){
        qry->prepare("select id,type,dest,nb_passagers,datev,num_avion from vol where ID_PILOTE=:id ");
        qry->bindValue(":id",getid());

        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
                      modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
                      modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Avion"));

        ui->tableView->setModel(modal);}
        else if (type=="Identifiant"){
            qry->prepare("select id,type,dest,nb_passagers,datev,num_avion from vol where ID_PILOTE=:id  order by id");
            qry->bindValue(":id",getid());

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
             modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
             modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Avion"));


            ui->tableView->setModel(modal);


        }
        else if (type=="Destination"){
            qry->prepare("select id,type,dest,nb_passagers,datev,num_avion from vol where ID_PILOTE=:id order by dest");
            qry->bindValue(":id",getid());

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
             modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
             modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Avion"));

            ui->tableView->setModel(modal);


        }
        else if (type=="Nb de passagers"){
            qry->prepare("select id,type,dest,nb_passagers,datev,num_avion from vol where ID_PILOTE=:id order by NB_PASSAGERS");
            qry->bindValue(":id",getid());

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
             modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
             modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Avion"));

            ui->tableView->setModel(modal);


        }
    else if (type=="Avion"){
        qry->prepare("select id,type,dest,nb_passagers,datev,num_avion from vol where ID_PILOTE=:id order by num_seriee");
        qry->bindValue(":id",getid());

        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
         modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
         modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Avion"));

        ui->tableView->setModel(modal);


    }

}
void pilotee::choix_bar()
{
QSqlQuery q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12;
int count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0,count11=0;
QString r=getid();
q1.prepare("select count(*) from vol where id_pilote='"+r+"' and extract(month from datev)='"+QString::number(12)+"') ");
q1.exec();

q2.prepare("select count(*) from vol where (id_pilote='"+r+"' and extract(month from datev)='"+QString::number(1)+"')");
q2.exec();

q3.prepare("select count(*) from vol  where (id_pilote='"+r+"' and extract(month from datev)='"+QString::number(2)+"')");

q3.exec();

q4.prepare("select count(*) FROM vol where (id_pilote='"+r+"' and extract(month from datev)='"+QString::number(3)+"')");
q4.exec();

q5.prepare("select count(*) from vol where (id_pilote='"+r+"' and extract(month from datev)='"+QString::number(4)+"')");
q5.exec();

q6.prepare("select count(*) from vol  where (id_pilote='"+r+"' and extract(month from datev)='"+QString::number(5)+"')");

q6.exec();

q7.prepare("select count(*) FROM vol where (id_pilote='"+r+"' and extract(month from datev)='"+QString::number(6)+"')");

q7.exec();

q8.prepare("select count(*) from vol where (id_pilote='"+r+"' andextract(month from datev)='"+QString::number(7)+"')");
q8.exec();

q9.prepare("select count(*) from vol  where (id_pilote='"+r+"' and extract(month from datev)='"+QString::number(8)+"')");

q9.exec();

q10.prepare("select count(*) FROM vol where (id_pilote='"+r+"' and extract(month from datev)='"+QString::number(9)+"')");
q10.exec();

q11.prepare("select count(*) from vol where (id_pilote='"+r+"' and extract(month from datev)='"+QString::number(10)+"')");
q11.exec();

q12.prepare("select count(*) from vol  where (id_pilote='"+r+"' and extract(month from datev)='"+QString::number(11)+"')");

q12.exec();

while(q1.next())
    {

    count0=q1.value(0).toString().toInt() ;
    }
while(q2.next())
    {

    count1=q2.value(0).toString().toInt() ;
    }
while(q3.next())
    {

    count2=q3.value(0).toString().toInt() ;
    }
while(q4.next())
    {

    count3=q4.value(0).toString().toInt() ;
    }
while(q5.next())
    {

    count4=q5.value(0).toString().toInt() ;
    }
while(q6.next())
    {

    count5=q6.value(0).toString().toInt() ;
    }
while(q7.next())
    {

    count6=q7.value(0).toString().toInt() ;
    }
while(q8.next())
    {

    count7=q8.value(0).toString().toInt() ;
    }
while(q9.next())
    {

    count8=q9.value(0).toString().toInt() ;
    }
while(q10.next())
    {

    count9=q10.value(0).toString().toInt() ;
    }
while(q11.next())
    {

    count10=q11.value(0).toString().toInt() ;
    }
while(q12.next())
    {

    count11=q12.value(0).toString().toInt() ;
    }

        QBarSet *set0 = new QBarSet("Jan");
        *set0 << count1<< count2<< count3<< count4<< count5<< count6<< count7<< count8<< count9<< count10<< count11<< count0;
      QBarSeries *series = new QBarSeries();
        series->append(set0);
       QChart *chart = new QChart();
        chart->addSeries(series);
chart->setTitle("Vol par mois");
QStringList cataloge;
cataloge<<"Jan"<<"Fev"<<"Mar"<<"Avr"<<"May"<<"Jui"<<"Juil"<<"Aou"<<"Sep"<<"Oct"<<"Nov"<<"Dec";
chart->setAnimationOptions(QChart::AllAnimations);
 QValueAxis *axisY = new QValueAxis();
axisY->setRange(0,10);
chart->setAxisY(axisY,series);
QBarCategoryAxis *axisX = new QBarCategoryAxis();
axisX->append(cataloge);
chart->createDefaultAxes();
chart->legend()->hide();

chart->setAxisX(axisX,series);
        QPalette pal = qApp->palette();
        pal.setColor(QPalette::Window, QRgb(0xffffff));
       pal.setColor(QPalette::WindowText, QRgb(0x404044));
       qApp->setPalette(pal);
chartView = new QChartView(chart,ui->chartview);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(551,321);

chartView->show();
}
void pilotee::afficherchatboxx()
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    qry->prepare("select id_pilote from pilote ");


    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Les pilotes"));
    ui->tableView_2->setModel(modal);

    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void pilotee::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    pilotee p;
    QString val=ui->tableView_2->model()->data(index).toString();
ui->receiver->setText(val);
ui->plainTextEdit->setPlainText("");
QString q=affichermsg(val);
ui->plainTextEdit->appendPlainText(q);

}

void pilotee::on_pushButton_2_clicked()
{
    pilotee p;

    QString msg=ui->plainTextEdit_2->toPlainText();
    QString receiver=ui->receiver->text();
    QString id=getid();
    QSqlQuery query,qry;

    qry.prepare("insert into chatbox (SENDER,MSG,RECEIVER,DATEC)""values(:SENDER,:MSG,:RECEIVER,:DATEC)");
     qry.bindValue(":SENDER",id );
     qry.bindValue(":MSG", msg);
       qry.bindValue(":RECEIVER", receiver);
     qry.bindValue(":DATEC", QDate::currentDate());
     qry.exec();
     ui->plainTextEdit_2->setPlainText("");
QString q;
q=affichermsg(receiver);
ui->plainTextEdit->appendPlainText(q);
}
QString affichermsg(QString RECEIVER)
{
pilotee p;
    QSqlQuery*qry=new QSqlQuery();
    qry->prepare("select SENDER,MSG,RECEIVER,datec from chatbox where (RECEIVER='"+p.getid()+"' or RECEIVER='"+RECEIVER+"') and (SENDER='"+RECEIVER+"' or SENDER='"+p.getid()+"')  ");
//    qry->bindValue(":id",RECEIVER);
//    qry->bindValue(":idd",p.getid());
QString q ,h;
    //qry->exec();
    if(qry->exec())
    {
        while(qry->next())
        {
            h=q;
           q=h+"\n"+qry->value(0).toString()+":"+qry->value(1).toString()+"      "+qry->value(3).toString();
        }
}
    return q;
}
