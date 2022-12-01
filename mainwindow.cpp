#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "passager.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTextStream>
#include <QTextDocument>
#include <QDesktopWidget>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    ui->tableView->setModel(passmp.afficher());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//  ui->lineEdit_idvol->setValidator(new QIntValidator (0,99999999,ui->lineEdit_idvol));
//  ui->lineEdit_nbvol->setValidator(new QIntValidator (0,99999999,ui->lineEdit_nbvol));
//  ui->lineEdit_rechidvol->setValidator(new QIntValidator (0,99999999,ui->lineEdit_rechidvol));
//  ui->lineEdit_destvol->setValidator(new QRegExpValidator(  QRegExp("[A-Za-z]*")  ));
ui->checkBox->setCheckState(Qt::Unchecked);

ui->checkBox_2->setCheckState(Qt::Unchecked);

ui->checkBox_3->setCheckState(Qt::Unchecked);

ui->checkBox_4->setCheckState(Qt::Unchecked);

ui->checkBox_5->setCheckState(Qt::Unchecked);


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
    ui->frame_2->hide();
    ui->frame->hide();
    ui->pushButton_12->setStyleSheet("qproperty-icon:url(:/icons/icons/plane1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
    init_button(ui->pushButton_15,":/icons/icons/passager.png");
    init_button(ui->pushButton_16,":/icons/icons/pilot.png");
    init_button(ui->pushButton_14,":/icons/icons/runway.png");
    init_button(ui->pushButton_13,":/icons/icons/tickets.png");
    init_button(ui->pushButton_11,":/icons/icons/reservation.png");


}

