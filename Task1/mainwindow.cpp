#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QTextEdit>
#include <QDebug>
#include <QDate>
#include <QFile>
#include <QByteArray>
#include <QString>
#include <QChar>

int size = 1, i = 0, co = 0, a = 0;
int yyy = 0;
QString fileName = "C:/253506/inputqt.txt";
date* arr_of_dates = new date[size];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->agreeadd->hide();
    ui->bth->hide();
    ui->textbth->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString date::nextDay(const QDate &date) const
{
    return date.addDays(1).toString();
}

QString nextDay(const QDate &date)
{
    return date.addDays(1).toString();
}

QString date::PreviousDay(const QDate &date) const
{
    QString Date;
    std::string date1;
    bool check = true;

        Date = date.addDays(-1).toString();
        date1 = Date.toStdString();
        for(int j = 0; j < date1.size(); j++) {
        if (date1[j] == '-') {
            date1.erase(j, 1);
            check = false;
        }
        }
        if(!check) date1 = date1 + " до н.э.";
        Date = QString::fromStdString(date1);
     return Date;
}

QString PreviousDay(const QDate &date)
{
    QString Date;
    std::string date1;
    bool check = true;

        Date = date.addDays(-1).toString();
        date1 = Date.toStdString();
        for(int j = 0; j < date1.size(); j++) {
        if (date1[j] == '-') {
            date1.erase(j, 1);
            check = false;
        }
        }
        if(!check) date1 = date1 + " до н.э.";
        Date = QString::fromStdString(date1);
    return Date;
}

bool date::IsLeap(const int &year) const
{
    return QDate::isLeapYear(year);
}

int date::WeekNumber(const QDate &date) const
{
    return date.weekNumber();
}

int DaysTillYourBithday(const QDate &bithdaydate)
{
    return QDate::currentDate().daysTo(bithdaydate);
}

int date::Duration(const QDate &date) const
{
    return QDate::currentDate().daysTo(date);
}

int Duration(const QDate &date, QDate datee)
{
    return datee.daysTo(date);
}

void addDay()
    {
    size++;

    date* tmp = arr_of_dates;

    arr_of_dates = new date[size];

    for (int i = 0; i < size - 1; ++i) {
        arr_of_dates[i] = tmp[i];
    }

    delete[] tmp;
    }

void deleteDay()
{
    i = 0;
    co = 0;
    size = 1;
    a = 0;
    addDay();

}

void date::SetInfo(int Day, int Month, int Year)
{
  day = Day;
  month = Month;
  year = Year;
}

int date::dayDate()
{
  return day;
}

int date::monthDate()
{
  return month;
}

int date::yearDate()
{
  return year;
}

QString date::GetInfo()
{
    QString datee, Day, Month, Year;

    Day = QString::number(day);
    if(Day.size() < 2) Day = "0" + Day;

    Month = QString::number(month);
    if(Month.size() < 2) Month = "0" + Month;

    Year = QString::number(year);
    if(Year.size() < 4) {
        while(Year.size() < 4){
        Year = "0" + Year;
        }
    }

    datee = Day + "." + Month + "." + Year;
  return datee;
}

void MainWindow::readFile()
{
    int day, month, year;
    QString str;
    QFile file(fileName); // создаем объект класса QFile
    QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные

    try {
        file.open(QIODevice::ReadOnly);

        while(!file.atEnd()) {
    data = file.readLine(); //считываем все данные с файла в объект data
    str = QString(data);
    if (str.size() > 8) {
    day = (str.mid(0, 2)).toInt();
    month = (str.mid(3, 2)).toInt();
    year = (str.mid(6, 4)).toInt();

    if(i > 0) {
        if(co > 0) i++;
        else co++;

    addDay();
    }

    a++;

    arr_of_dates[i].SetInfo(day, month, year);

    if (i == 0) i++;

    }
    }
    }

    catch (std::exception& e) {
         ui->output->setText("ERROR");
    }

}

void MainWindow::on_pushButtonread_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();

    QString data = "";
    ui->output->setText(data);
    MainWindow::readFile();
}


