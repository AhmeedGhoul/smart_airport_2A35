#include "mainwindow.h"
#include "passager.h"
#include "avion.h"
#include "QSslSocket"
#include "smtp.h"
#include "piste.h"
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
#include <QCloseEvent>
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
#include <QtCharts>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
QT_CHARTS_USE_NAMESPACE;
using namespace std;
//const QString getIniPath()
//{
//    const static QString iniPath( qApp->applicationDirPath() + "/settings.ini" );
//    return iniPath;
//}
//QString var = "num reservation"+ui->id+"\n nom : "+ui->nom;
//QString saveFormats()
//{
//    static QString suffix;
//    foreach ( const QByteArray & format , QImageWriter::supportedImageFormats() )
//        suffix += QString( "%1 ( *.%2 )\n" )
//                .arg( QString( format ).toUpper() )
//                .arg( QString( format ) );

//    return suffix;
//}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //,successfulEncoding(false)

{
    ui->setupUi(this);
 //   QSettings ini( getIniPath(), QSettings::IniFormat );

    QGraphicsDropShadowEffect *effect01 = new QGraphicsDropShadowEffect;
    effect01->setBlurRadius(20);
    effect01->setXOffset(2);
    effect01->setYOffset(2);
    effect01->setColor(Qt::lightGray);
    ui->frame_6->setGraphicsEffect(effect01);
    QGraphicsDropShadowEffect *effect12 = new QGraphicsDropShadowEffect;
    effect12->setBlurRadius(20);
    effect12->setXOffset(2);
    effect12->setYOffset(2);
    effect12->setColor(Qt::lightGray);
    ui->frame_11->setGraphicsEffect(effect12);
    QGraphicsDropShadowEffect *effect24 = new QGraphicsDropShadowEffect;
    effect24->setBlurRadius(20);
    effect24->setXOffset(2);
    effect24->setYOffset(2);
    effect24->setColor(Qt::lightGray);
    ui->frame_24->setGraphicsEffect(effect24);
    QGraphicsDropShadowEffect *effect21 = new QGraphicsDropShadowEffect;
    effect21->setBlurRadius(20);
    effect21->setXOffset(2);
    effect21->setYOffset(2);
    effect21->setColor(Qt::lightGray);
    ui->frame_8->setGraphicsEffect(effect21);
    QGraphicsDropShadowEffect *effect23 = new QGraphicsDropShadowEffect;
    effect23->setBlurRadius(20);
    effect23->setXOffset(2);
    effect23->setYOffset(2);
    effect23->setColor(Qt::lightGray);
    ui->frame_23->setGraphicsEffect(effect23);
    QGraphicsDropShadowEffect *effect02 = new QGraphicsDropShadowEffect;
    effect02->setBlurRadius(20);
    effect02->setXOffset(2);
    effect02->setYOffset(2);
    effect02->setColor(Qt::lightGray);
    ui->frame_7->setGraphicsEffect(effect02);
    QGraphicsDropShadowEffect *effect03 = new QGraphicsDropShadowEffect;
    effect03->setBlurRadius(20);
    effect03->setXOffset(2);
    effect03->setYOffset(2);
    effect03->setColor(Qt::lightGray);
    ui->frame_10->setGraphicsEffect(effect03);
    QGraphicsDropShadowEffect *effect04 = new QGraphicsDropShadowEffect;
    effect04->setBlurRadius(20);
    effect04->setXOffset(2);
    effect04->setYOffset(2);
    effect04->setColor(Qt::lightGray);
    ui->frame_9->setGraphicsEffect(effect04);
    QGraphicsDropShadowEffect *effect05 = new QGraphicsDropShadowEffect;
    effect05->setBlurRadius(20);
    effect05->setXOffset(2);
    effect05->setYOffset(2);
    effect05->setColor(Qt::lightGray);
    ui->frame_12->setGraphicsEffect(effect05);
    QGraphicsDropShadowEffect *effect06 = new QGraphicsDropShadowEffect;
    effect06->setBlurRadius(20);
    effect06->setXOffset(2);
    effect06->setYOffset(2);
    effect06->setColor(Qt::lightGray);
    ui->frame_13->setGraphicsEffect(effect06);
    QGraphicsDropShadowEffect *effect07 = new QGraphicsDropShadowEffect;
    effect07->setBlurRadius(20);
    effect07->setXOffset(2);
    effect07->setYOffset(2);
    effect07->setColor(Qt::lightGray);
    ui->frame_16->setGraphicsEffect(effect07);
    QGraphicsDropShadowEffect *effect08 = new QGraphicsDropShadowEffect;
    effect08->setBlurRadius(20);
    effect08->setXOffset(2);
    effect08->setYOffset(2);
    effect08->setColor(Qt::lightGray);
    ui->frame_15->setGraphicsEffect(effect08);
    QGraphicsDropShadowEffect *effect13 = new QGraphicsDropShadowEffect;
    effect13->setBlurRadius(20);
    effect13->setXOffset(2);
    effect13->setYOffset(2);
    effect13->setColor(Qt::lightGray);
    ui->frame_17->setGraphicsEffect(effect13);
    QGraphicsDropShadowEffect *effect14 = new QGraphicsDropShadowEffect;
    effect14->setBlurRadius(20);
    effect14->setXOffset(2);
    effect14->setYOffset(2);
    effect14->setColor(Qt::lightGray);
    ui->frame_18->setGraphicsEffect(effect14);
    QGraphicsDropShadowEffect *effect09 = new QGraphicsDropShadowEffect;
    effect09->setBlurRadius(20);
    effect09->setXOffset(2);
    effect09->setYOffset(2);
    effect09->setColor(Qt::lightGray);
    ui->frame_19->setGraphicsEffect(effect09);
    QGraphicsDropShadowEffect *effect10 = new QGraphicsDropShadowEffect;
    effect10->setBlurRadius(20);
    effect10->setXOffset(2);
    effect10->setYOffset(2);
    effect10->setColor(Qt::lightGray);
    ui->frame_20->setGraphicsEffect(effect10);
    QGraphicsDropShadowEffect *effect11 = new QGraphicsDropShadowEffect;
    effect11->setBlurRadius(20);
    effect11->setXOffset(2);
    effect11->setYOffset(2);
    effect11->setColor(Qt::lightGray);
    ui->frame_21->setGraphicsEffect(effect11);
    QGraphicsDropShadowEffect *effect15 = new QGraphicsDropShadowEffect;
    effect15->setBlurRadius(20);
    effect15->setXOffset(2);
    effect15->setYOffset(2);
    effect15->setColor(Qt::lightGray);
    ui->frame_22->setGraphicsEffect(effect15);
    QGraphicsDropShadowEffect *effect16 = new QGraphicsDropShadowEffect;
    effect16->setBlurRadius(20);
    effect16->setXOffset(2);
    effect16->setYOffset(2);
    effect16->setColor(Qt::lightGray);
    ui->frame_14->setGraphicsEffect(effect16);
    ui->frame_15->hide();
    ui->frame_16->hide();
    ui->frame_17->hide();
ui->frame_21->hide();
ui->frame_20->hide();
ui->frame_19->hide();

    ui->tableView_5->setModel(passmp.afficher());
    ui->tableView_5->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    popUp=new PopUp();
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
    ui->tableView->setModel(volmp.afficher());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
  ui->tableView_4->setModel(hismp.afficher());

  ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
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

  videoWidget->setGeometry(780, 360, 800, 450);
  videoWidget->setParent(this);
  videoWidget->show();
int k=player->volume();
ui->horizontalSlider_volume->setValue(k);
ui->pushButton_3->clicked();
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
QGraphicsDropShadowEffect *effect4 = new QGraphicsDropShadowEffect;
effect4->setBlurRadius(20);
effect4->setXOffset(2);
effect4->setYOffset(2);
effect4->setColor(Qt::lightGray);
ui->label_13->setGraphicsEffect(effect4);
QGraphicsDropShadowEffect *effect5 = new QGraphicsDropShadowEffect;
effect5->setBlurRadius(20);
effect5->setXOffset(2);
effect5->setYOffset(2);
effect5->setColor(Qt::lightGray);
ui->label_video1->setGraphicsEffect(effect5);
QGraphicsDropShadowEffect *effect6 = new QGraphicsDropShadowEffect;
effect6->setBlurRadius(20);
effect6->setXOffset(2);
effect6->setYOffset(2);
effect6->setColor(Qt::lightGray);
videoWidget->setGraphicsEffect(effect6);
QGraphicsDropShadowEffect *effect7 = new QGraphicsDropShadowEffect;
effect7->setBlurRadius(20);
effect7->setXOffset(2);
effect7->setYOffset(2);
effect7->setColor(Qt::lightGray);
ui->frame_4->setGraphicsEffect(effect7);
QGraphicsDropShadowEffect *effect8 = new QGraphicsDropShadowEffect;
effect8->setBlurRadius(20);
effect8->setXOffset(2);
effect8->setYOffset(2);
effect8->setColor(Qt::lightGray);
ui->frame_5->setGraphicsEffect(effect8);
admins a;
if(a.role()==0){
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
ui->frame_5->hide();
ui->frame_11->hide();
}
if(a.role()==1){

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
    ui->frame_5->hide();

}
if(a.role()==2){

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
    ui->frame_5->hide();

}
if(a.role()==3){

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
    ui->frame_5->hide();

}
if(a.role()==4){

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
    ui->frame_5->hide();

}
if(a.role()==5){

    ui->pushButton_14->hide();
    ui->pushButton_11->hide();
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->setGeometry(-60,209,313,100);
    ui->pushButton_17->setGeometry(-109,308,362,100);
    ui->line->hide();
    ui->line_3->hide();
    ui->line_4->hide();
    ui->line_5->hide();
    ui->line_8->hide();
    ui->pushButton_supphistorique->hide();
    ui->frame_5->hide();

}
//volmp.choix_bar(ui);
ui->frame_4->hide();
ui->frame_8->hide();
ui->frame_9->hide();
ui->frame_10->hide();
ui->frame_12->hide();
ui->frame_13->hide();
ui->tableView_2->setModel(admp.afficher());

ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
notif();
occ();
ui->frame_14->hide();
ui->frame_18->hide();
ui->frame_22->hide();
ui->frame_23->hide();
ui->frame_24->hide();
ui->frame_25->hide();

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
    ui->frame_8->hide();
    ui->frame_9->show();
    ui->frame_10->show();
    ui->frame_2->hide();
    ui->frame->hide();
    ui->frame_12->hide();
    ui->frame_13->hide();
    ui->pushButton_12->setStyleSheet("qproperty-icon:url(:/icons/icons/plane1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
    init_button(ui->pushButton_15,":/icons/icons/passager.png");
    init_button(ui->pushButton_16,":/icons/icons/pilot.png");
    init_button(ui->pushButton_14,":/icons/icons/runway.png");
    init_button(ui->pushButton_13,":/icons/icons/tickets.png");
    init_button(ui->pushButton_11,":/icons/icons/reservation.png");
    init_button(ui->pushButton_3,":/icons/icons/info1.png");
    init_button(ui->pushButton_17,":/icons/icons/history.png");
    ui->frame_historique->hide();
ui->frame_3->hide();
videoWidget->hide();
ui->pushButton_2->hide();
ui->horizontalSlider_volume->hide();
ui->horizontalSlider_progress->hide();
ui->label_video1->hide();
ui->label_13->hide();
ui->label_15->hide();
player->stop();
ui->frame_4
->hide();
ui->frame_5->hide();
ui->frame_6->hide();
ui->frame_7->hide();
ui->tableView_3->setModel(avmp.afficher());
ui->frame_11->show();
ui->frame_15->hide();
ui->frame_16->hide();
ui->frame_17->hide();
ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
statavion();
ui->frame_14->hide();
ui->frame_18->hide();
ui->frame_21->hide();
ui->frame_20->hide();
ui->frame_19->hide();
ui->frame_22->hide();
ui->frame_23->hide();
ui->frame_24->show();
ui->frame_25->hide();

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
    ui->frame_6->show();
    ui->frame_7->show();
    statpass();
    ui->frame_9->hide();
    ui->frame_10->hide();
    ui->frame_2->hide();
    ui->frame->hide();
    ui->frame_12->hide();
    ui->frame_13->hide();
    ui->frame_15->hide();
    ui->frame_16->hide();
    ui->frame_17->hide();
   ui->pushButton_15->setStyleSheet("qproperty-icon:url(:/icons/icons/passager1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
   init_button(ui->pushButton_16,":/icons/icons/pilot.png");
   init_button(ui->pushButton_14,":/icons/icons/runway.png");
   init_button(ui->pushButton_13,":/icons/icons/tickets.png");
   init_button(ui->pushButton_12,":/icons/icons/plane.png");
   init_button(ui->pushButton_11,":/icons/icons/reservation.png");
   init_button(ui->pushButton_3,":/icons/icons/info1.png");
   init_button(ui->pushButton_17,":/icons/icons/history.png");
   ui->frame_historique->hide();
ui->frame_3->hide();
   videoWidget->hide();
   ui->pushButton_2->hide();
   ui->horizontalSlider_volume->hide();
   ui->horizontalSlider_progress->hide();
   ui->label_video1->hide();
   ui->label_13->hide();
   ui->label_15->hide();
   player->stop();
   ui->frame_4->hide();
   ui->frame_11->hide();

   ui->frame_5->hide();
   ui->checkBox_6->setCheckState(Qt::Unchecked);

   ui->checkBox_7->setCheckState(Qt::Unchecked);

   ui->checkBox_8->setCheckState(Qt::Unchecked);

   ui->checkBox_9->setCheckState(Qt::Unchecked);
   ui->frame_8->show();
   ui->frame_24->hide();

   ui->checkBox_10->setCheckState(Qt::Unchecked);
   ui->tableView_5->setModel(passmp.afficher());
   ui->tableView_5->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
   ui->frame_18->hide();
   ui->frame_21->hide();
   ui->frame_20->hide();
   ui->frame_19->hide();
   ui->frame_22->hide();
   ui->frame_23->show();

  setCamera(QCameraInfo::defaultCamera());
  ui->frame_25->hide();

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
    ui->frame_6->hide();
    ui->frame_7->hide();
    ui->frame_2->hide();
    ui->frame_9->hide();
    ui->frame_10->hide();
    ui->frame->hide();
    ui->frame_12->hide();
    ui->frame_13->hide();
    ui->frame_15->show();
    ui->frame_16->show();
    ui->frame_17->show();
        ui->pushButton_11->setStyleSheet("qproperty-icon:url(:/icons/icons/reservation1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_16,":/icons/icons/pilot.png");
init_button(ui->pushButton_14,":/icons/icons/runway.png");
init_button(ui->pushButton_13,":/icons/icons/tickets.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_3,":/icons/icons/info1.png");
init_button(ui->pushButton_17,":/icons/icons/history.png");
ui->frame_historique->hide();
ui->frame_3->hide();
videoWidget->hide();
ui->pushButton_2->hide();
ui->horizontalSlider_volume->hide();
ui->horizontalSlider_progress->hide();
ui->label_video1->hide();
ui->label_13->hide();
ui->label_15->hide();
player->stop();
ui->frame_4->hide();
ui->frame_11->hide();
ui->frame_23->hide();
ui->frame_24->hide();

ui->frame_5->hide();
ui->frame_8->hide();
ui->frame_14->hide();
ui->tableView_9->setModel(resermp.afficher());
ui->frame_18->show();

statreservation();
ui->frame_22->hide();

ui->tableView_9->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
ui->frame_21->hide();
ui->frame_20->hide();
ui->frame_19->hide();
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
    ui->frame_2->show();
    ui->frame->show();
    ui->frame_9->hide();
    ui->frame_10->hide();
    ui->tableView->setModel(volmp.afficher());
    ui->frame_6->hide();
    ui->frame_7->hide();
    ui->frame_12->hide();
    ui->frame_13->hide();
    ui->frame_15->hide();
    ui->frame_16->hide();
    ui->frame_17->hide();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->pushButton_13->setStyleSheet("qproperty-icon:url(:/icons/icons/tickets1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_16,":/icons/icons/pilot.png");
init_button(ui->pushButton_14,":/icons/icons/runway.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_11,":/icons/icons/reservation.png");
init_button(ui->pushButton_3,":/icons/icons/info1.png");
init_button(ui->pushButton_17,":/icons/icons/history.png");
ui->frame_3->show();
videoWidget->hide();
ui->pushButton_2->hide();
ui->horizontalSlider_volume->hide();
ui->horizontalSlider_progress->hide();
ui->label_video1->hide();
ui->label_13->hide();
ui->label_15->hide();
player->stop();
//volmp.choix_bar(ui);
occ();
ui->frame_8->hide();
ui->frame_11->hide();
ui->frame_24->hide();

ui->frame_4->show();
ui->frame_5->hide();
notif();
ui->frame_14->hide();
ui->frame_18->hide();
ui->frame_21->hide();
ui->frame_20->hide();
ui->frame_19->hide();
ui->frame_22->hide();
ui->frame_23->hide();
ui->frame_25->hide();

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->frame_6->hide();
    ui->frame_7->hide();
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_14->setChecked(true);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_17->setChecked(false);
ui->frame_3->hide();
ui->frame_9->hide();
ui->frame_10->hide();
ui->frame_12->hide();
ui->frame_13->hide();
    ui->frame_2->hide();
    ui->frame->hide();
    ui->frame_15->hide();
    ui->frame_16->hide();
    ui->frame_17->hide();
        ui->pushButton_14->setStyleSheet("qproperty-icon:url(:/icons/icons/runway1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_16,":/icons/icons/pilot.png");
init_button(ui->pushButton_13,":/icons/icons/tickets.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_11,":/icons/icons/reservation.png");
init_button(ui->pushButton_3,":/icons/icons/info1.png");
init_button(ui->pushButton_17,":/icons/icons/history.png");
ui->frame_historique->hide();
ui->frame_3->hide();
videoWidget->hide();
ui->pushButton_2->hide();
ui->horizontalSlider_volume->hide();
ui->horizontalSlider_progress->hide();
ui->label_video1->hide();
ui->label_13->hide();
ui->label_15->hide();
player->stop();
ui->frame_4->hide();
ui->frame_11->hide();
ui->frame_23->hide();
ui->frame_24->hide();

ui->frame_5->hide();
ui->frame_8->hide();
ui->frame_14->hide();
ui->frame_18->hide();
ui->frame_22->show();

ui->frame_21->show();
ui->frame_20->show();
ui->frame_19->show();
ui->tableView_8->setModel(pismp.afficher());

ui->tableView_8->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
statpiste();
ui->frame_25->hide();

}

void MainWindow::on_pushButton_16_clicked()
{
    ui->frame_6->hide();
    ui->frame_7->hide();
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_16->setChecked(true);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_17->setChecked(false);
ui->frame_3->hide();
ui->frame_9->hide();
ui->frame_10->hide();
ui->frame_12->show();
ui->frame_13->show();
    ui->frame_2->hide();
    ui->frame->hide();
    ui->frame_15->hide();
    ui->frame_16->hide();
    ui->frame_17->hide();
    ui->pushButton_16->setStyleSheet("qproperty-icon:url(:/icons/icons/pilot1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_14,":/icons/icons/runway.png");
init_button(ui->pushButton_13,":/icons/icons/tickets.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_11,":/icons/icons/reservation.png");
init_button(ui->pushButton_3,":/icons/icons/info1.png");
init_button(ui->pushButton_17,":/icons/icons/history.png");
ui->frame_historique->hide();
ui->frame_3->hide();
videoWidget->hide();
ui->pushButton_2->hide();
ui->horizontalSlider_volume->hide();
ui->horizontalSlider_progress->hide();
ui->label_video1->hide();
ui->label_13->hide();
ui->label_15->hide();
player->stop();
ui->frame_4->hide();
ui->frame_11->hide();
ui->frame_23->hide();
ui->frame_24->hide();

ui->frame_5->hide();
ui->frame_5->hide();
ui->frame_8->hide();
statpilote();
statpilotepie();
ui->frame_25->show();

ui->frame_14->show();
ui->frame_18->hide();
qDebug()<<QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
ui->frame_21->hide();
ui->frame_20->hide();
ui->frame_19->hide();
ui->frame_22->hide();

}
void MainWindow::on_pushButton_3_clicked()
{
    ui->frame_6->hide();
    ui->frame_7->hide();
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_3->setChecked(true);
    ui->pushButton_17->setChecked(false);
ui->frame_3->hide();
ui->frame_9->hide();
ui->frame_10->hide();
ui->frame_12->hide();
ui->frame_13->hide();
ui->frame_15->hide();
ui->frame_16->hide();
ui->frame_17->hide();
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
ui->frame_3->hide();
    videoWidget->show();
    ui->pushButton_2->show();
    ui->horizontalSlider_volume->show();
    ui->horizontalSlider_progress->show();
    ui->label_video1->show();
    ui->label_13->show();
    ui->label_15->show();
    ui->frame_4->hide();
    ui->frame_11->hide();
    ui->frame_24->hide();

    ui->frame_23->hide();
    ui->frame_5->hide();
    ui->tableView_2->setModel(admp.afficher());

    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    QString res1,r=admp.getid();
    QSqlQuery qry;
    qry.prepare("select * from admins where username='"+r+"' " );
    if(qry.exec())
    {
        while(qry.next())
        {
            res1=qry.value(2).toString();

        }
    }
if(res1=="Directer"){
    ui->frame_5->show();}
ui->frame_8->hide();
ui->tableView_7->setModel(pilmp.afficher());
ui->frame_14->hide();
ui->frame_18->hide();
ui->frame_21->hide();
ui->frame_20->hide();
ui->frame_19->hide();
ui->frame_22->hide();
ui->frame_24->hide();
ui->frame_25->hide();

ui->tableView_7->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
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
    ui->frame_6->hide();
    ui->frame_9->hide();
    ui->frame_10->hide();
    ui->frame_7->hide();
    ui->frame_15->hide();
    ui->frame_16->hide();
    ui->frame_17->hide();
    ui->frame_12->hide();
    ui->frame_13->hide();
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
    QString res1,r=admp.getid();
    QSqlQuery qry;
    qry.prepare("select * from admins where username='"+r+"' " );
    if(qry.exec())
    {
        while(qry.next())
        {
            res1=qry.value(2).toString();

        }
    }
if(res1=="Directer"){
    ui->tableView_4->setModel(hismp.afficher());

    ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);}
else{
    ui->tableView_4->setModel(hismp.afficheradmin(a.getid()));

    ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);}

ui->frame_11->hide();
ui->frame_24->hide();

        ui->line_2->show();
    videoWidget->hide();
    ui->pushButton_2->hide();
    ui->horizontalSlider_volume->hide();
    ui->horizontalSlider_progress->hide();
    ui->label_video1->hide();
    ui->label_13->hide();
    ui->label_15->hide();
    player->stop();
    ui->frame_4->hide();
    ui->frame_5->hide();
    ui->frame_8->hide();
    ui->frame_14->hide();
    ui->frame_18->hide();
    ui->frame_21->hide();
    ui->frame_20->hide();
    ui->frame_19->hide();
    ui->frame_22->hide();
    ui->frame_23->hide();
    ui->frame_25->hide();

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
        ui->tableView->setModel(volmp.afficher());

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        QSqlQuery query;
        admins a;

               historique h(a.getid(),"ajouter une vol de id : "+ui->lineEdit_idvol->text(),QDateTime::currentDateTime());
        query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
        query.bindValue(":USERNAME", h.getuser());
        query.bindValue(":ACTION", h.getaction());
        query.bindValue(":DATEH", h.getdateh());
        ui->lineEdit_idvol->setText("");
        ui->lineEdit_nbvol->setText("");
        ui->lineEdit_destvol->setText("");
        ui->lineEdit_pilotevol->setText("");
        ui->lineEdit_avionvol->setText("");
       // query.bindValue(":num_serie", num_serie);
        //query.bindValue(":id_pilote", id_pilote);
query.exec();

    }

    //volmp.choix_bar(ui);
    occ();


}

void MainWindow::on_pushButton_suppvol_clicked()
{QModelIndex index=ui->tableView->currentIndex();
    int i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();
    bool test=volmp.supprimer(val);
    if (test)
    {

        ui->tableView->setModel(volmp.afficher());

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        QSqlQuery query;
        admins a;

               historique h(a.getid(),"supprimer une vol de id : "+val,QDateTime::currentDateTime());
        query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
        query.bindValue(":USERNAME", h.getuser());
        query.bindValue(":ACTION", h.getaction());
        query.bindValue(":DATEH", h.getdateh());
        ui->lineEdit_idvol->setText("");
        ui->lineEdit_nbvol->setText("");
        ui->lineEdit_destvol->setText("");
        ui->lineEdit_pilotevol->setText("");
        ui->lineEdit_avionvol->setText("");
       // query.bindValue(":num_serie", num_serie);
        //query.bindValue(":id_pilote", id_pilote);
query.exec();
    }
    //volmp.choix_bar(ui);
    occ();

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
    ui->tableView->setModel(volmp.afficher());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
QSqlQuery query;
admins a;

       historique h(a.getid(),"modifier une vol de id : "+ui->lineEdit_idvol->text(),QDateTime::currentDateTime());
query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
query.bindValue(":USERNAME", h.getuser());
query.bindValue(":ACTION", h.getaction());
query.bindValue(":DATEH", h.getdateh());
ui->lineEdit_idvol->setText("");
ui->lineEdit_nbvol->setText("");
ui->lineEdit_destvol->setText("");
ui->lineEdit_pilotevol->setText("");
ui->lineEdit_avionvol->setText("");
// query.bindValue(":num_serie", num_serie);
//query.bindValue(":id_pilote", id_pilote);
query.exec();}
//volmp.choix_bar(ui);
occ();

}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select id,type,dest,nb_passagers,datev,num_serie,id_pilote from vol where id='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_idvol->setText(qry.value(0).toString());
            ui->lineEdit_nbvol->setText(qry.value(3).toString());
            ui->comboBox_typevol->setCurrentText(qry.value(1).toString());
            ui->lineEdit_destvol->setText(qry.value(2).toString());
            ui->dateTimeEdit->setDate(qry.value(4).toDate());
            ui->lineEdit_pilotevol->setText(qry.value(6).toString());
            ui->lineEdit_avionvol->setText(qry.value(5).toString());
        }
}
initBrowserView();
}


void MainWindow::on_lineEdit_rechidvol_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechidvol->text();

    if(text.isEmpty())
    {
        ui->tableView->setModel(volmp.afficher());

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    }
    else
    {
        qry->prepare("select id,type,dest,nb_passagers,datev,num_serie,id_pilote from vol where ( id LIKE'%"+text+"%' OR type LIKE'%"+text+"%' OR dest LIKE'%"+text+"%'OR nb_passagers LIKE'%"+text+"%'OR datev LIKE'%"+text+"%' OR num_serie LIKE'%"+text+"%' OR id_pilote LIKE'%"+text+"%') ");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }
   initBrowserView();

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
        qry->prepare("select id,type,dest,nb_passagers,datev,num_serie,id_pilote from vol");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
                      modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
                      modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Avion"));
                      modal->setHeaderData(6,Qt::Horizontal,QObject::tr("Pilote"));
        ui->tableView->setModel(modal);}
        else if (type=="Identifiant"){
            qry->prepare("select id,type,dest,nb_passagers,datev,num_serie,id_pilote from vol order by id");
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


        }
        else if (type=="Destination"){
            qry->prepare("select id,type,dest,nb_passagers,datev,num_serie,id_pilote from vol order by dest");
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


        }
        else if (type=="Nb de passagers"){
            qry->prepare("select id,type,dest,nb_passagers,datev,num_serie,id_pilote from vol order by NB_PASSAGERS");
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


        }
    else if (type=="Avion"){
        qry->prepare("select id,type,dest,nb_passagers,datev,num_serie,id_pilote from vol order by num_seriee");
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


    }
    else if (type=="Pilote"){
        qry->prepare("select id,type,dest,nb_passagers,datev,num_serie,id_pilote  from vol order by id_pilote");
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


    }
    else if (type=="Date"){
        qry->prepare("select id,type,dest,nb_passagers,datev,num_serie,id_pilote from vol order by datev");
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

okey=1;
ui->pushButton_2->setText("Pause");

    }
    else if (okey==1){
        player->pause();

        okey=0;
        ui->pushButton_2->setText("Lancer");
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
        qApp->quit();
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

            ui->tableView_4->setModel(hismp.afficher());

            ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        }

}



void MainWindow::on_comboBox_trihistorique_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    admins a;
    QString type=ui->comboBox_trihistorique->currentText();
    if (a.role()==1 &&a.role()==2 &&a.role()==3 &&a.role()==4 &&a.role()==5){
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


        }}
    else{
        if (type=="Par defaut"){
            qry->prepare("select * from historique");
            qry->bindValue(":user",a.getid());

            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
             modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

            ui->tableView_4->setModel(modal);}
            else if (type=="User"){
                qry->prepare("select * from historique order by username");
                qry->bindValue(":user",a.getid());

                qry->exec();
                modal->setQuery(*qry);
                modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
                modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
                 modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

                ui->tableView_4->setModel(modal);


            }
            else if (type=="Date"){
                qry->prepare("select * from historique order by dateh");
                qry->bindValue(":user",a.getid());

                qry->exec();
                modal->setQuery(*qry);
                modal->setHeaderData(0,Qt::Horizontal,QObject::tr("User"));
                modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Action"));
                 modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Temps"));

                ui->tableView_4->setModel(modal);
    }

}}

