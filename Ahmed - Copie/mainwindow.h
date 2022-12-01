#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "vol.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include "historique.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
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


private:
   Ui::MainWindow *ui;
   vol volmp;
   historique hismp;
   QMediaPlayer *player;
   QVideoWidget *videoWidget;
   int okey=0;

};
#endif // MAINWINDOW_H
