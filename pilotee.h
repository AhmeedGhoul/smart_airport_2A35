#ifndef PILOTEE_H
#define PILOTEE_H
#include "historique.h"
#include <QDialog>
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
namespace Ui {
class pilotee;
}

class pilotee : public QDialog
{
    Q_OBJECT

public:
    explicit pilotee(QWidget *parent = nullptr);
    ~pilotee();
bool supprimer(QString id);
QString getid();
void closeEvent (QCloseEvent *event);

QChartView *chartView ;
void afficher(QString id_pilote);
void afficherchatboxx();
private slots:
    void on_pushButton_1322_clicked();
    void on_pushButton_disc_clicked();


    void on_pushButton_pdfhistorique_clicked();

    void on_comboBox_trihistorique_currentTextChanged(const QString &arg1);
void choix_bar();


    void on_pushButton_modpilotee_clicked();


    void on_pushButton_pdfvolpilotee_clicked();

    void on_comboBox_trivolpilotee_currentTextChanged(const QString &arg1);
    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::pilotee *ui;
    historique hismp1;

};

#endif // PILOTEE_H
bool modifier(QString id,QString nom,QString prenom,int salaire,int periode,QString mdp);
QString affichermsg(QString RECEIVER);