void MainWindow::on_lineEdit_rechhistoriqe_textChanged(const QString &arg1)
{
    admins a;

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechhistoriqe->text();

    if(text.isEmpty())
    {
        ui->tableView_4->setModel(hismp.afficher());

        ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    }
    else
    {
        if (a.role()==1 &&a.role()==2 &&a.role()==3 &&a.role()==4 &&a.role()==5){

        qry->prepare("select * from historique where(username=:user and  ( USERNAME LIKE'%"+text+"%' OR DATEH LIKE'%"+text+"%' OR ACTION LIKE'%"+text+"%')) ");
               qry->bindValue(":user",a.getid());        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_4->setModel(modal);
    }
    else
        {

                qry->prepare("select * from historique where( USERNAME LIKE'%"+text+"%' OR DATEH LIKE'%"+text+"%' OR ACTION LIKE'%"+text+"%') ");
                       qry->bindValue(":user",a.getid());        qry->exec();
                modal->setQuery(*qry);
                ui->tableView_4->setModel(modal);
            }
    }
}


void MainWindow::closeEvent (QCloseEvent *event)
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
     //   QSettings ini( getIniPath(), QSettings::IniFormat );
        qApp->quit();
}




void MainWindow::on_pushButton_ajoutagent_clicked()
{
    QString type=ui->comboBox_typeagent->currentText();
    QString username=ui->lineEdit_iusernameagent->text();
     QString pass=ui->lineEdit_mdpagent->text();
    admins A(username,pass,type,"0");

    bool test=A.ajouter();
    if (test)
    {
        ui->tableView_2->setModel(admp.afficher());

        ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        QSqlQuery query;
        admins a;

               historique h(a.getid(),"ajouter un agent de id : "+ui->lineEdit_idvol->text(),QDateTime::currentDateTime());
        query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
        query.bindValue(":USERNAME", h.getuser());
        query.bindValue(":ACTION", h.getaction());
        query.bindValue(":DATEH", h.getdateh());
        ui->lineEdit_iusernameagent->setText("");
        ui->lineEdit_mdpagent->setText("");
;
query.exec();

    }}

