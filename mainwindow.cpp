#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vol.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTextStream>
#include <QTextDocument>
#include <QDesktopWidget>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <iostream>
#include <QMediaPlayer>
#include <QUrl>
#include <QVideoWidget>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSeries>
#include <QPieSlice>
#include "historique.h"
#include <QDateTime>
#include "admins.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int okey=0;
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(20);
    effect->setXOffset(2);
    effect->setYOffset(2);
    effect->setColor(Qt::lightGray);
    ui->frame->setGraphicsEffect(effect);
    QGraphicsDropShadowEffect *effect1 = new QGraphicsDropShadowEffect;
    effect1->setBlurRadius(20);
    effect1->setXOffset(2);
    effect1->setYOffset(2);
    effect1->setColor(Qt::lightGray);
    ui->frame_2->setGraphicsEffect(effect1);
    ui->frame_2->hide();
    ui->frame->hide();
    ui->frame_historique->hide();
  volmp.afficher(ui);
  hismp.afficher(ui);
//  ui->lineEdit_idvol->setValidator(new QRegExpValidator(  QRegExp("[A-Za-z]*")  ));
  ui->lineEdit_nbvol->setValidator(new QIntValidator (0,99999999,ui->lineEdit_nbvol));
  //ui->lineEdit_rechidvol->setValidator(new QIntValidator (0,99999999,ui->lineEdit_rechidvol));
 // ui->lineEdit_destvol->setValidator(new QRegExpValidator(  QRegExp("[A-Za-z]*")  ));
  player = new QMediaPlayer;
  connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(on_positionChanged(qint64)));
  connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(on_durationChanged(qint64)));
 player->setMedia(QUrl::fromLocalFile("C:/Users/MSI/Desktop/template/Ahmed - Copie/video/1.mp4"));
  videoWidget = new QVideoWidget;
  player->setVideoOutput(videoWidget);

  videoWidget->setGeometry(780, 300, 800, 450);
  videoWidget->setParent(this);
  videoWidget->show();
int k=player->volume();
ui->horizontalSlider_volume->setValue(k);
ui->pushButton_3->clicked();
//QModelIndex index=ui->tableView->currentIndex();
//    int i=index.row();
//    QModelIndex in=index.sibling(i,0);
//    QString val=ui->tableView->model()->data(in).toString();