void MainWindow::on_pushButtonnext_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);

    int day, month, year;
    QDate dataa;
    QString data, empty;
    ui->output->setText(empty);

    for(int j = 0; j < a; j++) {
    day = arr_of_dates[j].dayDate();
    month = arr_of_dates[j].monthDate();
    year = arr_of_dates[j].yearDate();
    dataa.setDate(year, month, day);
    data = arr_of_dates[j].nextDay(dataa);

    if(j == 0) {
     ui->output->setText(data);
    }

    else ui->output->append(data);
    }
}


void MainWindow::on_pushButtonprev_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);

    int day, month, year;
    QDate dataa;
    QString data, empty;
    ui->output->setText(empty);

    for(int j = 0; j < a; j++) {
    day = arr_of_dates[j].dayDate();
    month = arr_of_dates[j].monthDate();
    year = arr_of_dates[j].yearDate();
    dataa.setDate(year, month, day);
    data = arr_of_dates[j].PreviousDay(dataa);

    if(j == 0) {
     ui->output->setText(data);
    }

    else ui->output->append(data);
    }
}


void MainWindow::on_pushButtonshow_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);

    QString data, Info, empty;
    ui->output->setText(empty);

    for(int j = 0; j < a; j++) {
          data = arr_of_dates[j].GetInfo();
          if(j == 0) {
           ui->output->setText(data);
          }
          else ui->output->append(data);
    }
}


void MainWindow::on_pushButtonadd_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(false);

    QString data = "";
    ui->output->setText(data);
    ui->agreeadd->show();
}


void MainWindow::on_agreeadd_clicked()
{

    ui->bth->hide();
    ui->textbth->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(false);

    QString str;

    str = ui->output->toPlainText().trimmed();
    if (str.size() == 0 || (!str[0].isDigit() && !str[1].isDigit() && !str[3].isDigit() && !str[4].isDigit() && !str[6].isDigit() && !str[7].isDigit() && !str[8].isDigit() && !str[9].isDigit()) || (str[2] != '.') || (str[5] != '.')|| (str[10].isLetterOrNumber())) {

        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if (!((str.mid(0, 2)).toInt() > 0 && (str.mid(0, 2)).toInt() < 32 && (str.mid(3, 2)).toInt() > 0 && (str.mid(3, 2)).toInt() < 13 && (str.mid(6, 4)).toInt() > 0 && (str.mid(6, 4)).toInt() < 10000)) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if ((str.mid(0, 2)).toInt() > 30 && ((str.mid(3, 2)).toInt() == 4 || str.mid(3, 2).toInt() == 6 || str.mid(3, 2).toInt() == 9 || str.mid(3, 2).toInt() == 11)) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if ((str.mid(0, 2)).toInt() > 31 && ((str.mid(3, 2)).toInt() == 1 || str.mid(3, 2).toInt() == 3 || str.mid(3, 2).toInt() == 5 || str.mid(3, 2).toInt() == 7 || str.mid(3, 2).toInt() == 8 || str.mid(3, 2).toInt() == 10 || str.mid(3, 2).toInt() == 12)) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if (str.mid(0, 2).toInt() > 29 && str.mid(3, 2).toInt() == 2) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if (str.mid(0, 2).toInt() > 28 && str.mid(3, 2).toInt() == 2 && str.mid(6, 4).toInt() % 4 != 0) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if (str.size() > 10) {
        QMessageBox::critical(this, "Внимание!", "За 1 раз можно записать лишь одну дату");
    }

    else {

    QFile file(fileName);
    QByteArray daata;
    if (!file.open(QIODevice::Append)) {
       ui->output->setText("ERROR");
       }
else {

        daata = QByteArray::fromStdString(str.toStdString());
        if(yyy > 0) {
        file.write("\n" + daata);
        }
        if(yyy == 0) {
            file.write(daata);
           yyy++;
        }
    }
    }
    QString data = "";
    ui->output->setText(data);

}


void MainWindow::on_pushButtonleap_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);

    bool isLeap;
    int year;
    QString data, Year, empty;
    ui->output->setText(empty);

    for(int j = 0; j < a; j++) {
    year = arr_of_dates[j].yearDate();
    Year = QString::number(year);

    if(Year.size() < 4) {
        while(Year.size() < 4){
        Year = "0" + Year;
        }
    }

    isLeap = arr_of_dates[j].IsLeap(year);
    if (isLeap) {
        data = Year + " is a leap year!:)";
    }
    else data = Year + " is not a leap year!:(";

    if(j == 0) {
     ui->output->setText(data);
    }
    else ui->output->append(data);
    }
}


