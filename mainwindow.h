#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "vol.h"
#include "avion.h"
#include "piste.h"
#include "pilote.h"
#include "reservation.h"
#include "qrcode.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include "historique.h"
#include "admins.h"
#include "passager.h"
#include "notification.h"
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
#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QMediaService>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QMediaMetaData>
#include <QPalette>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QChartView *chartView ;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent (QCloseEvent *event);
void notif();
void initBrowserView();
void occ();
void statpass();
void statavion();
void statpilote();
void updateQRImage();
void statreservation();
void sendMail();
void browse();
void statpiste();
void statpilotepie();
void mailSent(QString);
void setCamera(const QCameraInfo &cameraInfo);
void readyForCapture(bool ready);
private slots:





    void on_pushButton_12_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();






    void init_button(QWidget *q,QString link);

    void on_pushButton_ajoutvol_clicked();

    void on_pushButton_suppvol_clicked();

    void on_pushButton_modvol_clicked();

    void on_tableView_clicked(const QModelIndex &index);
    void on_lineEdit_rechidvol_textChanged(const QString &arg1);

    void on_pushButton_impvol_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_horizontalSlider_volume_sliderMoved(int position);

    void on_horizontalSlider_progress_sliderMoved(int position);

    void on_pushButton_2_clicked();
void on_pushButton_3_clicked();
    void on_durationChanged(qint64 position);
    void on_positionChanged(qint64 position);


    void on_pushButton_17_clicked();

    void on_pushButton_clicked();

    void on_pushButton_pdfhistorique_clicked();

    void on_pushButton_supphistorique_clicked();


    void on_comboBox_trihistorique_currentTextChanged(const QString &arg1);

    void on_lineEdit_rechhistoriqe_textChanged(const QString &arg1);



    void on_pushButton_ajoutagent_clicked();

    void on_pushButton_modagent_clicked();

    void on_pushButton_suppagent_clicked();

    void on_pushButton_impagent_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_ajoutvol_3_clicked();

    void on_pushButton_modvol_3_clicked();

    void on_pushButton_suppvol_3_clicked();

    void on_pushButton_impvol_3_clicked();

    void on_tableView_5_clicked(const QModelIndex &index);

    void on_lineEdit_rechidvol_3_textChanged(const QString &arg1);

    void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_ajoutvol_2_clicked();

    void on_pushButton_suppvol_2_clicked();

    void on_pushButton_modvol_2_clicked();

    void on_tableView_3_clicked(const QModelIndex &index);

    void on_pushButton_impvol_2_clicked();

    void on_lineEdit_rechidvol_2_textChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_pushButton_ajoutvol_5_clicked();

    void on_pushButton_suppvol_5_clicked();

    void on_pushButton_modvol_5_clicked();

    void on_lineEdit_rechidvol_5_textChanged(const QString &arg1);

    void on_tableView_7_clicked(const QModelIndex &index);

    void on_pushButton_impvol_5_clicked();

    void on_comboBox_5_currentTextChanged(const QString &arg1);



    void on_pushButton_ajoutvol_6_clicked();

    void on_pushButton_suppvol_6_clicked();

    void on_pushButton_modvol_6_clicked();

    void on_tableView_9_clicked(const QModelIndex &index);

    void on_lineEdit_rechidvol_6_textChanged(const QString &arg1);

    void on_pushButton_impvol_6_clicked();

    void on_comboBox_6_currentTextChanged(const QString &arg1);

    void on_save_clicked();


    void on_calendrier_clicked(const QDate &date);

    void on_pushButton_ajoutpiste_clicked();

    void on_pushButton_supppiste_clicked();

    void on_pushButton_modpiste_clicked();

    void on_tableView_8_clicked(const QModelIndex &index);

    void on_lineEdit_rechpiste_textChanged(const QString &arg1);

    void on_pushButton_imppiste_clicked();

    void on_comboBox_7_currentTextChanged(const QString &arg1);

    void on_sendBtn_clicked();

    void on_browseBtn_clicked();

    void on_takeImageButton_clicked();

    void on_pushButton_4_clicked();

private:

   Ui::MainWindow *ui;
   vol volmp;
   stat statt1;
   admins admp;
   historique hismp;
   QMediaPlayer *player;
   QVideoWidget *videoWidget;
   avion avmp;
   pilote pilmp;
   reservation resermp;
   piste pismp;
   QStringList files;

   int okey=0;
PopUp *popUp;
passager passmp;
QString file_path;
bool successfulEncoding;
int encodeImageSize;
QPoint lastPos;
CQR_Encode qrEncode;
QCamera *Camera = nullptr;
QCameraImageCapture *imageCapture = nullptr;
QMediaRecorder* mediaRecorder = nullptr;

QImageEncoderSettings imageSettings;
QAudioEncoderSettings audioSettings;
QVideoEncoderSettings videoSettings;
QString videoContainerFormat;
bool isCapturingImage = false;
bool applicationExiting = false;
};
#endif // MAINWINDOW_H
