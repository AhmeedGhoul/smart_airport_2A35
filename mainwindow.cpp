#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pilote.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTextStream>
#include <QTextDocument>
#include <QDesktopWidget>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <iostream>
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
  pilmp.afficher(ui);
//  ui->lineEdit_idvol->setValidator(new QIntValidator (0,99999999,ui->lineEdit_idvol));
//  ui->lineEdit_nbvol->setValidator(new QIntValidator (0,99999999,ui->lineEdit_nbvol));
//  ui->lineEdit_rechidvol->setValidator(new QIntValidator (0,99999999,ui->lineEdit_rechidvol));
//  ui->lineEdit_destvol->setValidator(new QRegExpValidator(  QRegExp("[A-Za-z]*")  ));
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
    ui->frame_2->hide();
    ui->frame->hide();
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
    pilmp.afficher(ui);

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
    ui->frame_2->show();
    ui->frame->show();
    ui->pushButton_16->setStyleSheet("qproperty-icon:url(:/icons/icons/pilot1.png);background: white;border-image:url(:/img/img/final.png);color: #1990ea;font: 40pt  'Oswald';font-size:22px;");
init_button(ui->pushButton_15,":/icons/icons/passager.png");
init_button(ui->pushButton_14,":/icons/icons/runway.png");
init_button(ui->pushButton_13,":/icons/icons/tickets.png");
init_button(ui->pushButton_12,":/icons/icons/plane.png");
init_button(ui->pushButton_11,":/icons/icons/reservation.png");
}

void MainWindow::on_pushButton_ajoutvol_clicked()
{
    QString idpilote=ui->lineEdit_idpilote->text();
    int salairepilote=ui->lineEdit_salairepilote->text().toInt();
    int periodepilote=ui->lineEdit_periodepilote->text().toInt();

    QString nompilote=ui->lineEdit_nompilote->text();
    QString prenompilote=ui->lineEdit_prenompilote->text();
     QString mdppilote=ui->lineEdit_mdppilote->text();
    pilote P(idpilote,nompilote,prenompilote,salairepilote,periodepilote,mdppilote);

    bool test=P.ajouter();
    if (test)
    {
        pilmp.afficher(ui);

    }


}

void MainWindow::on_pushButton_suppvol_clicked()
{QModelIndex index=ui->tableView->currentIndex();
    int i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();
    bool test=pilmp.supprimer(val);
    if (test)
    {

        pilmp.afficher(ui);

    }

}

void MainWindow::on_pushButton_modvol_clicked()
{
    QString idpilote=ui->lineEdit_idpilote->text();
    int salairepilote=ui->lineEdit_salairepilote->text().toInt();
    int periodepilote=ui->lineEdit_periodepilote->text().toInt();

    QString nompilote=ui->lineEdit_nompilote->text();
    QString prenompilote=ui->lineEdit_prenompilote->text();
    QString mdppilote=ui->lineEdit_mdppilote->text();
   pilote P(idpilote,nompilote,prenompilote,salairepilote,periodepilote,mdppilote);
    bool test=P.modifier();
if(test)
pilmp.afficher(ui);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select id_pilote,nom,prenom,salaire,periode from pilote where id_pilote='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_idpilote->setText(qry.value(0).toString());
            ui->lineEdit_salairepilote->setText(qry.value(3).toString());
            ui->lineEdit_nompilote->setText(qry.value(1).toString());
            ui->lineEdit_prenompilote->setText(qry.value(2).toString());
                       ui->lineEdit_periodepilote->setText(qry.value(4).toString());
                       ui->lineEdit_mdppilote->setText("");
        }
}}


void MainWindow::on_lineEdit_rechidvol_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit_rechidvol->text();

    if(text.isEmpty())
    {
        pilmp.afficher(ui);

    }
    else
    {
        qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote where id_pilote='"+text+"'");
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
        qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifant de pilote"));
        modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Salaire"));
        modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
         modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
           modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Periode"));
        ui->tableView->setModel(modal);}
        else if (type=="Identifiant de pilote"){
            qry->prepare("select id_pilote,nom,prenom,salaire,periode from pilote order by id_pilote");
            qry->exec();
            modal->setQuery(*qry);
            modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifant de pilote"));
            modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Salaire"));
            modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
             modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
               modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Periode"));

            ui->tableView->setModel(modal);


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

            ui->tableView->setModel(modal);


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
            ui->tableView->setModel(modal);


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

        ui->tableView->setModel(modal);


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

        ui->tableView->setModel(modal);


    }

}