void MainWindow::on_pushButtonweek_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);

    int day, month, year, week;
    QDate dataa;
    QString data, empty;
    ui->output->setText(empty);

    for(int j = 0; j < a; j++) {

    day = arr_of_dates[j].dayDate();
    month = arr_of_dates[j].monthDate();
    year = arr_of_dates[j].yearDate();
    dataa.setDate(year, month, day);
    week = arr_of_dates[j].WeekNumber(dataa);

    data = QString::number(week);

    if(j == 0) {
     ui->output->setText("Week № " + data);
    }

    else ui->output->append("Week № " + data);
    }
}


void MainWindow::on_pushButtonbth_clicked()
{
    QString data, empty;
    ui->output->setText(empty);
    ui->bth->show();
    ui->textbth->show();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);
}


void MainWindow::on_bth_clicked()
{

    int day, month, daytobth;
    QDate dataa;
    QString data, empty;
    ui->output->setText(empty);

    QString str = ui->textbth->toPlainText().trimmed();

    if (str.size() == 0 || (!str[0].isDigit() && !str[1].isDigit() && !str[3].isDigit() && !str[4].isDigit() && !str[6].isDigit() && !str[7].isDigit() && !str[8].isDigit() && !str[9].isDigit()) || (str[2] != '.') || (str[5] != '.')|| (str[10].isLetterOrNumber())) {

        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if (!((str.mid(0, 2)).toInt() > 0 && (str.mid(0, 2)).toInt() < 32 && (str.mid(3, 2)).toInt() > 0 && (str.mid(3, 2)).toInt() < 13 && (str.mid(6, 4)).toInt() > 0 && (str.mid(6, 4)).toInt() < 10000)) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if ((str.mid(0, 2)).toInt() > 30 && ((str.mid(3, 2)).toInt() == 4 || str.mid(3, 2).toInt() == 6 || str.mid(3, 2).toInt() == 9 || str.mid(3, 2).toInt() == 11)) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if ((str.mid(0, 2)).toInt() > 31 && ((str.mid(3, 2)).toInt() == 1 || str.mid(3, 2).toInt() == 3 || str.mid(3, 2).toInt() == 5 || str.mid(3, 2).toInt() == 7 || str.mid(3, 2).toInt() == 8 || str.mid(3, 2).toInt() == 10 || str.mid(3, 2).toInt() == 12)) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if (str.mid(0, 2).toInt() > 29 && str.mid(3, 2).toInt() == 2) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if (str.mid(0, 2).toInt() > 28 && str.mid(3, 2).toInt() == 2 && str.mid(6, 4).toInt() % 4 != 0) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else {

    QDate dateToday = QDate::currentDate();
    day = (str.mid(0, 2)).toInt();
    month = (str.mid(3, 2)).toInt();

    if(str[0] == '2' && str[1] == '9' && str[3] == '0' && str[4] == '2') {
        day = 1;
        month = 3;
    }

    dataa.setDate(dateToday.year(), month, day);
    daytobth = DaysTillYourBithday(dataa);

    if (daytobth < 0) {
        daytobth = 365 + daytobth;
    }

    if (daytobth == 0) {
        ui->output->setText("Your birthday today!\nHappy birthday to you!:)");
    }

   if (daytobth > 0) {
    data = QString::number(daytobth);

    ui->output->setText("Before your birthday " + data + " days");
    }
    }

    ui->textbth->setText("");
}


void MainWindow::on_pushButtondays_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);


    int day, month, year, duration;
    QDate dataa;
    QString data, empty;
    ui->output->setText(empty);

    for(int j = 0; j < a; j++) {
    day = arr_of_dates[j].dayDate();
    month = arr_of_dates[j].monthDate();
    year = arr_of_dates[j].yearDate();
    dataa.setDate(year, month, day);
    duration = arr_of_dates[j].Duration(dataa);
    if(duration < 0) duration = -duration;

    data = QString::number(duration);

    if(j == 0) {
     ui->output->setText("Duration: " + data + " days");
    }

    else ui->output->append("Duration: " + data + " days");
    }
}