//    QSqlQuery qry;
//    qry.prepare("select id,type,dest,nb_passagers,datev from vol where id='"+val+"' " );
//ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/"+qry.value(2).toString());
ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");
ui->frame_3->hide();
QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect;
effect2->setBlurRadius(20);
effect2->setXOffset(2);
effect2->setYOffset(2);
effect2->setColor(Qt::lightGray);
ui->frame_3->setGraphicsEffect(effect2);
QGraphicsDropShadowEffect *effect3 = new QGraphicsDropShadowEffect;
effect3->setBlurRadius(20);
effect3->setXOffset(2);
effect3->setYOffset(2);
effect3->setColor(Qt::lightGray);
ui->frame_historique->setGraphicsEffect(effect3);
admins a;
a.role(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::init_button(QWidget *q,QString link)
{

    q->setStyleSheet("background: transparent;border-radius:60px;color: white;qproperty-icon:url('"+link+"');font: 40pt  'Oswald';font-size:22px;");
}



void MainWindow::on_pushButton_12_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_12->setChecked(true);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_17->setChecked(false);
    ui->frame_3->hide();

    ui->frame_2->hide();
    ui->frame->hide();
    ui->pushButton_12->setStyleSheet("qproperty-icon:url(:/icons/icons/plane1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
    init_button(ui->pushButton_15,":/icons/icons/passager.png");
    init_button(ui->pushButton_16,":/icons/icons/pilot.png");
    init_button(ui->pushButton_14,":/icons/icons/runway.png");
    init_button(ui->pushButton_13,":/icons/icons/tickets.png");
    init_button(ui->pushButton_11,":/icons/icons/reservation.png");
    init_button(ui->pushButton_3,":/icons/icons/info1.png");
    init_button(ui->pushButton_17,":/icons/icons/history.png");
    ui->frame_historique->hide();

videoWidget->hide();
ui->pushButton_2->hide();
ui->horizontalSlider_volume->hide();
ui->horizontalSlider_progress->hide();
ui->label_video1->hide();
ui->label_13->hide();
ui->label_15->hide();
player->stop();

}

void MainWindow::on_pushButton_15_clicked()
{
    ui->pushButton_12->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_15->setChecked(true);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_17->setChecked(false);
    ui->frame_3->hide();

    ui->frame_2->hide();
    ui->frame->hide();
   ui->pushButton_15->setStyleSheet("qproperty-icon:url(:/icons/icons/passager1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
   init_button(ui->pushButton_16,":/icons/icons/pilot.png");
   init_button(ui->pushButton_14,":/icons/icons/runway.png");
   init_button(ui->pushButton_13,":/icons/icons/tickets.png");
   init_button(ui->pushButton_12,":/icons/icons/plane.png");
   init_button(ui->pushButton_11,":/icons/icons/reservation.png");
   init_button(ui->pushButton_3,":/icons/icons/info1.png");
   init_button(ui->pushButton_17,":/icons/icons/history.png");
   ui->frame_historique->hide();

   videoWidget->hide();
   ui->pushButton_2->hide();
   ui->horizontalSlider_volume->hide();
   ui->horizontalSlider_progress->hide();
   ui->label_video1->hide();
   ui->label_13->hide();
   ui->label_15->hide();
   player->stop();

}

void MainWindow::on_pushButton_11_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_11->setChecked(true);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_17->setChecked(false);
    ui->frame_historique->hide();
    ui->frame_3->hide();

    ui->frame_2->hide();
    ui->frame->hide();
        ui->pushButton_11->setStyleSheet("qproperty-icon:url(:/icons/icons/reservation1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_16,":/icons/icons/pilot.png");
init_button(ui->pushButton_14,":/icons/icons/runway.png");
init_button(ui->pushButton_13,":/icons/icons/tickets.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_3,":/icons/icons/info1.png");
init_button(ui->pushButton_17,":/icons/icons/history.png");
ui->frame_historique->hide();

videoWidget->hide();
ui->pushButton_2->hide();
ui->horizontalSlider_volume->hide();
ui->horizontalSlider_progress->hide();
ui->label_video1->hide();
ui->label_13->hide();
ui->label_15->hide();
player->stop();

}

void MainWindow::on_pushButton_13_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_13->setChecked(true);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_17->setChecked(false);
    ui->frame_historique->hide();
    ui->frame_3->show();

    ui->frame_2->show();
    ui->frame->show();
    volmp.afficher(ui);

    ui->pushButton_13->setStyleSheet("qproperty-icon:url(:/icons/icons/tickets1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_16,":/icons/icons/pilot.png");
init_button(ui->pushButton_14,":/icons/icons/runway.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_11,":/icons/icons/reservation.png");
init_button(ui->pushButton_3,":/icons/icons/info1.png");
init_button(ui->pushButton_17,":/icons/icons/history.png");

videoWidget->hide();
ui->pushButton_2->hide();
ui->horizontalSlider_volume->hide();
ui->horizontalSlider_progress->hide();
ui->label_video1->hide();
ui->label_13->hide();
ui->label_15->hide();
player->stop();

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_14->setChecked(true);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_17->setChecked(false);
    ui->frame_3->hide();

    ui->frame_2->hide();
    ui->frame->hide();
        ui->pushButton_14->setStyleSheet("qproperty-icon:url(:/icons/icons/runway1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_16,":/icons/icons/pilot.png");
init_button(ui->pushButton_13,":/icons/icons/tickets.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_11,":/icons/icons/reservation.png");
init_button(ui->pushButton_3,":/icons/icons/info1.png");
init_button(ui->pushButton_17,":/icons/icons/history.png");
ui->frame_historique->hide();

videoWidget->hide();
ui->pushButton_2->hide();
ui->horizontalSlider_volume->hide();
ui->horizontalSlider_progress->hide();
ui->label_video1->hide();
ui->label_13->hide();
ui->label_15->hide();
player->stop();

}

void MainWindow::on_pushButton_16_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_16->setChecked(true);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_17->setChecked(false);
    ui->frame_3->hide();

    ui->frame_2->hide();
    ui->frame->hide();
    ui->pushButton_16->setStyleSheet("qproperty-icon:url(:/icons/icons/pilot1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_14,":/icons/icons/runway.png");
init_button(ui->pushButton_13,":/icons/icons/tickets.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_11,":/icons/icons/reservation.png");
init_button(ui->pushButton_3,":/icons/icons/info1.png");
init_button(ui->pushButton_17,":/icons/icons/history.png");
ui->frame_historique->hide();

videoWidget->hide();
ui->pushButton_2->hide();
ui->horizontalSlider_volume->hide();
ui->horizontalSlider_progress->hide();
ui->label_video1->hide();
ui->label_13->hide();
ui->label_15->hide();
player->stop();

}
void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_3->setChecked(true);
    ui->pushButton_17->setChecked(false);
    ui->frame_3->hide();

    ui->frame_2->hide();
    ui->frame->hide();
    ui->pushButton_3->setStyleSheet("qproperty-icon:url(:/icons/icons/info.png);background: white;border-image:url(:/icons/icons/info0.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
    init_button(ui->pushButton_15,":/icons/icons/passager.png");
    init_button(ui->pushButton_14,":/icons/icons/runway.png");
    init_button(ui->pushButton_13,":/icons/icons/tickets.png");
    init_button(ui->pushButton_12,":/icons/icons/plane.png");
    init_button(ui->pushButton_11,":/icons/icons/reservation.png");
    init_button(ui->pushButton_16,":/icons/icons/pilot.png");
    init_button(ui->pushButton_17,":/icons/icons/history.png");
    ui->frame_historique->hide();

    videoWidget->show();
    ui->pushButton_2->show();
    ui->horizontalSlider_volume->show();
    ui->horizontalSlider_progress->show();
    ui->label_video1->show();
    ui->label_13->show();
    ui->label_15->show();
}
void MainWindow::on_pushButton_17_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_17->setChecked(true);
    ui->frame_3->hide();

    ui->frame_2->hide();
    ui->frame->hide();
    ui->pushButton_17->setStyleSheet("qproperty-icon:url(:/icons/icons/history1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
    init_button(ui->pushButton_15,":/icons/icons/passager.png");
    init_button(ui->pushButton_14,":/icons/icons/runway.png");
    init_button(ui->pushButton_13,":/icons/icons/tickets.png");
    init_button(ui->pushButton_12,":/icons/icons/plane.png");
    init_button(ui->pushButton_11,":/icons/icons/reservation.png");
    init_button(ui->pushButton_16,":/icons/icons/pilot.png");
    init_button(ui->pushButton_3,":/icons/icons/info1.png");
    ui->frame_historique->show();
    admins a;
    hismp.afficheradmin(ui,a.getid());
ui->line_2->show();
    videoWidget->hide();
    ui->pushButton_2->hide();
    ui->horizontalSlider_volume->hide();
    ui->horizontalSlider_progress->hide();
    ui->label_video1->hide();
    ui->label_13->hide();
    ui->label_15->hide();
    player->stop();

}

void MainWindow::on_pushButton_ajoutvol_clicked()
{
    int id=ui->lineEdit_idvol->text().toInt();
    int nbp=ui->lineEdit_nbvol->text().toInt();
   QDate date=ui->dateTimeEdit->date();
    QString type=ui->comboBox_typevol->currentText();
    QString dest=ui->lineEdit_destvol->text();
    QString id_pilote=ui->lineEdit_pilotevol->text();
     QString num_serie=ui->lineEdit_avionvol->text();
    vol V(id,nbp,type,dest,date,num_serie,id_pilote);

    bool test=V.ajouter();
    if (test)
    {
        volmp.afficher(ui);
        QSqlQuery query;
        admins a;

        historique h(a.getid(),"ajouter une vol de id : "+ui->lineEdit_idvol->text(),QDateTime::currentDateTime());
        query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
        query.bindValue(":USERNAME", h.getuser());
        query.bindValue(":ACTION", h.getaction());
        query.bindValue(":DATEH", h.getdateh());
       // query.bindValue(":num_serie", num_serie);
        //query.bindValue(":id_pilote", id_pilote);
query.exec();

    }


}

void MainWindow::on_pushButton_suppvol_clicked()
{QModelIndex index=ui->tableView->currentIndex();
    int i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();
    bool test=volmp.supprimer(val);
    if (test)
    {

        volmp.afficher(ui);
        QSqlQuery query;
        admins a;

        historique h(a.getid(),"supprimer une vol de id : "+val,QDateTime::currentDateTime());
        query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
        query.bindValue(":USERNAME", h.getuser());
        query.bindValue(":ACTION", h.getaction());
        query.bindValue(":DATEH", h.getdateh());
       // query.bindValue(":num_serie", num_serie);
        //query.bindValue(":id_pilote", id_pilote);
query.exec();
    }

}

void MainWindow::on_pushButton_modvol_clicked()
{
    int id=ui->lineEdit_idvol->text().toInt();
    int nbp=ui->lineEdit_nbvol->text().toInt();
   QDate date=ui->dateTimeEdit->date();
    QString type=ui->comboBox_typevol->currentText();
    QString dest=ui->lineEdit_destvol->text();
    QString id_pilote=ui->lineEdit_pilotevol->text();
     QString num_serie=ui->lineEdit_avionvol->text();
    vol V(id,nbp,type,dest,date,num_serie,id_pilote);
    bool test=V.modifier();
if(test){
volmp.afficher(ui);
QSqlQuery query;
admins a;

historique h(a.getid(),"modifier une vol de id : "+ui->lineEdit_idvol->text(),QDateTime::currentDateTime());
query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
query.bindValue(":USERNAME", h.getuser());
query.bindValue(":ACTION", h.getaction());
query.bindValue(":DATEH", h.getdateh());
// query.bindValue(":num_serie", num_serie);
//query.bindValue(":id_pilote", id_pilote);
query.exec();}
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select id,type,dest,nb_passagers,datev from vol where id='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_idvol->setText(qry.value(0).toString());
            ui->lineEdit_nbvol->setText(qry.value(3).toString());
            ui->comboBox_typevol->setCurrentText(qry.value(1).toString());
            ui->lineEdit_destvol->setText(qry.value(2).toString());
            ui->dateTimeEdit->setDate(qry.value(4).toDate());

//            ui->lineEdit_pilotevol->setText(qry.value(6).toString());
//            ui->lineEdit_avionvol->setText(qry.value(5).toString());
        }

}
volmp.initBrowserView(ui);
}


void MainWindow::on_lineEdit_rechidvol_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechidvol->text();

    if(text.isEmpty())
    {
        volmp.afficher(ui);

    }
    else
    {
        qry->prepare("select id,type,dest,nb_passagers,datev from vol where ( id LIKE'%"+text+"%' OR type LIKE'%"+text+"%' OR dest LIKE'%"+text+"%'OR nb_passagers LIKE'%"+text+"%'OR datev LIKE'%"+text+"%') ");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }
}


void MainWindow::on_pushButton_impvol_clicked()
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

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString type=ui->comboBox->currentText();
    if (type=="Par defaut"){
        qry->prepare("select id,type,dest,nb_passagers,datev from vol");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
                      modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
        ui->tableView->setModel(modal);}
        else if (type=="Identifiant"){
            qry->prepare("select id,type,dest,nb_passagers,datev from vol order by id");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
             modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));

            ui->tableView->setModel(modal);


        }
        else if (type=="Destination"){
            qry->prepare("select id,type,dest,nb_passagers,datev from vol order by dest");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
             modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));

            ui->tableView->setModel(modal);


        }
        else if (type=="Nb de passagers"){
            qry->prepare("select id,type,dest,nb_passagers,datev from vol order by NB_PASSAGERS");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
             modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));

            ui->tableView->setModel(modal);


        }
    else if (type=="Avion"){
        qry->prepare("select id,type,dest,nb_passagers,datev from vol order by num_seriee");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
         modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));

        ui->tableView->setModel(modal);


    }
    else if (type=="Pilote"){
        qry->prepare("select id,type,dest,nb_passagers,datev  from vol order by id_pilote");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
         modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));

        ui->tableView->setModel(modal);


    }
    else if (type=="Date"){
        qry->prepare("select id,type,dest,nb_passagers,datev from vol order by datev");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
         modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));

        ui->tableView->setModel(modal);


    }
}

