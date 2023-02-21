#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void edit_combobox();
    ~MainWindow();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_save_clicked();

    void on_pushButton_5_clicked();

    void on_exit1_clicked();

    void on_studentsbox_currentIndexChanged(int index);

    void on_delete_abiturs_clicked();

    void on_info_speciality_clicked();

    void on_pushButton_3_clicked();

    void on_edit_abitur_clicked();

    void on_delete_abitur_clicked();

    void on_choice_clicked();

    void on_choice2_clicked();

    void on_editinfo_clicked();

   void on_choicepath_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
