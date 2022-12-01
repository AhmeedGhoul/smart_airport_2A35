#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
#include "ui_pilotee.h"

#include <QDateTime>

class historique
{
    QString user,action;
    QDateTime dateh;
public:
    QString getuser(){return user;}
    QString getaction(){return action;}
    QDateTime getdateh(){return dateh;}
void afficherpilo(Ui::pilotee *ui,QString id_pilote);
void afficheradmin(Ui::MainWindow *ui,QString admin);

    historique();
    historique(QString,QString,QDateTime);
    void afficher(Ui::MainWindow *ui);
bool supprimer(QDateTime d);
};

#endif // HISTORIQUE_H
