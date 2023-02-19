#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inputdate.h"
#include <QDate>
#include <QFile>
#include <QByteArray>
#include <QString>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void readFile();

private slots:

    void on_pushButtonread_clicked();

    void on_pushButtonnext_clicked();

    void on_pushButtonprev_clicked();

    void on_pushButtonshow_clicked();

    void on_pushButtonadd_clicked();

    void on_agreeadd_clicked();

    void on_pushButtonleap_clicked();

    void on_pushButtonweek_clicked();

    void on_pushButtonbth_clicked();

    void on_bth_clicked();

    void on_pushButtondays_clicked();

    void on_clear_clicked();

    void on_Add_clicked();

    void on_agree_clicked();

    void on_clear_file_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_durat_clicked();

    void on_pushButtonopen_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    InputDate *input;
};

class date
{

    int year, month, day;

public:

    QString nextDay(const QDate &date) const;
    QString PreviousDay(const QDate &date) const;
    bool IsLeap(const int &year) const;
    int WeekNumber(const QDate &date) const;
    int Duration(const QDate &date) const;
    void SetInfo (int Day, int Month, int Year);
    int dayDate();
    int monthDate();
    int yearDate();
    QString GetInfo();
};
#endif // MAINWINDOW_H