void MainWindow::on_clear_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();

    QString empty;
    ui->output->setText(empty);

    deleteDay();
}


void MainWindow::on_Add_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->show();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(false);

    QString data = "";
    ui->output->setText(data);
}


void MainWindow::on_agree_clicked()
{
    QString str;
    int day, month, year;

    str = ui->output->toPlainText().trimmed();

    if (str.size() == 0 || (!str[0].isDigit() && !str[1].isDigit() && !str[3].isDigit() && !str[4].isDigit() && !str[6].isDigit() && !str[7].isDigit() && !str[8].isDigit() && !str[9].isDigit()) || (str[2] != '.') || (str[5] != '.') || (str[10].isLetterOrNumber())) {

        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if (!((str.mid(0, 2)).toInt() > 0 && (str.mid(0, 2)).toInt() < 32 && (str.mid(3, 2)).toInt() > 0 && (str.mid(3, 2)).toInt() < 13 && (str.mid(6, 4)).toInt() > 0 && (str.mid(6, 4)).toInt() < 10000)) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if ((str.mid(0, 2)).toInt() > 30 && ((str.mid(3, 2)).toInt() == 4 || str.mid(3, 2).toInt() == 6 || str.mid(3, 2).toInt() == 9 || str.mid(3, 2).toInt() == 11)) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if ((str.mid(0, 2)).toInt() > 31 && ((str.mid(3, 2)).toInt() == 1 || str.mid(3, 2).toInt() == 3 || str.mid(3, 2).toInt() == 5 || str.mid(3, 2).toInt() == 7 || str.mid(3, 2).toInt() == 8 || str.mid(3, 2).toInt() == 10 || str.mid(3, 2).toInt() == 12)) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if (str.mid(0, 2).toInt() > 29 && str.mid(3, 2).toInt() == 2) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else if (str.mid(0, 2).toInt() > 28 && str.mid(3, 2).toInt() == 2 && str.mid(6, 4).toInt() % 4 != 0) {
        QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
    }

    else {

    day = (str.mid(0, 2)).toInt();
    month = (str.mid(3, 2)).toInt();
    year = (str.mid(6, 4)).toInt();

    if(i > 0) {
        if(co > 0) i++;
        else co++;
    addDay();
    }

    a++;
    arr_of_dates[i].SetInfo(day, month, year);
    if (i == 0) i++;
    }

    QString data = "";
    ui->output->setText(data);
}

void MainWindow::on_clear_file_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();

    QString data = "";
    ui->output->setText(data);

    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
}

void MainWindow::on_pushButton_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->show();
    ui->output->hide();
    ui->listWidget->clear();
    ui->pushButton_2->show();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);

    QString Day, Month, Year, data;
    int day, month, year;
    QString empty = "";
    ui->output->setText(empty);


    for(int j = 0; j < a; j++) {
        day = arr_of_dates[j].dayDate();
        Day = QString::number(day);

        if(Day.size() < 2) Day = "0" + Day;

        month = arr_of_dates[j].monthDate();
        Month = QString::number(month);

        if(Month.size() < 2) Month = "0" + Month;

        year = arr_of_dates[j].yearDate();
        Year = QString::number(year);

        if(Year.size() < 4) {
            while(Year.size() < 4){
            Year = "0" + Year;
            }
        }

        data = Day + "." + Month + "." + Year;
        ui->listWidget->addItem(data);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString data;
    QDate dataa;
    int day, month, year;
    QString empty = "";
    ui->output->setText(empty);
    ui->output->setReadOnly(true);

    data = ui->listWidget->currentItem()->text();

    ui->listWidget->hide();
    ui->output->show();

    ui->output->setText(data);

    day = (data.mid(0, 2)).toInt();
    month = (data.mid(3, 2)).toInt();
    year = (data.mid(6, 4)).toInt();

    dataa.setDate(year, month, day);
    data = nextDay(dataa);
    ui->output->append("Next day - " + data);

}