void MainWindow::on_pushButton_modagent_clicked()
{
    QString type=ui->comboBox_typeagent->currentText();
    QString username=ui->lineEdit_iusernameagent->text();
     QString pass=ui->lineEdit_mdpagent->text();
    admins A(username,pass,type,"0");
    bool test=A.modifier();
if(test){
    ui->tableView_2->setModel(admp.afficher());

    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
QSqlQuery query;
admins a;

       historique h(a.getid(),"modifier une vol de id : "+ui->lineEdit_idvol->text(),QDateTime::currentDateTime());
query.prepare("insert into historique (USERNAME,ACTION,DATEH)""values(:USERNAME,:ACTION,:DATEH)");
query.bindValue(":USERNAME", h.getuser());
query.bindValue(":ACTION", h.getaction());
query.bindValue(":DATEH", h.getdateh());

query.exec();

ui->lineEdit_iusernameagent->setText("");
ui->lineEdit_mdpagent->setText("");
}
}

void MainWindow::on_pushButton_suppagent_clicked()
{
    QModelIndex index=ui->tableView_2->currentIndex();
        int i=index.row();
        QModelIndex in=index.sibling(i,0);
        QString val=ui->tableView_2->model()->data(in).toString();
        bool test=admp.supprimer(val);
        if (test)
        {

            ui->tableView_2->setModel(admp.afficher());

            ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
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
    ui->lineEdit_iusernameagent->setText("");
    ui->lineEdit_mdpagent->setText("");
        }
}

