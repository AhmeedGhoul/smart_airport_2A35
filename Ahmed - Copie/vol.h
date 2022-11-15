#ifndef VOL_H
#define VOL_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
#include <QDate>
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
class vol
{
    QString dest,type,id_pilote,num_serie;
    int nbp,id;
    QDate date;
public:

    QChartView *chartView ;


    vol();
    vol(int,int, QString, QString,QDate, QString, QString);
    QString getdest(){return dest;}
    QString gettype(){return type;}
    int getID(){return id;}
    int getnbp(){return nbp;}
//int statvol(int month);
    void setdest(QString d){dest=d;}
    void settype(QString t){type=t;}
    void setID(int id){this->id=id;}
     void setnbp(int nbp){this->nbp=nbp;}
    bool ajouter();
    bool supprimer(QString);
    bool modifier();
    void afficher(Ui::MainWindow *ui);
void trie(Ui::MainWindow *ui);
void initBrowserView(Ui::MainWindow *ui);
void choix_bar(Ui::MainWindow *ui);
 void occ(Ui::MainWindow *ui);
};
class statt{
public:
    QString id,dest;

};

#endif // VOL_H