void MainWindow::on_pushButton_3_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->show();
    ui->output->hide();
    ui->listWidget->clear();
    ui->pushButton_2->hide();
    ui->pushButton_4->show();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);

    QString Day, Month, Year, data;
    int day, month, year;
    QString empty = "";
    ui->output->setText(empty);


    for(int j = 0; j < a; j++) {

        day = arr_of_dates[j].dayDate();
        Day = QString::number(day);

        if(Day.size() < 2) Day = "0" + Day;

        month = arr_of_dates[j].monthDate();
        Month = QString::number(month);

        if(Month.size() < 2) Month = "0" + Month;

        year = arr_of_dates[j].yearDate();
        Year = QString::number(year);

        if(Year.size() < 4) {
            while(Year.size() < 4){
            Year = "0" + Year;
            }
        }

        data = Day + "." + Month + "." + Year;
        ui->listWidget->addItem(data);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QString data;
    QDate dataa;
    int day, month, year;
    QString empty = "";
    ui->output->setText(empty);
    ui->output->setReadOnly(true);

    data = ui->listWidget->currentItem()->text();

    ui->listWidget->hide();
    ui->output->show();

    ui->output->setText(data);

    day = (data.mid(0, 2)).toInt();
    month = (data.mid(3, 2)).toInt();
    year = (data.mid(6, 4)).toInt();

    dataa.setDate(year, month, day);
    data = PreviousDay(dataa);
    ui->output->append("Previous day - " + data);

}


void MainWindow::on_durat_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);

    int day, month, year, duration, Day, Month, Year;
    QDate dataa, dataaa;
    QString data, empty = "";
    ui->output->setText(empty);

    for(int j = 0; j < a - 1; j++) {

        day = arr_of_dates[j].dayDate();
        month = arr_of_dates[j].monthDate();
        year = arr_of_dates[j].yearDate();
        Day = arr_of_dates[j + 1].dayDate();
        Month = arr_of_dates[j + 1].monthDate();
        Year = arr_of_dates[j + 1].yearDate();
        dataa.setDate(year, month, day);
        dataaa.setDate(Year, Month, Day);
        duration = Duration(dataa, dataaa);

        if (duration < 0) {
            duration = -duration;
        }

        data = QString::number(duration);

        if(j == 0) {
            ui->output->setText("Duration between adjacent dates: " + data + " days");
        }

        else ui->output->append("Duration between adjacent dates: " + data + " days");
    }
}


void MainWindow::on_pushButtonopen_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->hide();
    ui->output->show();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->label_5->hide();
    ui->NewDate->hide();
    ui->output->setReadOnly(true);

    QString nameFile;

    nameFile = QFileDialog::getOpenFileName(this, "Открытие документа", "C:\\", "Текстовые файлы (*.txt);");

    QFile file(nameFile);
    QString str;
    int result = 0;

    try {
        file.open(QIODevice::ReadOnly);

        if(file.size() == 0) {
            fileName = nameFile;
            ui->label_4->setText(fileName);
        }

        while(!file.atEnd()) {
    str = file.readLine().trimmed();
    result = 0;
    if (str.size() != 0 || (str[0].isDigit() && str[1].isDigit() && str[3].isDigit() && str[4].isDigit() && str[6].isDigit() && str[7].isDigit() && str[8].isDigit() && str[9].isDigit()) || (str[2] == '.') || (str[5] == '.') || (!str[10].isLetterOrNumber())) {
        result++;
    }

    if (((str.mid(0, 2)).toInt() > 0 && (str.mid(0, 2)).toInt() < 32 && (str.mid(3, 2)).toInt() > 0 && (str.mid(3, 2)).toInt() < 13 && (str.mid(6, 4)).toInt() > 0 && (str.mid(6, 4)).toInt() < 10000)) {
         result++;
    }

    if (!((str.mid(0, 2)).toInt() > 30 && ((str.mid(3, 2)).toInt() == 4 || str.mid(3, 2).toInt() == 6 || str.mid(3, 2).toInt() == 9 || str.mid(3, 2).toInt() == 11))) {
       result++;
    }

    if (!((str.mid(0, 2)).toInt() > 31 && ((str.mid(3, 2)).toInt() == 1 || str.mid(3, 2).toInt() == 3 || str.mid(3, 2).toInt() == 5 || str.mid(3, 2).toInt() == 7 || str.mid(3, 2).toInt() == 8 || str.mid(3, 2).toInt() == 10 || str.mid(3, 2).toInt() == 12))) {
         result++;
    }

    if (!(str.mid(0, 2).toInt() > 29 && str.mid(3, 2).toInt() == 2)) {
    result++;
    }

    if (!(str.mid(0, 2).toInt() > 28 && str.mid(3, 2).toInt() == 2 && str.mid(6, 4).toInt() % 4 != 0)) {
         result++;
    }

    if(result == 6){
      fileName = nameFile;
      ui->label_4->setText(fileName);
    }

    if(result < 6) {
         QMessageBox::critical(this, "Внимание!", "Выбранный вами файл не может быть использован\nв качестве источника ресурсов, так как он \nсодержит неподходящие данные");
         break;
    }

    }
    }

    catch (...) {
         ui->output->setText("ERROR");
    }


}