void MainWindow::on_pushButton_impagent_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_2->model()->rowCount();
    const int columnCount = ui->tableView_2->model()->columnCount();

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
        if (!ui->tableView_2->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_2->isColumnHidden(column)) {
                QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView_2->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select USERNAME,PASSWORD,type from admins where USERNAME='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_iusernameagent->setText(qry.value(0).toString());
            ui->comboBox_typeagent->setCurrentText(qry.value(2).toString());
            ui->lineEdit_mdpagent->setText(qry.value(1).toString());

        }
}
}
void MainWindow::notif()
{

   int d=QDate::currentDate().day();
   int m=QDate::currentDate().month();
   int y=QDate::currentDate().year();

        QSqlQuery query;
        query.prepare("select id,type,dest,nb_passagers,datev,num_serie,id_pilote from vol  where extract(month  from datev)=:month and extract(day  from datev)=:day and extract(year  from datev)=:year ");
     query.bindValue(":day",d);
     query.bindValue(":month",m);
     query.bindValue(":year",y);

        query.exec();

//query.next();

    while  (query.next())
     {
       QString datev=query.value(4).toString();
       QString id=query.value(0).toString();
       QString type=query.value(1).toString();
       QString dest=query.value(2).toString();
       QString nb_passagers=query.value(3).toString();
       QString num_serie=query.value(5).toString();
       QString id_pilote=query.value(6).toString();

if(datev!="")

    popUp->setPopupText(" votre vol :\n "+id+"  "+type+ "  est  a "+dest+" ,de passageurs : "+nb_passagers+", avion : "+num_serie+",et avion :"+id_pilote);


else
    popUp->setPopupText("pas des vol aujordhui\n");


popUp->show();
query.next();

     }
}
void MainWindow::initBrowserView(){

QString x=ui->lineEdit_destvol->text();;
if (x=="Afghanistan"
      ||  x=="Albanie"
       ||  x=="Algerie"
        ||  x=="Andorre"
        ||  x=="Angola"
        ||  x=="Antigua et Deps"
        ||  x=="Argentine"
        ||  x=="Armenie"
        ||  x=="Australie"
       ||  x=="L'Autriche"
        ||  x=="Azerbaidjan"
        ||  x=="Bahamas"
        ||  x=="Bahrein"
        ||  x=="Bangladesh"
        ||  x=="Barbade"
        ||  x=="Bielorussie"
        ||  x=="Belgique"
        ||  x=="Belize"
        ||  x=="Benin"
        ||  x=="Bhoutan"
        ||  x=="Bolivie"
        ||  x=="Bosnie-Herzegovine"
        ||  x=="Botswana"
        ||  x=="Bresil"
        ||  x=="Brunei"
        ||  x=="Bulgarie"
        ||  x=="Burkina Faso"
        ||  x=="Burundi"
        ||  x=="Cambodge"
        ||  x=="Cameroun"
        ||  x=="Canada"
       ||  x=="Cap-Vert"
       ||  x=="Rep Centrafricaine"

        ||  x=="Tchad"
        ||  x=="Chili"
        ||  x=="Chine"
        ||  x=="Colombie"
        ||  x=="Comores"
        ||  x=="Congo"
        ||  x=="Costa Rica"
        ||  x=="Croatie"
        ||  x=="Cuba"
        ||  x=="Chypre"
        ||  x=="Republique tcheque"
        ||  x=="Danemark"
        ||  x=="Djibouti"
        ||  x=="Dominique"
        ||  x=="Republique Dominicaine"
        ||  x=="Timor Oriental"
        ||  x=="Equateur"
        ||  x=="Egypte"
        ||  x=="Le Salvador"
        ||  x=="Guinee equatoriale"
        ||  x=="erythree"
        ||  x=="Estonie"
        ||  x=="Ethiopie"
        ||  x=="Fidji"
        ||  x=="Finlande"
       ||  x=="France"
        ||  x=="Gabon"
        ||  x=="Gambie"
        ||  x=="Georgie"
        ||  x=="Allemagne"
        ||  x=="Ghana"
        ||  x=="Grece"
        ||  x=="Grenade"
        ||  x=="Guatemala"
        ||  x=="Guinee"
        ||  x=="Guinea-Bissau"
        ||  x=="Guyane"
       ||  x=="Haiti"
       ||  x=="Honduras"
       ||  x=="Hongrie"
       ||  x=="Islande"
       ||  x=="Inde"
       ||  x=="Indonesie"
       ||  x=="L'Iran"
       ||  x=="Irak"
        ||  x=="Irlande"
        ||  x=="Italie"
        ||  x=="Cote d'Ivoire"
        ||  x=="Jamaique"
        ||  x=="Japon"
        ||  x=="Jordan"
        ||  x=="Kazakhstan"
       ||  x=="Kenya"
       ||  x=="Kiribati"
       ||  x=="Coree du Nord"
       ||  x=="Coree du Sud"
       ||  x=="Kosovo"
       ||  x=="Kuweit"
       ||  x=="Kirghizistan"
       ||  x=="Laos"
        ||  x=="Lettonie"
        ||  x=="Liban"
        ||  x=="Lesotho"
        ||  x=="Liberia"
        ||  x=="Libye"
       ||  x=="Liechtenstein"
       ||  x=="Lituanie"
       ||  x=="Luxembourg"
       ||  x=="Macedoine"
       ||  x=="Madagascar"
       ||  x=="Malawi"
       ||  x=="Malaisie"
       ||  x=="Maldives"
       ||  x=="Mali"
||  x=="Malte"
       ||  x=="Iles Marshall"
       ||  x=="Mauritanie"
       ||  x=="Maurice"
       ||  x=="Mexique"
       ||  x=="Micronesie"
       ||  x=="Moldavie"
       ||  x=="Monaco"
       ||  x=="Mongolie"
       ||  x=="Montenegro"
       ||  x=="Maroc"
       ||  x=="Mozambique"
       ||  x=="Birmanie"
       ||  x=="Namibie"
       ||  x=="Nauru"
       ||  x=="Nepal"
       ||  x=="Pays-Bas"
       ||  x=="Nouvelle-Zelande"
        ||  x=="Nicaragua"
        ||  x=="Niger"
       ||  x=="Nigeria"
       ||  x=="Norvege"
       ||  x=="Oman"
        ||  x=="Pakistan"
       ||  x=="Palaos"
       ||  x=="Panama"
       ||  x=="Papouasie Nouvelle Guinee"
       ||  x=="Paraguay"
        ||  x=="Perou"
       ||  x=="Philippines"
       ||  x=="Pologne"
       ||  x=="le Portugal"
        ||  x=="Qatar"
       ||  x=="Roumanie"
       ||  x=="Russe"
       ||  x=="Rwanda"
       ||  x=="Saint-Kitts-et-Nevis"
       ||  x=="Sainte Lucie"
       ||  x=="Saint-Vincent-et-les Grenadines"
       ||  x=="Samoa"
       ||  x=="Saint Marin"
       ||  x=="Sao Tome et Principe"
       ||  x=="Arabie Saoudite"
       ||  x=="Senegal"
       ||  x=="Serbie"
        ||  x=="les Seychelles"
        ||  x=="Sierra Leone"
       ||  x=="Singapour"
       ||  x=="Slovaquie"
       ||  x=="Slovenie"
      ||  x=="iles Salomon"
      ||  x=="Somalie"
      ||  x=="Afrique du Sud"
      ||  x=="Soudan du sud"
      ||  x=="Espagne"
      ||  x=="Sri Lanka"
       ||  x=="Soudan"
       ||  x=="Suriname"
       ||  x=="Swaziland"
       ||  x=="Suede"
       ||  x=="Suisse"
       ||  x=="Syrie"
       ||  x=="Taiwan"
       ||  x=="Tadjikistan"
       ||  x=="Tanzania"
        ||  x=="Thailande"
        ||  x=="Togo"
        ||  x=="Tonga"
        ||  x=="Trinite-et-Tobago"
       ||  x=="Tunisie"
       ||  x=="Turquie"
       ||  x=="Turkmenistan"
       ||  x=="Tuvalu"
      ||  x=="Ouganda"
      ||  x=="Ukraine"
      ||  x=="Emirats Arabes Unis"
      ||  x=="Royaume-Uni"
      ||  x=="etats-Unis"
      ||  x=="Uruguay"
       ||  x=="Ouzbekistan"
       ||  x=="Vanuatu"
      ||  x=="Cite du Vatican"
      ||  x=="Venezuela"
       ||  x=="Vietnam"
      ||  x=="Yemen"
       ||  x=="Zambie"
       ||  x=="Zimbabwe"
        )
ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/dir/Aéroport+de+Tunis-Carthage/"+x);

}
void MainWindow::occ(){

    vector<statt> v1,v11,v2,v3,v4;
    QSqlQuery qry,qry1,qry2,qry3;
statt s0,s1,s2,s3;

    qry.prepare("select id,dest from vol" );


    qry.exec();

        while(qry.next())
        {
            s0.id=qry.value(0).toString();
            s0.dest=qry.value(1).toString();
            v1.push_back(s0);
        }
        int occ0=0,occ01=0,occ02=0,occ03=0,occ1=0,occ2=0,occ3=0,occ4=0;
        QString destocc="",destocc1="",destocc2="",destocc3="",id="",id1="",id2="",id3="";
for( int i=0;i<v1.size();i++){
    occ0=0;
    for( int j=0;j<v1.size();j++){
        if (v1[i].dest==v1[j].dest)
            occ0++;
    }
    if(occ0>occ1){
        occ1=occ0;
    destocc=v1[i].dest;
    id=v1[i].id;}
}
qry1.prepare("select id,dest from vol where dest!='"+destocc+"'" );


qry1.exec();

    while(qry1.next())
    {
        s1.id=qry1.value(0).toInt();
        s1.dest=qry1.value(1).toString();
        v2.push_back(s1);
    }
    for( int i=0;i<v2.size();i++){
        occ01=0;

        for( int j=0;j<v2.size();j++){
            if (v2[i].dest==v2[j].dest)
                occ01++;
        }
        if(occ01>occ2){
            occ2=occ01;
        destocc1=v2[i].dest;
        id1=v2[i].id;}
    }
    qry2.prepare("select id,dest from vol where dest!='"+destocc+"' and dest!='"+destocc1+"' " );


    qry2.exec();

        while(qry2.next())
        {
            s2.id=qry2.value(0).toInt();
            s2.dest=qry2.value(1).toString();

            v3.push_back(s2);
        }
        for(unsigned int i=0;i<v3.size();i++){
            occ02=0;

            for(unsigned int j=0;j<v3.size();j++){
                if (v3[i].dest==v3[j].dest)
                    occ02++;
            }
            if(occ02>occ3){
                occ3=occ02;
            destocc2=v3[i].dest;
            id2=v3[i].id;}
        }
        qry3.prepare("select id,dest from vol where dest!='"+destocc+"' and dest!='"+destocc1+"' and dest!='"+destocc2+"'" );


        qry3.exec();

            while(qry3.next())
            {
                s3.id=qry3.value(0).toInt();
                s3.dest=qry3.value(1).toString();

                v4.push_back(s3);
            }
            for(unsigned int i=0;i<v4.size();i++){
                occ03=0;

                for(unsigned int j=0;j<v4.size();j++){
                    if (v4[i].dest==v4[j].dest)
                        occ03++;
                }
                if(occ03>occ4){
                    occ4=occ03;
                destocc3=v4[i].dest;
                id3=v4[i].id;}
            }

            QBarSet *set0 = new QBarSet("Jan");
            *set0 << occ1<< occ2<< occ3<< occ4;
          QBarSeries *series = new QBarSeries();
            series->append(set0);
           QChart *chart = new QChart();
            chart->addSeries(series);
    chart->setTitle("Les pays les plus populaires");
    QStringList cataloge;
    cataloge<<destocc<<destocc1<<destocc2<<destocc3;
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
    chartView->setMinimumSize(561,331);

    chartView->show();

}

void MainWindow::on_pushButton_ajoutvol_3_clicked()
{
    QSqlQuery qry;

    int a=0,a1=0,a2=0,a3=0,a4=0;
    QString val,passpass=ui->lineEdit_passpass_2->text();
    int Agepass=ui->lineEdit_Agepass_3->text().toInt();
   QDate datepass=ui->dateTimeEdit_datepass_2->date();
    QString nompass=ui->lineEdit_nompass_2->text();
    QString prenompass=ui->lineEdit_prenompass_2->text();
     QString avionpass=ui->lineEdit_avionpass_2->text();
    passager p(passpass,nompass,prenompass,Agepass,datepass,avionpass);
if (ui->checkBox_6->isChecked()){
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                         QObject::tr("acides sont interdits!"),
                         QMessageBox::Ok,
                         QApplication::desktop());
     message.exec();}
if (ui->checkBox_7->isChecked()){
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                         QObject::tr("pistoles sont interdits!"),
                         QMessageBox::Ok,
                         QApplication::desktop());
     message.exec();}
if (ui->checkBox_10->isChecked()){
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                         QObject::tr("couteux sont interdits!"),
                         QMessageBox::Ok,
                         QApplication::desktop());
     message.exec();}