void MainWindow::on_horizontalSlider_volume_sliderMoved(int position)
{

    player->setVolume(position);

}

void MainWindow::on_horizontalSlider_progress_sliderMoved(int position)
{
    player->setPosition(position);


}

void MainWindow::on_pushButton_2_clicked()
{
    if( okey==0){
     player->play();

okey=1;}
    else if (okey==1){
        player->pause();

        okey=0;
    }

}


void MainWindow::on_positionChanged(qint64 position)
{
    ui->horizontalSlider_progress->setValue(position);

}
void MainWindow::on_durationChanged(qint64 position)
{
    ui->horizontalSlider_progress->setMaximum(position);

}



void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query,qry;

    admins a;
   QString id=a.getid();
   int action=0;
   QString res=QString::number(action);
   query.prepare("UPDATE admins "" SET action=:action  where username='"+id+"' ");
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

void MainWindow::on_pushButton_pdfhistorique_clicked()
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

void MainWindow::on_pushButton_supphistorique_clicked()
{
    QModelIndex index=ui->tableView_4->currentIndex();
        int i=index.row();
        QModelIndex in=index.sibling(i,2);
        QDateTime val=ui->tableView_4->model()->data(in).toDateTime();
        bool test=hismp.supprimer(val);
        if (test)
        {

            hismp.afficher(ui);

        }

}



