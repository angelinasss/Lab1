#include "inputdate.h"
#include "ui_inputdate.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

InputDate::InputDate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDate)
{
    ui->setupUi(this);
}

InputDate::~InputDate()
{
    delete ui;
}

void InputDate::on_pushButtonOK_clicked()
{
    bool contin = true;

    int Day = ui->lineDay->text().toInt();
    int Month = ui->linemonth->text().toInt();
    int Year = ui->lineyear->text().toInt();
   // GetArr(Day, Month, Year);
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Информация", "Желаете ввести еще одну дату?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No) {
        contin = false;
   }

    if(!contin) {
        hide();
    }
}