if (ui->checkBox_9->isChecked()){
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                         QObject::tr("Equipement electronique sont interdits!"),
                         QMessageBox::Ok,
                         QApplication::desktop());
     message.exec();}
if (ui->checkBox_8->isChecked()){
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                         QObject::tr("Equipement Medical sont interdits!"),
                         QMessageBox::Ok,
                         QApplication::desktop());
     message.exec();}
else if(ui->checkBox_6->isChecked()==false &&ui->checkBox_7->isChecked()==false && ui->checkBox_10->isChecked()==false && ui->checkBox_9->isChecked()==false &&ui->checkBox_8->isChecked()==false ){
    QFile file(file_path);
    if (!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
}

    QTextStream in(&file);
    while (!in.atEnd())
    {
       QString line = in.readLine();
if (line==ui->lineEdit_passpass_2->text())
a=1;
if (line==ui->dateTimeEdit_datepass_2->dateTime().toString())
a1=1;
if (line==ui->lineEdit_nompass_2->text())
a2=1;
if (line==ui->lineEdit_prenompass_2->text())
a3=1;
if (line==ui->lineEdit_Agepass_3->text())
a4=1;
    }
if(a1==1 && a2==1 &&a==1 &&a3==1 &&a4==1){
    qry.prepare("select num_pass from RECHERCHEE where num_pass='"+ui->lineEdit_passpass_2->text()+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            val=qry.value(0).toString();

        }
}
  if (val!=ui->lineEdit_passpass_2->text())  {
bool test=p.ajouter();
if (test)
{
    statpass();
    ui->tableView_5->setModel(passmp.afficher());

    ui->tableView_5->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}}
  else
  {
      QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                       QObject::tr("cette person est recherchee!"),
                       QMessageBox::Ok,
                       QApplication::desktop());

  }
}
else
{
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                     QObject::tr("Pass sanitaire est invalid!"),
                     QMessageBox::Ok,
                     QApplication::desktop());

}

}
}
void MainWindow::on_pushButton_modvol_3_clicked()
{
    QString passpass=ui->lineEdit_passpass_2->text();
    int Agepass=ui->lineEdit_Agepass_3->text().toInt();
   QDate datepass=ui->dateTimeEdit_datepass_2->date();
    QString nompass=ui->lineEdit_nompass_2->text();
    QString prenompass=ui->lineEdit_prenompass_2->text();
     QString avionpass=ui->lineEdit_avionpass_2->text();
     passager p(passpass,nompass,prenompass,Agepass,datepass,avionpass);
    bool test=p.modifier();
if(test){
    statpass();
    ui->tableView_5->setModel(passmp.afficher());
 ui->tableView_5->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);}
}

void MainWindow::on_pushButton_suppvol_3_clicked()
{
    QModelIndex index=ui->tableView_5->currentIndex();
        int i=index.row();
        QModelIndex in=index.sibling(i,0);
        QString val=ui->tableView_5->model()->data(in).toString();
        bool test=passmp.supprimer(val);
        if (test)
        {
            statpass();

            ui->tableView_5->setModel(passmp.afficher());

            ui->tableView_5->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        }
}

void MainWindow::on_pushButton_impvol_3_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_5->model()->rowCount();
    const int columnCount = ui->tableView_5->model()->columnCount();

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
        if (!ui->tableView_5->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_5->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_5->isColumnHidden(column)) {
                QString data = ui->tableView_5->model()->data(ui->tableView_5->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_tableView_5_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView_5->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager where num_pass='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_passpass_2->setText(qry.value(0).toString());
            ui->lineEdit_Agepass_3->setText(qry.value(3).toString());
            ui->lineEdit_nompass_2->setText(qry.value(1).toString());
            ui->lineEdit_prenompass_2->setText(qry.value(2).toString());
            ui->dateTimeEdit_datepass_2->setDate(qry.value(4).toDate());
            ui->lineEdit_avionpass_2->setText(qry.value(5).toString());
        }
}
}

void MainWindow::on_lineEdit_rechidvol_3_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechidvol_3->text();

    if(text.isEmpty())
    {
        ui->tableView_5->setModel(passmp.afficher());

        ui->tableView_5->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else
    {
        qry->prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager where ( num_pass LIKE'%"+text+"%' OR nom LIKE'%"+text+"%' OR prenom LIKE'%"+text+"%'OR age LIKE'%"+text+"%'OR DATE_EXPR LIKE'%"+text+"%' OR num_serie LIKE'%"+text+"%')");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_5->setModel(modal);
    }
}

void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString type=ui->comboBox_3->currentText();
    if (type=="Par defaut"){
        qry->prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
                      modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
        ui->tableView_5->setModel(modal);}
        else if (type=="Num de passport"){
            qry->prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager order by num_pass");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de passport"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de exp"));
               modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Num d'avion"));

            ui->tableView_5->setModel(modal);


        }
        else if (type=="Nom"){
            qry->prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager order by nom");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de passport"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de exp"));
               modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Num d'avion"));

            ui->tableView_5->setModel(modal);


        }
        else if (type=="Prenom"){
            qry->prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager order by prenom");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de passport"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de exp"));
               modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Num d'avion"));

            ui->tableView_5->setModel(modal);


        }
    else if (type=="Age"){
        qry->prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager order by age");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de passport"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
           modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de exp"));
           modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Num d'avion"));

        ui->tableView_5->setModel(modal);


    }

    else if (type=="Date"){
        qry->prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager order by DATE_EXPR");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de passport"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
           modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de exp"));
           modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Num d'avion"));

        ui->tableView_5->setModel(modal);


    }
    else if (type=="Num d'avion"){
        qry->prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager order by num_serie");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de passport"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
           modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de exp"));
           modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Num d'avion"));

        ui->tableView_5->setModel(modal);


    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this,"open file");
    QFile file(file_name);
    file_path=file_name;
    if (!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"..","File not open");

    }

    file.close();
}
void MainWindow::statpass(){

    vector<statt> v1,v11,v2,v3,v4;
    QSqlQuery qry,qry1,qry2,qry3;
statt s0,s1,s2,s3;

    qry.prepare("select NUM_PASS,age from passager" );


    qry.exec();

        while(qry.next())
        {
            s0.id=qry.value(0).toString();
            s0.dest=qry.value(1).toString();
            v1.push_back(s0);
        }
        int occ0=0,occ01=0,occ02=0,occ03=0,occ1=0,occ2=0,occ3=0,occ4=0;
        QString destocc="",destocc1="",destocc2="",destocc3="",id="",id1="",id2="",id3="";
for( int i=0;i<v1.size();i++){
    occ0=0;
    for( int j=0;j<v1.size();j++){
        if (v1[i].dest==v1[j].dest)
            occ0++;
    }
    if(occ0>occ1){
        occ1=occ0;
    destocc=v1[i].dest;
    id=v1[i].id;}
}
qry1.prepare("select NUM_PASS,age from passager where age!='"+destocc+"'" );


qry1.exec();

    while(qry1.next())
    {
        s1.id=qry1.value(0).toInt();
        s1.dest=qry1.value(1).toString();
        v2.push_back(s1);
    }
    for( int i=0;i<v2.size();i++){
        occ01=0;

        for( int j=0;j<v2.size();j++){
            if (v2[i].dest==v2[j].dest)
                occ01++;
        }
        if(occ01>occ2){
            occ2=occ01;
        destocc1=v2[i].dest;
        id1=v2[i].id;}
    }
    qry2.prepare("select NUM_PASS,age from passager where age!='"+destocc+"' and age!='"+destocc1+"' " );


    qry2.exec();

        while(qry2.next())
        {
            s2.id=qry2.value(0).toInt();
            s2.dest=qry2.value(1).toString();

            v3.push_back(s2);
        }
        for(unsigned int i=0;i<v3.size();i++){
            occ02=0;

            for(unsigned int j=0;j<v3.size();j++){
                if (v3[i].dest==v3[j].dest)
                    occ02++;
            }
            if(occ02>occ3){
                occ3=occ02;
            destocc2=v3[i].dest;
            id2=v3[i].id;}
        }
        qry3.prepare("select NUM_PASS,age from passager where age!='"+destocc+"' and age!='"+destocc1+"' and age!='"+destocc2+"'" );


        qry3.exec();

            while(qry3.next())
            {
                s3.id=qry3.value(0).toInt();
                s3.dest=qry3.value(1).toString();

                v4.push_back(s3);
            }
            for(unsigned int i=0;i<v4.size();i++){
                occ03=0;

                for(unsigned int j=0;j<v4.size();j++){
                    if (v4[i].dest==v4[j].dest)
                        occ03++;
                }
                if(occ03>occ4){
                    occ4=occ03;
                destocc3=v4[i].dest;
                id3=v4[i].id;}
            }

            QBarSet *set0 = new QBarSet("Jan");
            *set0 << occ1<< occ2<< occ3<< occ4;
          QBarSeries *series = new QBarSeries();
            series->append(set0);
           QChart *chart = new QChart();
            chart->addSeries(series);
    chart->setTitle("Les ages les plus populaires");
    QStringList cataloge;
    cataloge<<destocc<<destocc1<<destocc2<<destocc3;
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
    chartView = new QChartView(chart,ui->chartview_5);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(801,311);

    chartView->show();

}

void MainWindow::on_pushButton_ajoutvol_2_clicked()
{
    QString num_serie=ui->lineEdit_numav->text();
    int poids=ui->lineEdit_poidsav->text().toInt();
    QString etat=ui->comboBox_etatav->currentText();
    int num_pilote=ui->lineEdit_pisteav->text().toInt();
   avion a(num_serie,poids,etat,num_pilote);

    bool test=a.ajouter();
    if (test)
    {
        ui->tableView_3->setModel(avmp.afficher());

        ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        statavion();

    }



}

void MainWindow::on_pushButton_suppvol_2_clicked()
{
    QModelIndex index=ui->tableView_3->currentIndex();
        int i=index.row();
        QModelIndex in=index.sibling(i,0);
        QString val=ui->tableView_3->model()->data(in).toString();
        bool test=avmp.supprimer(val);
        if (test)
        {

            ui->tableView_3->setModel(avmp.afficher());

            ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
            statavion();

        }
}

void MainWindow::on_pushButton_modvol_2_clicked()
{
    QString num_serie=ui->lineEdit_numav->text();
    int poids=ui->lineEdit_poidsav->text().toInt();
    QString etat=ui->comboBox_etatav->currentText();
    int num_pilote=ui->lineEdit_pisteav->text().toInt();
    avion a(num_serie,poids,etat,num_pilote);
    bool test=a.modifier();
if(test){
    ui->tableView_3->setModel(avmp.afficher());

    ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    statavion();
} }

void MainWindow::on_tableView_3_clicked(const QModelIndex &index)
{
    int i;
    i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView_3->model()->data(in).toString();


        QSqlQuery qry;
        qry.prepare("select num_serie,POIDS_BAGAGE,ETAT,NUM_PISTE from avion where num_serie='"+val+"' " );


        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit_numav->setText(qry.value(0).toString());
                ui->lineEdit_pisteav->setText(qry.value(3).toString());
                ui->lineEdit_poidsav->setText(qry.value(1).toString());
                ui->comboBox_etatav->setCurrentText(qry.value(2).toString());

            }
    }
}

