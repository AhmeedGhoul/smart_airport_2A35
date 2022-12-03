#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "piste.h"

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

private:
   Ui::MainWindow *ui;
   piste pismp;

};
#endif // MAINWINDOW_H
