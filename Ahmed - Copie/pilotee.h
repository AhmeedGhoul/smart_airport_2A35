#ifndef PILOTEE_H
#define PILOTEE_H
#include "ui_login.h"
#include "historique.h"
#include <QDialog>

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
QString getid( );
bool modifier(QString id,QString nom,QString prenom,QString mdp);



private slots:
    void on_pushButton_1322_clicked();
    void on_pushButton_disc_clicked();

    void on_pushButton_clicked();

    void on_pushButton_pdfhistorique_clicked();

    void on_comboBox_trihistorique_currentTextChanged(const QString &arg1);

private:
    Ui::pilotee *ui;
    historique hismp1;

};

QString getuser(Ui::Login *uii);
#endif // PILOTEE_H