void MainWindow::on_pushButton_impvol_2_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_3->model()->rowCount();
    const int columnCount = ui->tableView_3->model()->columnCount();

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
        if (!ui->tableView_3->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_3->isColumnHidden(column)) {
                QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_lineEdit_rechidvol_2_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechidvol_2->text();

    if(text.isEmpty())
    {
        ui->tableView_3->setModel(avmp.afficher());

        ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else
    {
        qry->prepare("select num_serie,POIDS_BAGAGE,ETAT,NUM_PISTE from avion where ( num_serie LIKE'%"+text+"%' OR POIDS_BAGAGE LIKE'%"+text+"%' OR ETAT LIKE'%"+text+"%'OR NUM_PISTE LIKE'%"+text+"%')");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_3->setModel(modal);
    }
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString type=ui->comboBox_2->currentText();
    if (type=="Par defaut"){
        qry->prepare("select num_serie,POIDS_BAGAGE,ETAT,NUM_PISTE from avion");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num_avion"));
        modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Poids_bagage"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Num_piste"));
        ui->tableView_3->setModel(modal);}
        else if (type=="Num Serie"){
            qry->prepare("select num_serie,POIDS_BAGAGE,ETAT,NUM_PISTE from avion order by num_serie");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num_avion"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Poids_bagage"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Num_piste"));

            ui->tableView_3->setModel(modal);


        }
        else if (type=="Poids de Bagage"){
            qry->prepare("select num_serie,POIDS_BAGAGE,ETAT,NUM_PISTE from avion order by POIDS_BAGAGE");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num_avion"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Poids_bagage"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Num_piste"));

            ui->tableView_3->setModel(modal);


        }
        else if (type=="Etat"){
            qry->prepare("select num_serie,POIDS_BAGAGE,ETAT,NUM_PISTE from avion order by ETAT");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num_avion"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Poids_bagage"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Num_piste"));

            ui->tableView_3->setModel(modal);


        }
    else if (type=="Num de Piste"){
        qry->prepare("select num_serie,POIDS_BAGAGE,ETAT,NUM_PISTE from avion order by NUM_PISTE");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num_avion"));
        modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Poids_bagage"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Etat"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Num_piste"));

        ui->tableView_3->setModel(modal);


    }

}
void MainWindow::statavion(){
    QSqlQuery qry,qry1;
    QString destocc1="en panne",destocc="normal";
statt s0,s1,s2,s3;
int count0=0,count1=0;
    qry.prepare("select count(*) from avion where etat='"+destocc+"'" );


    qry.exec();

    while(qry.next())
        {

        count0=qry.value(0).toString().toInt() ;
        }

qry1.prepare("select count(*) from avion where etat='"+destocc1+"'" );


qry1.exec();

while(qry1.next())
    {

    count1=qry1.value(0).toString().toInt() ;
    }


QPieSeries *series = new QPieSeries();
series->append("avion en panne",count0);
series->append("avion normal",count1);
QPieSlice *slice0 = series->slices().at(0);
slice0->setLabelVisible();
QPieSlice *slice1 = series->slices().at(1);
slice1->setExploded();
slice1->setLabelVisible();
slice1->setPen(QPen(Qt::darkGreen, 2));
slice1->setBrush(Qt::green);
QChart *chart = new QChart();
 chart->addSeries(series);
 chart->setTitle("Les etats de avions");

    chart->setAnimationOptions(QChart::AllAnimations);

    chart->legend()->hide();

    chartView = new QChartView(chart,ui->chartview_6);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(781,291);

    chartView->show();



}

void MainWindow::on_pushButton_ajoutvol_5_clicked()
{
    QString idpilote=ui->lineEdit_idpilote_2->text();
    int salairepilote=ui->lineEdit_salairepilote_2->text().toInt();
    int periodepilote=ui->lineEdit_periodepilote_2->text().toInt();

    QString nompilote=ui->lineEdit_nompilote_2->text();
    QString prenompilote=ui->lineEdit_prenompilote_2->text();
     QString mdppilote=ui->lineEdit_mdppilote_2->text();
    pilote P(idpilote,nompilote,prenompilote,salairepilote,periodepilote,mdppilote);

    bool test=P.ajouter();
    if (test)
    {
        statpilote();

        ui->tableView_7->setModel(pilmp.afficher());

        ui->tableView_7->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
}

void MainWindow::on_pushButton_suppvol_5_clicked()
{
    QModelIndex index=ui->tableView_7->currentIndex();
        int i=index.row();
        QModelIndex in=index.sibling(i,0);
        QString val=ui->tableView_7->model()->data(in).toString();
        bool test=pilmp.supprimer(val);
        if (test)
        {
statpilote();
            ui->tableView_7->setModel(pilmp.afficher());

            ui->tableView_7->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        }
}

void MainWindow::on_pushButton_modvol_5_clicked()
{
    QString idpilote=ui->lineEdit_idpilote_2->text();
    int salairepilote=ui->lineEdit_salairepilote_2->text().toInt();
    int periodepilote=ui->lineEdit_periodepilote_2->text().toInt();

    QString nompilote=ui->lineEdit_nompilote_2->text();
    QString prenompilote=ui->lineEdit_prenompilote_2->text();
    QString mdppilote=ui->lineEdit_mdppilote_2->text();
   pilote P(idpilote,nompilote,prenompilote,salairepilote,periodepilote,mdppilote);
    bool test=P.modifier();
if(test)
{

    ui->tableView_7->setModel(pilmp.afficher());

    ui->tableView_7->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}}

void MainWindow::on_lineEdit_rechidvol_5_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechidvol_5->text();

    if(text.isEmpty())
    {
        ui->tableView_7->setModel(pilmp.afficher());

        ui->tableView_7->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else
    {
        qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote where ( id_pilote LIKE'%"+text+"%' OR nom LIKE'%"+text+"%' OR prenom LIKE'%"+text+"%'OR salaire LIKE'%"+text+"%' OR periode LIKE'%"+text+"%')");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_7->setModel(modal);
    }
}

void MainWindow::on_tableView_7_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView_7->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select id_pilote,nom,prenom,salaire,periode from pilote where id_pilote='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_idpilote_2->setText(qry.value(0).toString());
            ui->lineEdit_salairepilote_2->setText(qry.value(3).toString());
            ui->lineEdit_nompilote_2->setText(qry.value(1).toString());
            ui->lineEdit_prenompilote_2->setText(qry.value(2).toString());
                       ui->lineEdit_periodepilote_2->setText(qry.value(4).toString());
                       ui->lineEdit_mdppilote_2->setText("");
        }
}
}

void MainWindow::on_pushButton_impvol_5_clicked()
{

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_7->model()->rowCount();
    const int columnCount = ui->tableView_7->model()->columnCount();

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
        if (!ui->tableView_7->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_7->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_7->isColumnHidden(column)) {
                QString data = ui->tableView_7->model()->data(ui->tableView_7->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_comboBox_5_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString type=ui->comboBox_5->currentText();
    if (type=="Par defaut"){
        qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifant de pilote"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Salaire"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
           modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Periode"));
        ui->tableView_7->setModel(modal);}
        else if (type=="Identifiant de pilote"){
            qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote order by id_pilote");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifant de pilote"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Salaire"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Periode"));

            ui->tableView_7->setModel(modal);


        }
        else if (type=="Periode"){
            qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote order by periode");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifant de pilote"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Salaire"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Periode"));

            ui->tableView_7->setModel(modal);


        }
        else if (type=="Salaire"){
            qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote order by salaire");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifant de pilote"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Salaire"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Periode"));
            ui->tableView_7->setModel(modal);


        }
    else if (type=="Prenom"){
        qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote order by prenom");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifant de pilote"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Salaire"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
           modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Periode"));

        ui->tableView_7->setModel(modal);


    }
    else if (type=="Nom"){
        qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote order by nom");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifant de pilote"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Salaire"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
           modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Periode"));

        ui->tableView_7->setModel(modal);


    }
}
void MainWindow::statpilote(){


    vector<statt> v1,v11,v2,v3,v4;
    QSqlQuery qry,qry1,qry2,qry3;
statt s0,s1,s2,s3;

    qry.prepare("select ID_PILOTE,PERIODE from pilote" );


    qry.exec();

        while(qry.next())
        {
            s0.id=qry.value(0).toString();
            s0.dest=qry.value(1).toString();
            v1.push_back(s0);
        }
        int occ0=0,occ01=0,occ02=0,occ03=0,occ1=0,occ2=0,occ3=0,occ4=0;
        QString destocc="",destocc1="",destocc2="",destocc3="",id="",id1="",id2="",id3="";
for( int i=0;i<v1.size();i++){
    occ0=0;
    for( int j=0;j<v1.size();j++){
        if (v1[i].dest==v1[j].dest)
            occ0++;
    }
    if(occ0>occ1){
        occ1=occ0;
    destocc=v1[i].dest;
    id=v1[i].id;}
}
qry1.prepare("select ID_PILOTE,PERIODE from pilote where PERIODE!='"+destocc+"'" );


qry1.exec();

    while(qry1.next())
    {
        s1.id=qry1.value(0).toInt();
        s1.dest=qry1.value(1).toString();
        v2.push_back(s1);
    }
    for( int i=0;i<v2.size();i++){
        occ01=0;

        for( int j=0;j<v2.size();j++){
            if (v2[i].dest==v2[j].dest)
                occ01++;
        }
        if(occ01>occ2){
            occ2=occ01;
        destocc1=v2[i].dest;
        id1=v2[i].id;}
    }
    qry2.prepare("select ID_PILOTE,PERIODE from pilote where PERIODE!='"+destocc+"' and PERIODE!='"+destocc1+"' " );


    qry2.exec();

        while(qry2.next())
        {
            s2.id=qry2.value(0).toInt();
            s2.dest=qry2.value(1).toString();

            v3.push_back(s2);
        }
        for(unsigned int i=0;i<v3.size();i++){
            occ02=0;

            for(unsigned int j=0;j<v3.size();j++){
                if (v3[i].dest==v3[j].dest)
                    occ02++;
            }
            if(occ02>occ3){
                occ3=occ02;
            destocc2=v3[i].dest;
            id2=v3[i].id;}
        }
        qry3.prepare("select ID_PILOTE,PERIODE from pilote where PERIODE!='"+destocc+"' and PERIODE!='"+destocc1+"' and PERIODE!='"+destocc2+"'" );


        qry3.exec();

            while(qry3.next())
            {
                s3.id=qry3.value(0).toInt();
                s3.dest=qry3.value(1).toString();

                v4.push_back(s3);
            }
            for(unsigned int i=0;i<v4.size();i++){
                occ03=0;

                for(unsigned int j=0;j<v4.size();j++){
                    if (v4[i].dest==v4[j].dest)
                        occ03++;
                }
                if(occ03>occ4){
                    occ4=occ03;
                destocc3=v4[i].dest;
                id3=v4[i].id;}
            }

            QBarSet *set0 = new QBarSet("Jan");
            *set0 << occ1<< occ2<< occ3<< occ4;
          QBarSeries *series = new QBarSeries();
            series->append(set0);
           QChart *chart = new QChart();
            chart->addSeries(series);
    chart->setTitle("Les differents horaires travail de pilotes");
    QStringList cataloge;
    cataloge<<destocc<<destocc1<<destocc2<<destocc3;
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
    chartView = new QChartView(chart,ui->chartview_7);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(801,311);

    chartView->show();


}

void MainWindow::on_pushButton_ajoutvol_6_clicked()
{
    QString numres=ui->lineEdit_numres->text();
    int idvolres=ui->lineEdit_idvolres->text().toInt();

    QString numpassreser=ui->lineEdit_numpassreser->text();
    QString classe=ui->comboBox_classeres->currentText();
    int prixreser=ui->lineEdit_prixreser->text().toInt();
    reservation R(numres,idvolres,numpassreser,classe,prixreser);

    bool test=R.ajouter();
    if (test)
    {
        statreservation();

        ui->tableView_9->setModel(resermp.afficher());

        ui->tableView_9->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }

}

