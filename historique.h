#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDateTime>

class historique
{
    QString user,action;
    QDateTime dateh;
public:
    QString getuser(){return user;}
    QString getaction(){return action;}
    QDateTime getdateh(){return dateh;}
QSqlQueryModel * afficherpilo(QString id_pilote);
QSqlQueryModel * afficheradmin(QString admin);

    historique();
    historique(QString,QString,QDateTime);
    QSqlQueryModel * afficher();
bool supprimer(QDateTime d);
};

#endif // HISTORIQUE_H
