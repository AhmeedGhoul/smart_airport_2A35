#include "vol.h"
#include <QSqlQuery>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <iostream>
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
#include<QtCharts>
#include <vector>

using namespace std;


vol::vol()
{
    id=0;
    nbp=0;
    type="";
    dest="";
    num_serie="";
    id_pilote="";
}
vol::vol(int id,int nbp, QString type, QString dest,QDate date, QString num_serie, QString id_pilote)
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
    query.prepare("insert into vol (id,type,dest,NB_PASSAGERS,datev,NUM_SERIE,ID_PILOTE)""values(:id,:type,:dest,:nbp,:date,:num_serie,:id_pilote)");
    query.bindValue(":id", res);
            query.bindValue(":nbp", res2);
    query.bindValue(":type", type);
    query.bindValue(":dest", dest);
    query.bindValue(":date", date);
    query.bindValue(":num_serie", num_serie);
    query.bindValue(":id_pilote", id_pilote);
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

          query.prepare("UPDATE vol "" SET id=:id,type=:type,  dest=:dest, NB_PASSAGERS=:nbp, datev=:date , num_serie=:num_serie, id_pilote=:id_pilote  where ID='"+res+"' ");


          query.bindValue(":id", res);
                  query.bindValue(":nbp", res2);
          query.bindValue(":type", type);
          query.bindValue(":dest", dest);
          query.bindValue(":date", date);
            query.bindValue(":num_serie", num_serie);
            query.bindValue(":id_pilote", id_pilote);
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
       modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Avion"));
       modal->setHeaderData(6,Qt::Horizontal,QObject::tr("Pilote"));
    ui->tableView->setModel(modal);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

}



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

void vol::choix_bar(Ui::MainWindow *ui)
{
QSqlQuery q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12;
int count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0,count11=0;

q1.prepare("select count(*) from vol where extract(month from datev)='"+QString::number(12)+"' ");
q1.exec();

q2.prepare("select count(*) from vol where extract(month from datev)='"+QString::number(1)+"'");
q2.exec();

q3.prepare("select count(*) from vol  where extract(month from datev)='"+QString::number(2)+"'");

q3.exec();

q4.prepare("select count(*) FROM vol where extract(month from datev)='"+QString::number(3)+"'");
q4.exec();

q5.prepare("select count(*) from vol where extract(month from datev)='"+QString::number(4)+"'");
q5.exec();

q6.prepare("select count(*) from vol  where extract(month from datev)='"+QString::number(5)+"'");

q6.exec();

q7.prepare("select count(*) FROM vol where extract(month from datev)='"+QString::number(6)+"'");

q7.exec();

q8.prepare("select count(*) from vol where extract(month from datev)='"+QString::number(7)+"'");
q8.exec();

q9.prepare("select count(*) from vol  where extract(month from datev)='"+QString::number(8)+"'");

q9.exec();

q10.prepare("select count(*) FROM vol where extract(month from datev)='"+QString::number(9)+"'");
q10.exec();

q11.prepare("select count(*) from vol where extract(month from datev)='"+QString::number(10)+"'");
q11.exec();

q12.prepare("select count(*) from vol  where extract(month from datev)='"+QString::number(11)+"'");

q12.exec();

while(q1.next())
    {

    count0=q1.value(0).toString().toInt() ;
    }
while(q2.next())
    {

    count1=q2.value(0).toString().toInt() ;
    }
while(q3.next())
    {

    count2=q3.value(0).toString().toInt() ;
    }
while(q4.next())
    {

    count3=q4.value(0).toString().toInt() ;
    }
while(q5.next())
    {

    count4=q5.value(0).toString().toInt() ;
    }
while(q6.next())
    {

    count5=q6.value(0).toString().toInt() ;
    }
while(q7.next())
    {

    count6=q7.value(0).toString().toInt() ;
    }
while(q8.next())
    {

    count7=q8.value(0).toString().toInt() ;
    }
while(q9.next())
    {

    count8=q9.value(0).toString().toInt() ;
    }
while(q10.next())
    {

    count9=q10.value(0).toString().toInt() ;
    }
while(q11.next())
    {

    count10=q11.value(0).toString().toInt() ;
    }
while(q12.next())
    {

    count11=q12.value(0).toString().toInt() ;
    }

        QBarSet *set0 = new QBarSet("Jan");
        *set0 << count1<< count2<< count3<< count4<< count5<< count6<< count7<< count8<< count9<< count10<< count11<< count0;
      QBarSeries *series = new QBarSeries();
        series->append(set0);
       QChart *chart = new QChart();
        chart->addSeries(series);
chart->setTitle("Vol par mois");
QStringList cataloge;
cataloge<<"Jan"<<"Fev"<<"Mar"<<"Avr"<<"May"<<"Jui"<<"Juil"<<"Aou"<<"Sep"<<"Oct"<<"Nov"<<"Dec";
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
void vol::occ(Ui::MainWindow *ui){

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
