#include "vol.h"
#include <QSqlQuery>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <iostream>
#include <QDate>
using namespace std;


vol::vol()
{
    id=0;
    nbp=0;
    type="";
    dest="";
}
vol::vol(int id,int nbp, QString type, QString dest,QDate date, QString id_pilote, QString num_serie)
{
this->id=id;
    this->nbp=nbp;
this->dest=dest;
this ->type=type;
   this ->date=date;
    this ->id_pilote=id_pilote;
       this ->num_serie=num_serie;
}
bool vol::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
QString res2=QString::number(nbp);
    query.prepare("insert into vol (id,type,dest,NB_PASSAGERS,datev)""values(:id,:type,:dest,:nbp,:date)");
    query.bindValue(":id", res);
            query.bindValue(":nbp", res2);
    query.bindValue(":type", type);
    query.bindValue(":dest", dest);
    query.bindValue(":date", date);
   // query.bindValue(":num_serie", num_serie);
    //query.bindValue(":id_pilote", id_pilote);
return query.exec();
}


bool vol::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from vol where ID=:id");
query.bindValue(":id",id);
return query.exec();
}
bool vol::modifier()
{

    QSqlQuery query;
    QString res=QString::number(id);
    QString res2=QString::number(nbp);

          query.prepare("UPDATE vol "" SET id=:id,type=:type,  dest=:dest, NB_PASSAGERS=:nbp, datev=:date  where ID='"+res+"' ");


          query.bindValue(":id", res);
                  query.bindValue(":nbp", res2);
          query.bindValue(":type", type);
          query.bindValue(":dest", dest);
          query.bindValue(":date", date);
//            query.bindValue(":num_serie", num_serie);
//            query.bindValue(":id_pilote", id_pilote);
        return    query.exec();
}

void vol::afficher(Ui::MainWindow *ui)
{

    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();

    qry->prepare("select * from vol");
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("NBpassasguer"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Destination"));
     modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
       modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));
//       modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Avion"));
//       modal->setHeaderData(6,Qt::Horizontal,QObject::tr("Pilote"));
    ui->tableView->setModel(modal);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}



//int vol::statvol(int month)
//{
//    QSqlQuery query;
//    query.prepare("select count(*) from vol where extract(month from datev)=:month ");
//    query.bindValue(":month",month);
//    query.exec();

//    int count=0;

//    while(query.next())
//    {
//        //count=query.value(0).toString().toInt() ;
//        count++;
//    }

//    return count;
//}



void vol::initBrowserView(Ui::MainWindow *ui){

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