void MainWindow::on_pushButton_suppvol_6_clicked()
{
    QModelIndex index=ui->tableView_9->currentIndex();
        int i=index.row();
        QModelIndex in=index.sibling(i,0);
        QString val=ui->tableView_9->model()->data(in).toString();
        bool test=resermp.supprimer(val);
        if (test)
        {
            statreservation();

            ui->tableView_9->setModel(resermp.afficher());

            ui->tableView_9->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        }

}

void MainWindow::on_pushButton_modvol_6_clicked()
{
    QString numres=ui->lineEdit_numres->text();
    int idvolres=ui->lineEdit_idvolres->text().toInt();

    QString numpassreser=ui->lineEdit_numpassreser->text();
    QString classe=ui->comboBox_classeres->currentText();
    int prixreser=ui->lineEdit_prixreser->text().toInt();

    reservation R(numres,idvolres,numpassreser,classe,prixreser);
    bool test=R.modifier();
if(test)
    {
    statreservation();
    ui->tableView_9->setModel(resermp.afficher());

    ui->tableView_9->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
}
void MainWindow::on_tableView_9_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView_9->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select NUM_RESER,NUM_PASS,ID,CLASSE,PRIX from reservation where NUM_RESER='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_numres->setText(qry.value(0).toString());
            ui->lineEdit_idvolres->setText(qry.value(2).toString());
            ui->comboBox_classeres->setCurrentText(qry.value(3).toString());
            ui->lineEdit_numpassreser->setText(qry.value(1).toString());
            ui->lineEdit_prixreser->setText(qry.value(4).toString());


        }
}
    updateQRImage();

}

void MainWindow::on_lineEdit_rechidvol_6_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechidvol_6->text();

    if(text.isEmpty())
    {
        ui->tableView_9->setModel(resermp.afficher());

        ui->tableView_9->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else
    {
        qry->prepare("select NUM_RESER,NUM_PASS,ID,CLASSE,PRIX from reservation where  ( NUM_RESER LIKE'%"+text+"%' OR NUM_PASS LIKE'%"+text+"%' OR ID LIKE'%"+text+"%'OR CLASSE LIKE'%"+text+"%' OR PRIX LIKE'%"+text+"%')");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_9->setModel(modal);
    }
}

void MainWindow::on_pushButton_impvol_6_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_9->model()->rowCount();
    const int columnCount = ui->tableView_9->model()->columnCount();

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
        if (!ui->tableView_9->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_9->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_9->isColumnHidden(column)) {
                QString data = ui->tableView_9->model()->data(ui->tableView_9->model()->index(row, column)).toString().simplified();
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


void MainWindow::on_comboBox_6_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString type=ui->comboBox_6->currentText();
    if (type=="Par defaut"){
        qry->prepare("select NUM_RESER,NUM_PASS,ID,CLASSE,PRIX from reservation");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de reservation"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Num de passport"));
        modal->setHeaderData(1,Qt::Horizontal,QObject::tr("ID vol"));
         modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Classe"));
           modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));


        ui->tableView_9->setModel(modal);}
        else if (type=="Num de reservation"){
            qry->prepare("select NUM_RESER,NUM_PASS,ID,CLASSE,PRIX from reservation order by NUM_RESER");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de reservation"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Num de passport"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("ID vol"));
             modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Classe"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));



            ui->tableView_9->setModel(modal);


        }
        else if (type=="Num de passport"){
            qry->prepare("select NUM_RESER,NUM_PASS,ID,CLASSE,PRIX from reservation order by NUM_PASS");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de reservation"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Num de passport"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("ID vol"));
             modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Classe"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));


            ui->tableView_9->setModel(modal);


        }
        else if (type=="Identifiant de vol"){
            qry->prepare("select NUM_RESER,NUM_PASS,ID,CLASSE,PRIX from reservation order by ID");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de reservation"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Num de passport"));
            modal->setHeaderData(1,Qt::Horizontal,QObject::tr("ID vol"));
             modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Classe"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));


            ui->tableView_9->setModel(modal);


        }
    else if (type=="Classe"){
        qry->prepare("select NUM_RESER,NUM_PASS,ID,CLASSE,PRIX from reservation order by CLASSE");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de reservation"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Num de passport"));
        modal->setHeaderData(1,Qt::Horizontal,QObject::tr("ID vol"));
         modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Classe"));
           modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));


        ui->tableView_9->setModel(modal);


    }
    else if (type=="Prix"){
        qry->prepare("select NUM_RESER,NUM_PASS,ID,CLASSE,PRIX from reservation order by Prix");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de reservation"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Num de passport"));
        modal->setHeaderData(1,Qt::Horizontal,QObject::tr("ID vol"));
         modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Classe"));
           modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));


        ui->tableView_9->setModel(modal);


    }
}
void MainWindow::updateQRImage()
{

//int scale=5;
    int levelIndex = 1;
    int versionIndex = 0;
    bool bExtent = true;
    int maskIndex = -1;
    QSqlQuery*qry=new QSqlQuery();
QString d;
    qry->prepare("select datev from vol where id='"+ui->lineEdit_idvolres->text()+"'");
    qry->exec();
    while(qry->next())
    {




     d=qry->value(0).toString();}
    QString encodeString = "num res:"+ui->lineEdit_numres->text()+"\n num pass :"+ui->lineEdit_numpassreser->text()+"\n date :"+d+"\n num vol :"+ui->lineEdit_idvolres->text()+"\n type de classe :"+ui->comboBox_classeres->currentText()+"\n prix :"+ui->lineEdit_prixreser->text();

    successfulEncoding = qrEncode.EncodeData( levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data() );
    if ( !successfulEncoding )
    {
        ui->qrcode->clear();
        ui->qrcode->setText( tr("QR Code...") );

        ui->save->setEnabled( successfulEncoding );
        return;
    }

    int qrImageSize = qrEncode.m_nSymbleSize;


    encodeImageSize = qrImageSize + ( QR_MARGIN * 2 );
    QImage encodeImage( encodeImageSize, encodeImageSize, QImage::Format_Mono );
    encodeImage.fill( 1 );


    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncode.m_byModuleData[i][j] )
                encodeImage.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    ui->qrcode->setPixmap( QPixmap::fromImage( encodeImage ) );
ui->qrcode->setScaledContents(true);


    ui->save->setEnabled( successfulEncoding );
}
//void MainWindow::on_save_clicked()
//{
//    const QString & path = QFileDialog::getSaveFileName( this, QString::null, "qrcodevoyage", saveFormats() );
//    if ( path.isNull() )
//        return;

//    ui->qrcode->pixmap()->save( path );
//}



void MainWindow::on_calendrier_clicked(const QDate &date)
{
    ui->plainTextEdit->setPlainText("");
    QSqlQuery*qry=new QSqlQuery();
    QSqlQuery*qry1=new QSqlQuery();
QString d,d1;
QString x1,x=ui->calendrier->selectedDate().toString();

    qry->prepare("select id from vol where datev=:date");
    qry->bindValue(":date",date);
    qry->exec();
    while(qry->next())
    {




     d=qry->value(0).toString();

     qry1->prepare("select NUM_RESER,NUM_PASS,ID,CLASSE,PRIX from reservation where id='"+d+"'");
     qry1->exec();
     while(qry1->next())
     {
         x1= "num res:"+qry1->value(0).toString()+"\n num pass :"+qry1->value(1).toString()+"\n date :"+x+"\n num vol :"+qry1->value(2).toString()+"\n type de classe :"+qry1->value(3).toString()+"\n prix :"+qry1->value(4).toString()+"\n";
         ui->plainTextEdit->appendPlainText(x1);

    }
}
}
void MainWindow::statreservation(){

    QSqlQuery qry,qry1,qry2,qry3;
    QString destocc1="Classe economique",destocc="Classe economique premium",destocc2="Classe affaires",destocc3="Premiere classe";
statt s0,s1,s2,s3;
int count0=0,count1=0,count2=0,count3=0;
    qry.prepare("select count(*) from reservation where classe='"+destocc1+"'" );


    qry.exec();

    while(qry.next())
        {

        count0=qry.value(0).toString().toInt() ;
        }

qry1.prepare("select count(*) from reservation where classe='"+destocc+"'" );


qry1.exec();

while(qry1.next())
    {

    count1=qry1.value(0).toString().toInt() ;
    }
qry2.prepare("select count(*) from reservation where classe='"+destocc2+"'" );


qry2.exec();

while(qry2.next())
    {

    count2=qry2.value(0).toString().toInt() ;
    }

qry3.prepare("select count(*) from reservation where classe='"+destocc3+"'" );


qry3.exec();

while(qry3.next())
{

count3=qry3.value(0).toString().toInt() ;
}

QPieSeries *series = new QPieSeries();
series->append("Classe economique",count0);
series->append("Classe economique premium",count1);
series->append("Classe affaires",count2);
series->append("Premiere classe",count3);
QPieSlice *slice0 = series->slices().at(0);
slice0->setLabelVisible();
QPieSlice *slice1 = series->slices().at(1);
QPieSlice *slice2 = series->slices().at(2);
slice2->setLabelVisible();
slice2->setExploded();
slice2->setPen(QPen(Qt::darkBlue, 2));
slice2->setBrush(Qt::blue);
QPieSlice *slice3 = series->slices().at(3);
slice3->setLabelVisible();
slice3->setExploded();
slice3->setPen(QPen(Qt::darkGray, 2));
slice3->setBrush(Qt::gray);
slice1->setExploded();
slice1->setLabelVisible();
slice1->setPen(QPen(Qt::darkGreen, 2));
slice1->setBrush(Qt::green);
QChart *chart = new QChart();
 chart->addSeries(series);
 chart->setTitle("Les classe de vols");

    chart->setAnimationOptions(QChart::AllAnimations);

    chart->legend()->hide();

    chartView = new QChartView(chart,ui->chartview_8);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(401,311);

    chartView->show();







}

void MainWindow::on_pushButton_ajoutpiste_clicked()
{
    int numpiste=ui->lineEdit_numpiste->text().toInt();
    int prixpiste=ui->lineEdit_prixpiste->text().toInt();
    int largeurpiste=ui->lineEdit_largeurpiste->text().toInt();
    piste P(numpiste,prixpiste,largeurpiste);

    bool test=P.ajouter();
    if (test)
    {
        statpiste();

        ui->tableView_8->setModel(pismp.afficher());

        ui->tableView_8->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
}

void MainWindow::on_pushButton_supppiste_clicked()
{
    QModelIndex index=ui->tableView_8->currentIndex();
        int i=index.row();
        QModelIndex in=index.sibling(i,0);
        QString val=ui->tableView_8->model()->data(in).toString();
        bool test=pismp.supprimer(val);
        if (test)
        {
            statpiste();

            ui->tableView_8->setModel(pismp.afficher());

            ui->tableView_8->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        }
}

void MainWindow::on_pushButton_modpiste_clicked()
{
    int numpiste=ui->lineEdit_numpiste->text().toInt();
    int prixpiste=ui->lineEdit_prixpiste->text().toInt();
    int largeurpiste=ui->lineEdit_largeurpiste->text().toInt();
    piste P(numpiste,prixpiste,largeurpiste);
    bool test=P.modifier();
if(test)
{
statpiste();
    ui->tableView_8->setModel(pismp.afficher());

    ui->tableView_8->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
}

void MainWindow::on_tableView_8_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView_8->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select NUM_PISTE,PRIX_LOCATION,LARGEUR_PISTE from piste where NUM_PISTE='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_numpiste->setText(qry.value(0).toString());
            ui->lineEdit_prixpiste->setText(qry.value(1).toString());
            ui->lineEdit_largeurpiste->setText(qry.value(2).toString());

        }
}
}