void MainWindow::on_comboBox_trihistorique_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    admins a;
    QString type=ui->comboBox_trihistorique->currentText();
    if (type=="Par defaut"){
        qry->prepare("select * from historique where username=:user");
        qry->bindValue(":user",a.getid());

        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
        modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
         modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

        ui->tableView_4->setModel(modal);}
        else if (type=="User"){
            qry->prepare("select * from historique where username=:user order by username");
            qry->bindValue(":user",a.getid());

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
             modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

            ui->tableView_4->setModel(modal);


        }
        else if (type=="Date"){
            qry->prepare("select * from historique where username=:user order by dateh");
            qry->bindValue(":user",a.getid());

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
             modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

            ui->tableView_4->setModel(modal);


        }

}

void MainWindow::on_lineEdit_rechhistoriqe_textChanged(const QString &arg1)
{
    admins a;
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechhistoriqe->text();

    if(text.isEmpty())
    {
        hismp.afficher(ui);

    }
    else
    {
        qry->prepare("select * from historique where(username=:user and  ( USERNAME LIKE'%"+text+"%' OR DATEH LIKE'%"+text+"%' OR ACTION LIKE'%"+text+"%')) ");
        qry->bindValue(":user",a.getid());

        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_4->setModel(modal);
    }
}