void MainWindow::on_pushButton_15_clicked()
{
    ui->pushButton_12->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_15->setChecked(true);

    ui->frame_2->show();
    ui->frame->show();
    ui->tableView->setModel(passmp.afficher());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
   ui->pushButton_15->setStyleSheet("qproperty-icon:url(:/icons/icons/passager1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
   init_button(ui->pushButton_16,":/icons/icons/pilot.png");
   init_button(ui->pushButton_14,":/icons/icons/runway.png");
   init_button(ui->pushButton_13,":/icons/icons/tickets.png");
   init_button(ui->pushButton_12,":/icons/icons/plane.png");
   init_button(ui->pushButton_11,":/icons/icons/reservation.png");

}

void MainWindow::on_pushButton_11_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_11->setChecked(true);
    ui->frame_2->hide();
    ui->frame->hide();
        ui->pushButton_11->setStyleSheet("qproperty-icon:url(:/icons/icons/reservation1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_16,":/icons/icons/pilot.png");
init_button(ui->pushButton_14,":/icons/icons/runway.png");
init_button(ui->pushButton_13,":/icons/icons/tickets.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_13->setChecked(true);
    ui->frame_2->hide();
    ui->frame->hide();
    ui->tableView->setModel(passmp.afficher());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->pushButton_13->setStyleSheet("qproperty-icon:url(:/icons/icons/tickets1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_16,":/icons/icons/pilot.png");
init_button(ui->pushButton_14,":/icons/icons/runway.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_11,":/icons/icons/reservation.png");
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_16->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_14->setChecked(true);
    ui->frame_2->hide();
    ui->frame->hide();
        ui->pushButton_14->setStyleSheet("qproperty-icon:url(:/icons/icons/runway1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_16,":/icons/icons/pilot.png");
init_button(ui->pushButton_13,":/icons/icons/tickets.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_11,":/icons/icons/reservation.png");
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->pushButton_15->setChecked(false);
    ui->pushButton_11->setChecked(false);
    ui->pushButton_12->setChecked(false);
    ui->pushButton_13->setChecked(false);
    ui->pushButton_14->setChecked(false);
    ui->pushButton_16->setChecked(true);
    ui->frame_2->hide();
    ui->frame->hide();
    ui->pushButton_16->setStyleSheet("qproperty-icon:url(:/icons/icons/pilot1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_14,":/icons/icons/runway.png");
init_button(ui->pushButton_13,":/icons/icons/tickets.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_11,":/icons/icons/reservation.png");

}

void MainWindow::on_pushButton_ajoutvol_clicked()
{
    QSqlQuery qry;

    int a=0,a1=0,a2=0,a3=0,a4=0;
    QString val,passpass=ui->lineEdit_passpass->text();
    int Agepass=ui->lineEdit_Agepass->text().toInt();
   QDate datepass=ui->dateTimeEdit_datepass->date();
    QString nompass=ui->lineEdit_nompass->text();
    QString prenompass=ui->lineEdit_prenompass->text();
     QString avionpass=ui->lineEdit_avionpass->text();
    passager p(passpass,nompass,prenompass,Agepass,datepass,avionpass);
if (ui->checkBox->isChecked()){
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                         QObject::tr("acides sont interdits!"),
                         QMessageBox::Ok,
                         QApplication::desktop());
     message.exec();}
if (ui->checkBox_2->isChecked()){
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                         QObject::tr("pistoles sont interdits!"),
                         QMessageBox::Ok,
                         QApplication::desktop());
     message.exec();}
if (ui->checkBox_3->isChecked()){
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                         QObject::tr("couteux sont interdits!"),
                         QMessageBox::Ok,
                         QApplication::desktop());
     message.exec();}
if (ui->checkBox_4->isChecked()){
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                         QObject::tr("Equipement electronique sont interdits!"),
                         QMessageBox::Ok,
                         QApplication::desktop());
     message.exec();}
if (ui->checkBox_5->isChecked()){
    QMessageBox message(QMessageBox::Critical, QObject::tr("Error!"),
                         QObject::tr("Equipement Medical sont interdits!"),
                         QMessageBox::Ok,
                         QApplication::desktop());
     message.exec();}
else if(ui->checkBox_5->isChecked()==false &&ui->checkBox->isChecked()==false && ui->checkBox_2->isChecked()==false && ui->checkBox_3->isChecked()==false &&ui->checkBox_4->isChecked()==false ){
    QFile file(file_path);
    if (!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"..","File not open");

    }
        QTextStream in(&file);
        while (!in.atEnd())
        {
           QString line = in.readLine();
if (line==ui->lineEdit_passpass->text())
    a=1;
if (line==ui->dateTimeEdit_datepass->dateTime().toString())
    a1=1;
if (line==ui->lineEdit_nompass->text())
    a2=1;
if (line==ui->lineEdit_prenompass->text())
    a3=1;
if (line==ui->lineEdit_Agepass->text())
    a4=1;
        }
    if(a1==1 && a2==1 &&a==1 &&a3==1 &&a4==1){
        qry.prepare("select num_pass from RECHERCHEE where num_pass='"+ui->lineEdit_passpass->text()+"' " );


        if(qry.exec())
        {
            while(qry.next())
            {
                val=qry.value(0).toString();

            }
    }
      if (val!=ui->lineEdit_passpass->text())  {
    bool test=p.ajouter();
    if (test)
    {
        ui->tableView->setModel(passmp.afficher());

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
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

void MainWindow::on_pushButton_suppvol_clicked()
{QModelIndex index=ui->tableView->currentIndex();
    int i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();
    bool test=passmp.supprimer(val);
    if (test)
    {

        ui->tableView->setModel(passmp.afficher());

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }

}

void MainWindow::on_pushButton_modvol_clicked()
{
    QString passpass=ui->lineEdit_passpass->text();
    int Agepass=ui->lineEdit_Agepass->text().toInt();
   QDate datepass=ui->dateTimeEdit_datepass->date();
    QString nompass=ui->lineEdit_nompass->text();
    QString prenompass=ui->lineEdit_prenompass->text();
     QString avionpass=ui->lineEdit_avionpass->text();
     passager p(passpass,nompass,prenompass,Agepass,datepass,avionpass);
    bool test=p.modifier();
if(test)
    ui->tableView->setModel(passmp.afficher());

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager where num_pass='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_passpass->setText(qry.value(0).toString());
            ui->lineEdit_Agepass->setText(qry.value(3).toString());
            ui->lineEdit_nompass->setText(qry.value(1).toString());
            ui->lineEdit_prenompass->setText(qry.value(2).toString());
            ui->dateTimeEdit_datepass->setDate(qry.value(4).toDate());
            ui->lineEdit_avionpass->setText(qry.value(5).toString());
        }
}}


void MainWindow::on_lineEdit_rechidvol_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechidvol->text();

    if(text.isEmpty())
    {
        ui->tableView->setModel(passmp.afficher());

        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else
    {
        qry->prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager where num_pass='"+text+"'");
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

        QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString type=ui->comboBox->currentText();
    if (type=="Par defaut"){
        qry->prepare("select num_pass,nom,prenom,age,DATE_EXPR,num_serie from passager");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
                      modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
        ui->tableView->setModel(modal);}
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

            ui->tableView->setModel(modal);


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

            ui->tableView->setModel(modal);


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

            ui->tableView->setModel(modal);


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

        ui->tableView->setModel(modal);


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

        ui->tableView->setModel(modal);


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

        ui->tableView->setModel(modal);


    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this,"open file");
    QFile file(file_name);
    file_path=file_name;
    if (!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"..","File not open");

    }

    file.close();
}