void MainWindow::on_lineEdit_rechpiste_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechpiste->text();

    if(text.isEmpty())
    {

        ui->tableView_8->setModel(pismp.afficher());

        ui->tableView_8->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else
    {
        qry->prepare("select NUM_PISTE,PRIX_LOCATION,LARGEUR_PISTE from piste where ( NUM_PISTE LIKE'%"+text+"%' OR PRIX_LOCATION LIKE'%"+text+"%' OR LARGEUR_PISTE LIKE'%"+text+"%')");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_8->setModel(modal);
    }
}

void MainWindow::on_pushButton_imppiste_clicked()
{

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_8->model()->rowCount();
    const int columnCount = ui->tableView_8->model()->columnCount();

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
        if (!ui->tableView_8->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_8->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_8->isColumnHidden(column)) {
                QString data = ui->tableView_8->model()->data(ui->tableView_8->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_comboBox_7_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString type=ui->comboBox_7->currentText();
    if (type=="Par defaut"){
        qry->prepare("select NUM_PISTE,PRIX_LOCATION,LARGEUR_PISTE from piste");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de piste"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Largeur de piste"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Prix de location"));
        ui->tableView_8->setModel(modal);}
        else if (type=="Num de piste"){
            qry->prepare("select NUM_PISTE,PRIX_LOCATION,LARGEUR_PISTE from piste order by NUM_PISTE");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de piste"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Largeur de piste"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Prix de location"));

            ui->tableView_8->setModel(modal);


        }
        else if (type=="Largeur de Piste"){
            qry->prepare("select NUM_PISTE,PRIX_LOCATION,LARGEUR_PISTE from piste order by LARGEUR_PISTE");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de piste"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Largeur de piste"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Prix de location"));

            ui->tableView_8->setModel(modal);


        }
        else if (type=="Prix de location"){
            qry->prepare("select NUM_PISTE,PRIX_LOCATION,LARGEUR_PISTE from piste order by PRIX_LOCATION");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Num de piste"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Largeur de piste"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Prix de location"));

            ui->tableView_8->setModel(modal);


        }
}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("ahmed.ghoul@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("ahmed.ghoul@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("ahmed.ghoul@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

void MainWindow::on_sendBtn_clicked()
{
    sendMail();
}

void MainWindow::on_browseBtn_clicked()
{
    browse();
}
void MainWindow::statpiste(){

    vector<statt> v1,v11,v2,v3,v4;
    QSqlQuery qry,qry1,qry2,qry3;
statt s0,s1,s2,s3;

    qry.prepare("select NUM_PISTE,PRIX_LOCATION from piste" );


    qry.exec();

        while(qry.next())
        {
            s0.id=qry.value(0).toString();
            s0.dest=qry.value(1).toString();
            v1.push_back(s0);
        }
        int occ0=0,occ01=0,occ02=0,occ03=0,occ1=0,occ2=0,occ3=0,occ4=0;
        QString destocc="",destocc1="",destocc2="",destocc3="",id="",id1="",id2="",id3="";
for( int i=0;i<v1.size();i++){
    occ0=0;
    for( int j=0;j<v1.size();j++){
        if (v1[i].dest==v1[j].dest)
            occ0++;
    }
    if(occ0>occ1){
        occ1=occ0;
    destocc=v1[i].dest;
    id=v1[i].id;}
}
qry1.prepare("select NUM_PISTE,PRIX_LOCATION from piste where PRIX_LOCATION!='"+destocc+"'" );


qry1.exec();

    while(qry1.next())
    {
        s1.id=qry1.value(0).toInt();
        s1.dest=qry1.value(1).toString();
        v2.push_back(s1);
    }
    for( int i=0;i<v2.size();i++){
        occ01=0;

        for( int j=0;j<v2.size();j++){
            if (v2[i].dest==v2[j].dest)
                occ01++;
        }
        if(occ01>occ2){
            occ2=occ01;
        destocc1=v2[i].dest;
        id1=v2[i].id;}
    }
    qry2.prepare("select NUM_PISTE,PRIX_LOCATION from piste where PRIX_LOCATION!='"+destocc+"' and PRIX_LOCATION!='"+destocc1+"' " );


    qry2.exec();

        while(qry2.next())
        {
            s2.id=qry2.value(0).toInt();
            s2.dest=qry2.value(1).toString();

            v3.push_back(s2);
        }
        for(unsigned int i=0;i<v3.size();i++){
            occ02=0;

            for(unsigned int j=0;j<v3.size();j++){
                if (v3[i].dest==v3[j].dest)
                    occ02++;
            }
            if(occ02>occ3){
                occ3=occ02;
            destocc2=v3[i].dest;
            id2=v3[i].id;}
        }
        qry3.prepare("select NUM_PISTE,PRIX_LOCATION from piste where PRIX_LOCATION!='"+destocc+"' and PRIX_LOCATION!='"+destocc1+"' and PRIX_LOCATION!='"+destocc2+"'" );


        qry3.exec();

            while(qry3.next())
            {
                s3.id=qry3.value(0).toInt();
                s3.dest=qry3.value(1).toString();

                v4.push_back(s3);
            }
            for(unsigned int i=0;i<v4.size();i++){
                occ03=0;

                for(unsigned int j=0;j<v4.size();j++){
                    if (v4[i].dest==v4[j].dest)
                        occ03++;
                }
                if(occ03>occ4){
                    occ4=occ03;
                destocc3=v4[i].dest;
                id3=v4[i].id;}
            }

            QBarSet *set0 = new QBarSet("Jan");
            *set0 << occ1<< occ2<< occ3<< occ4;
          QBarSeries *series = new QBarSeries();
            series->append(set0);
           QChart *chart = new QChart();
            chart->addSeries(series);
    chart->setTitle("Les differents prix de pistes");
    QStringList cataloge;
    cataloge<<destocc<<destocc1<<destocc2<<destocc3;
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
    chartView = new QChartView(chart,ui->chartview_9);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(581,351);

    chartView->show();


}
void MainWindow::setCamera(const QCameraInfo &cameraInfo)
{
    Camera = new QCamera(cameraInfo);
    imageCapture = new QCameraImageCapture(Camera);
    Camera->setViewfinder(ui->viewfinder_3);
    connect(imageCapture, &QCameraImageCapture::readyForCaptureChanged, this, &MainWindow::readyForCapture);
    Camera->start();
}


void MainWindow::readyForCapture(bool ready)
{
    ui->takeImageButton->setEnabled(ready);
}
void MainWindow::on_takeImageButton_clicked()
{
    isCapturingImage = true;
    imageCapture->capture();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString text,space="";
    QString msg=ui->input->text();
    ui->output->appendPlainText(space);
    ui->output->appendPlainText(msg);
    QSqlQuery qry,query;
     if     (msg[0]!="$")   {
    qry.prepare("select * from chatbot where word='"+msg+"' " );
     if(qry.exec())
     {
         if(qry.next()==false){
             ui->output->appendPlainText( "do you wanna add new word? write my answer with $ in first");
ui->label_16->setText(msg);}
         else

           ui->output->appendPlainText( "\n"+qry.value(1).toString());




     }}
    else if (msg[0]=="$"){
         QString msg1=msg.mid(1,msg.length()-1);
         query.prepare("insert into chatbot (WORD,REP)""values(:WORD,:REP)");
         query.bindValue(":WORD", ui->label_16->text());
         query.bindValue(":REP", msg1);
         query.exec();
         ui->output->appendPlainText( "\n New word for me");

     }
}
void MainWindow::statpilotepie(){

    vector<statt> v1,v11,v2,v3,v4;
    QSqlQuery qry,qry1,qry2,qry3;
statt s0,s1,s2,s3;

    qry.prepare("select ID_PILOTE,SALAIRE from pilote" );


    qry.exec();

        while(qry.next())
        {
            s0.id=qry.value(0).toString();
            s0.dest=qry.value(1).toString();
            v1.push_back(s0);
        }
        int occ0=0,occ01=0,occ02=0,occ03=0,occ1=0,occ2=0,occ3=0,occ4=0;
        QString destocc="",destocc1="",destocc2="",destocc3="",id="",id1="",id2="",id3="";
for( int i=0;i<v1.size();i++){
    occ0=0;
    for( int j=0;j<v1.size();j++){
        if (v1[i].dest==v1[j].dest)
            occ0++;
    }
    if(occ0>occ1){
        occ1=occ0;
    destocc=v1[i].dest;
    id=v1[i].id;}
}
qry1.prepare("select ID_PILOTE,SALAIRE from pilote where SALAIRE!='"+destocc+"'" );


qry1.exec();

    while(qry1.next())
    {
        s1.id=qry1.value(0).toInt();
        s1.dest=qry1.value(1).toString();
        v2.push_back(s1);
    }
    for( int i=0;i<v2.size();i++){
        occ01=0;

        for( int j=0;j<v2.size();j++){
            if (v2[i].dest==v2[j].dest)
                occ01++;
        }
        if(occ01>occ2){
            occ2=occ01;
        destocc1=v2[i].dest;
        id1=v2[i].id;}
    }
    qry2.prepare("select ID_PILOTE,SALAIRE from pilote where SALAIRE!='"+destocc+"' and SALAIRE!='"+destocc1+"' " );


    qry2.exec();

        while(qry2.next())
        {
            s2.id=qry2.value(0).toInt();
            s2.dest=qry2.value(1).toString();

            v3.push_back(s2);
        }
        for(unsigned int i=0;i<v3.size();i++){
            occ02=0;

            for(unsigned int j=0;j<v3.size();j++){
                if (v3[i].dest==v3[j].dest)
                    occ02++;
            }
            if(occ02>occ3){
                occ3=occ02;
            destocc2=v3[i].dest;
            id2=v3[i].id;}
        }
        qry3.prepare("select ID_PILOTE,salaire from pilote where SALAIRE!='"+destocc+"' and SALAIRE!='"+destocc1+"' and SALAIRE!='"+destocc2+"'" );


        qry3.exec();

            while(qry3.next())
            {
                s3.id=qry3.value(0).toInt();
                s3.dest=qry3.value(1).toString();

                v4.push_back(s3);
            }
            for(unsigned int i=0;i<v4.size();i++){
                occ03=0;

                for(unsigned int j=0;j<v4.size();j++){
                    if (v4[i].dest==v4[j].dest)
                        occ03++;
                }
                if(occ03>occ4){
                    occ4=occ03;
                destocc3=v4[i].dest;
                id3=v4[i].id;}
            }

QPieSeries *series = new QPieSeries();
series->append(destocc,occ1);
series->append(destocc1,occ2);
series->append(destocc2,occ3);
series->append(destocc3,occ4);
QPieSlice *slice0 = series->slices().at(0);
slice0->setLabelVisible();
QPieSlice *slice1 = series->slices().at(1);
QPieSlice *slice2 = series->slices().at(2);
slice2->setLabelVisible();
slice2->setExploded();
slice2->setPen(QPen(Qt::darkBlue, 2));
slice2->setBrush(Qt::blue);
QPieSlice *slice3 = series->slices().at(3);
slice3->setLabelVisible();
slice3->setExploded();
slice3->setPen(QPen(Qt::darkGray, 2));
slice3->setBrush(Qt::gray);
slice1->setExploded();
slice1->setLabelVisible();
slice1->setPen(QPen(Qt::darkGreen, 2));
slice1->setBrush(Qt::green);
QChart *chart = new QChart();
 chart->addSeries(series);
 chart->setTitle("Les salaires de pilotes");

    chart->setAnimationOptions(QChart::AllAnimations);

    chart->legend()->hide();

    chartView = new QChartView(chart,ui->chartview_10);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(441,301);

    chartView->show();







}