void MainWindow::on_pushButton_5_clicked()
{
    ui->bth->hide();
    ui->textbth->hide();
    ui->agreeadd->hide();
    ui->agree->hide();
    ui->listWidget->show();
    ui->output->hide();
    ui->listWidget->clear();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->show();
    ui->label_5->show();
    ui->NewDate->show();
    ui->output->setReadOnly(true);


    QString data, Dates;

    QFile file(fileName);
    QByteArray dates;

    file.open(QIODevice::ReadOnly);

    while(!file.atEnd()) {
         dates = file.readLine();
         Dates = QByteArray::fromStdString(dates.toStdString());
         Dates = Dates.mid(0, 10);
         ui->listWidget->addItem(Dates);
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    QString NewdatE;
    QString data, yrt, str;
    QDate dataa;
    QByteArray daata;
    QString empty = "";
    int day, month, year;
    QFile file(fileName);
        file.open(QIODevice::ReadWrite | QIODevice::Text);

       data = ui->listWidget->currentItem()->text();

       NewdatE = ui->NewDate->toPlainText().trimmed();
       str = NewdatE;

       if (str.size() == 0 || (!str[0].isDigit() && !str[1].isDigit() && !str[3].isDigit() && !str[4].isDigit() && !str[6].isDigit() && !str[7].isDigit() && !str[8].isDigit() && !str[9].isDigit()) || (str[2] != '.') || (str[5] != '.')|| (str[10].isLetterOrNumber())) {

           QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
       }

       else if (!((str.mid(0, 2)).toInt() > 0 && (str.mid(0, 2)).toInt() < 32 && (str.mid(3, 2)).toInt() > 0 && (str.mid(3, 2)).toInt() < 13 && (str.mid(6, 4)).toInt() > 0 && (str.mid(6, 4)).toInt() < 10000)) {
           QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
       }

       else if ((str.mid(0, 2)).toInt() > 30 && ((str.mid(3, 2)).toInt() == 4 || str.mid(3, 2).toInt() == 6 || str.mid(3, 2).toInt() == 9 || str.mid(3, 2).toInt() == 11)) {
           QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
       }

       else if ((str.mid(0, 2)).toInt() > 31 && ((str.mid(3, 2)).toInt() == 1 || str.mid(3, 2).toInt() == 3 || str.mid(3, 2).toInt() == 5 || str.mid(3, 2).toInt() == 7 || str.mid(3, 2).toInt() == 8 || str.mid(3, 2).toInt() == 10 || str.mid(3, 2).toInt() == 12)) {
           QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
       }

       else if (str.mid(0, 2).toInt() > 29 && str.mid(3, 2).toInt() == 2) {
           QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
       }

       else if (str.mid(0, 2).toInt() > 28 && str.mid(3, 2).toInt() == 2 && str.mid(6, 4).toInt() % 4 != 0) {
           QMessageBox::critical(this, "Внимание!", "Формат даты введен некорректно!\nПовторите попытку!");
       }

       else {

       ui->NewDate->setText(empty);

      while(!file.atEnd()) {

        str = NewdatE;
        yrt = file.readLine();
        yrt = yrt.mid(0, 10);


        if(data == yrt) {
            if (file.atEnd()) {
                file.seek(file.pos() - 10);
            }
            else {
            file.seek(file.pos() - 12);
            }


            yrt.clear();
            yrt.insert(0, NewdatE);
            daata = QByteArray::fromStdString(yrt.toStdString());
            file.write(daata);
            break;
        }
      }
    }
    file.close();
}
