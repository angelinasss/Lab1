#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "students.h"
#include <QMessageBox>
#include <QTextEdit>
#include <QDebug>
#include <QDate>
#include <QFile>
#include <QByteArray>
#include <QtCore>
#include <QChar>
#include <stdlib.h>
#include <malloc.h>
#include <string>

int size = 1, i = 0, co = 0, a = 0, ind, mathp, physicsp, rusp;
double averp;
QString Name, spec, fileName = "C:\\FilesForQtLabs\\Students.txt";
Student* students = new Student[size];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->fio->hide();

    ui->studentsbox->hide();

    ui->FIO->hide();

    ui->lineEdit_2->hide();

    ui->lineEdit->hide();

    ui->lineEdit_3->hide();

    ui->lineEdit_4->hide();

    ui->lineEdit_5->hide();

    ui->ghj->hide();

    ui->label_2->hide();

    ui->label_3->hide();

    ui->label_4->hide();

    ui->label_5->hide();

    ui->label_6->hide();

    ui->label->hide();

    ui->textEdit->hide();

    ui->list_of_abitur->hide();

    ui->save->hide();

    ui->exit1->hide();

    ui->info_special->hide();

    ui->pushButton_3->hide();

    ui->listWidget->hide();

    ui->label_7->hide();

    ui->choice->hide();

    ui->edit_ab->hide();

    ui->choice2->hide();

    ui->label_8->hide();

    ui->editinfo->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void del(Student* students)
    {

delete[] students;

    }


void addStudent()
    {
    size++;

    Student* tmp = students;

    students = new Student[size];

    for (int i = 0; i < size - 1; ++i) {
        students[i] = tmp[i];
    }

    delete[] tmp;

    }

void editsize() {
    size = size - 1;

    a = a - 1;

    co = co - 1;
}

void delete_abitura () {

    i = 0;
    a = 0;
    co = 0;

    size = 1;

    Student* tmp = students;

    students = new Student[size];

    for (int i = 0; i < size - 1; ++i) {
        students[i] = tmp[i];
    }

    delete[] tmp;
}

 void MainWindow::edit_combobox() {
    QFile file(fileName);
    QString str;

    if(i == 0) {
         ui->studentsbox->clear();
    }

    else {
    ui->studentsbox->clear();

    try {

     file.open(QIODevice::ReadOnly);

       str = "";
       ui->studentsbox->addItem(str);

        while(!file.atEnd()) {

               str = file.readLine();

        if(str.size() != 1) {

        ui->studentsbox->addItem(str);

        str = file.readLine();

        str = file.readLine();

        str = file.readLine();

        str = file.readLine();

        str = file.readLine();

        }
      }
    }
    catch(...) {
        QMessageBox::critical(this, "Внимание!", "Не удалось открыть выбранный вами файл!");
    }
 }
}

void MainWindow::on_pushButton_6_clicked()
{
     del(students);
     exit(0);
}

void MainWindow::on_pushButton_2_clicked()
{

    ui->edit_abitur->hide();

    ui->delete_abitur->hide();

    ui->info_special->hide();

    ui->info_speciality->hide();

    ui->fio->hide();

    ui->delete_abiturs->hide();

    ui->exit1->show();

    ui->studentsbox->hide();

    ui->pushButton_2->hide();

    ui->pushButton_5->hide();

    ui->pushButton_3->hide();

    ui->pushButton_6->hide();

    ui->pushButton->hide();

    ui->textEdit->show();

    ui->list_of_abitur->show();

    ui->textEdit->clear();

    ui->listWidget->hide();

    ui->FilePath->hide();

    ui->choicepath->hide();

    QString str, info;
    double aver;
\
    if(students[0].info_student() != " ") {
    for(int j = 0; j < a; j++) {
        str = students[j].info_student();

        info = "NAME: ";

        if(j == 0) {
        ui->textEdit->setText(info + str);
        }

        else ui->textEdit->append("\n" + info + str);

        str = students[j].speciality_student();

        info = "SPECIALITY: ";

        ui->textEdit->append(info + str);

        aver = students[j].aver_point();

        info = "AVERAGE POINT: ";

        ui->textEdit->append(info + QString::number(aver));

        aver = students[j].rus_language_mark();

        info = "RUSSIAN LANGUAGE POINT: ";

        ui->textEdit->append(info + QString::number(aver));

        aver = students[j].physics_mark();

        info = "PHYSICS POINT: ";

        ui->textEdit->append(info + QString::number(aver));

        aver = students[j].math_mark();

        info = "MATH POINT: ";

        ui->textEdit->append(info + QString::number(aver));


    }
    }
    ui->textEdit->setReadOnly(true);
}

void MainWindow::on_pushButton_clicked()
{
    QFile file(fileName);
    QString str;
    int counter = 0;

    if (i == 0) {

        try {

    file.open(QIODevice::ReadOnly);

        while(!file.atEnd()) {

            if(i > 0) {
                if(co > 0) i++;
                else co++;

            addStudent();
            }

            a++;


               str = file.readLine();

               while(str.size() < 2) {
                    str = file.readLine();
               }

         students[i].FIO(str.trimmed());

        str = file.readLine();

         students[i].specialit(str.trimmed());

         str = file.readLine();

          students[i].averpo(str.toDouble());

        str = file.readLine();

        students[i].ruslang(str.toInt());

        str = file.readLine();

        students[i].phys(str.toInt());

        str = file.readLine();

        students[i].mathem(str.toInt());

        counter++;

        if (i == 0) i++;
    }
            file.close();
    }
        catch(...) {
            QMessageBox::critical(this, "Внимание!", "Не удалось открыть выбранный вами файл!");
        }
}

        ui->FilePath->hide();

        ui->choicepath->hide();

        ui->lineEdit_2->show();

        ui->lineEdit->show();

        ui->lineEdit_3->show();

        ui->lineEdit_4->show();

        ui->lineEdit_5->show();

        ui->ghj->show();

        ui->lineEdit_2->clear();

        ui->lineEdit->clear();

        ui->lineEdit_3->clear();

        ui->lineEdit_4->clear();

        ui->lineEdit_5->clear();

        ui->ghj->clear();

        ui->lineEdit->setReadOnly(false);

        ui->lineEdit_2->setReadOnly(false);

        ui->lineEdit_3->setReadOnly(false);

        ui->lineEdit_4->setReadOnly(false);

        ui->lineEdit_5->setReadOnly(false);

        ui->ghj->setReadOnly(false);


    ui->edit_abitur->hide();

    ui->delete_abitur->hide();

    ui->fio->hide();

    ui->delete_abiturs->hide();

    ui->exit1->show();

    ui->listWidget->hide();

    ui->info_special->hide();

    ui->info_speciality->hide();

    ui->studentsbox->hide();

    ui->FIO->show();

    ui->label_2->show();

    ui->label_3->show();

    ui->label_4->show();

    ui->label_5->show();

    ui->label_6->show();

    ui->label->show();

    ui->textEdit->show();

    ui->save->show();

    ui->pushButton_2->hide();

    ui->pushButton_5->hide();

    ui->pushButton_3->hide();

    ui->pushButton_6->hide();

    ui->pushButton->hide();

    ui->textEdit->hide();

    ui->list_of_abitur->hide();
}

void MainWindow::on_save_clicked()
{
    QString str;

    QString math_mark = ui->lineEdit_2->text().trimmed();

    QString physics_mark = ui->lineEdit->text().trimmed();

    QString rus_language_mark = ui->lineEdit_3->text().trimmed();

    QString average_point = ui->lineEdit_4->text().trimmed();

    QString speciality = ui->lineEdit_5->text().trimmed();

    QString fio = ui->ghj->toPlainText().trimmed();

    bool result = true;

    if(math_mark.size() == 0) {
        str = "Оценка по математике";
        QMessageBox::critical(this, "Внимание!", str + " введенa некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(physics_mark.size() == 0) {
        str = "Оценка по физике";
        QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(rus_language_mark.size() == 0) {
        str = "Оценка по русскому языку";
        QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(average_point.size() == 0) {
        str = "Средний балл аттестата";
        QMessageBox::critical(this, "Внимание!", str + " введен некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(speciality.size() == 0) {
        str = "Специальность";
        QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(fio.size() == 0) {
        str = "ФИО";
        QMessageBox::critical(this, "Внимание!", str + " введено некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(1) {
        str = "Оценка по математике";
    for(int j = 0; j < math_mark.size(); j++) {
        if(!math_mark[j].isDigit()) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }

        else if(math_mark.toInt() > 100 || math_mark.toInt() < 1) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }
    }
    }

    if(result) {
        str = "Оценка по физике";

    for(int j = 0; j < physics_mark.size(); j++) {
        if(!(physics_mark[j].isDigit())) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }

        else if(physics_mark.toInt() > 100 || physics_mark.toInt() < 1) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }
    }
    }

    if(result) {
        str = "Оценка по русскому языку";

    for(int j = 0; j < rus_language_mark.size(); j++) {
        if(!rus_language_mark[j].isDigit()) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }

        else if(rus_language_mark.toInt() > 100
             || rus_language_mark.toInt() < 1) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }
    }
    }

    if(result) {
        str = "Средний балл";

    for(int j = 0; j < average_point.size(); j++) {
        if(!average_point[j].isDigit()) {
            if((j == 1 && average_point[j] == '.')
            || (j == 2 && average_point[0] == '1'
            && average_point[1] == '0'
            && average_point[j] == '.')) {
              result = true;
            }
            else {
            QMessageBox::critical(this, "Внимание!", str + " введен некорректно!\nПовторите попытку!");
            result = false;
            break;
            }
        }

        else if(average_point.toInt() > 10 || average_point.toInt() < 0) {
            QMessageBox::critical(this, "Внимание!", str + " введен некорректно!\nПовторите попытку!");
            result = false;
            break;
        }
    }
    }

    if(result){

    int math = math_mark.toInt();

    int physics = physics_mark.toInt();

    int rus_lang = rus_language_mark.toInt();

    double aver_point = average_point.toDouble();

    try {
    QFile file(fileName);
    QByteArray daata;

       file.open(QIODevice::Append);

        daata = QByteArray::fromStdString(fio.toStdString());
        file.write("\n" + daata);

        daata = QByteArray::fromStdString(speciality.toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(average_point.toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(rus_language_mark.toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(physics_mark.toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(math_mark.toStdString());

        file.write("\n" + daata);

        if(i > 0) {
            if(co > 0) i++;
            else co++;

        addStudent();
        }

        a++;

        students[i].SetInfo(fio, speciality, aver_point, math, rus_lang, physics);

        if (i == 0) i++;

        ui->lineEdit_2->clear();

        ui->lineEdit->clear();

        ui->lineEdit_3->clear();

        ui->lineEdit_4->clear();

        ui->lineEdit_5->clear();

        ui->ghj->clear();

    file.close();
    }
    catch(...) {
        QMessageBox::critical(this, "Внимание!", "Не удалось открыть выбранный вами файл!");
    }

    }
}


void MainWindow::on_pushButton_5_clicked()
{
    edit_combobox();

    ui->delete_abiturs->hide();

    ui->edit_abitur->hide();

    ui->delete_abitur->hide();

    ui->fio->show();

    ui->studentsbox->show();

    ui->FIO->hide();

    ui->list_of_abitur->hide();

    ui->listWidget->hide();

    ui->lineEdit_2->show();

    ui->lineEdit->show();

    ui->info_special->hide();

    ui->info_speciality->hide();

    ui->lineEdit_3->show();

    ui->lineEdit_4->show();

    ui->exit1->hide();

    ui->lineEdit_5->show();

    ui->ghj->hide();

    ui->label_2->show();

    ui->label_3->show();

    ui->label_4->show();

    ui->label_5->show();

    ui->label_6->show();

    ui->label->show();

    ui->textEdit->show();

    ui->save->hide();

    ui->pushButton_2->hide();

    ui->pushButton_5->hide();

    ui->pushButton_3->hide();

    ui->pushButton_6->hide();

    ui->pushButton->hide();

    ui->textEdit->hide();

    ui->exit1->show();

    ui->FilePath->hide();

    ui->choicepath->hide();

    ui->lineEdit->setReadOnly(true);

    ui->lineEdit_2->setReadOnly(true);

    ui->lineEdit_3->setReadOnly(true);

    ui->lineEdit_4->setReadOnly(true);

    ui->lineEdit_5->setReadOnly(true);

    ui->ghj->setReadOnly(true);
}

void MainWindow::on_exit1_clicked()
{
    ui->edit_abitur->show();

    ui->delete_abiturs->show();

    ui->label_8->hide();

    ui->delete_abiturs->show();

    ui->delete_abitur->show();

    ui->fio->hide();

    ui->exit1->hide();

    ui->studentsbox->hide();

    ui->pushButton_2->show();

    ui->pushButton_5->show();

    ui->pushButton_3->hide();

    ui->info_special->hide();

    ui->info_speciality->show();

    ui->listWidget->hide();

    ui->pushButton_6->show();

    ui->pushButton->show();

    ui->textEdit->hide();

    ui->list_of_abitur->hide();

    ui->label->hide();

    ui->label_2->hide();

    ui->label_3->hide();

    ui->label_4->hide();

    ui->label_5->hide();

    ui->label_6->hide();

    ui->lineEdit_2->hide();

    ui->lineEdit->hide();

    ui->lineEdit_3->hide();

    ui->lineEdit_4->hide();

    ui->lineEdit_5->hide();

    ui->label_7->hide();

    ui->choice->hide();

    ui->edit_ab->hide();

    ui->choice2->hide();

    ui->FIO->hide();

    ui->ghj->hide();

    ui->editinfo->hide();

    ui->FilePath->show();

    ui->choicepath->show();

    ui->save->hide();
}

void MainWindow::on_studentsbox_currentIndexChanged(int index)
{
    QString name, name1;
    int mark;
    double mark1;

    name = ui->studentsbox->currentText().trimmed();

    if (index == 0) {
        ui->lineEdit->clear();

        ui->lineEdit_3->clear();

        ui->lineEdit_2->clear();

        ui->lineEdit_4->clear();

        ui->lineEdit_5->clear();
    }

    else {

 for(int m = 0; m < i + 1; m++) {

        name1 = students[m].info_student().trimmed();

        if (name == name1) {

            mark = students[m].physics_mark();

            ui->lineEdit->setText(QString::number(mark));

            mark = students[m].rus_language_mark();

            ui->lineEdit_3->setText(QString::number(mark));

            mark = students[m].math_mark();

            ui->lineEdit_2->setText(QString::number(mark));

            mark1 = students[m].aver_point();

            ui->lineEdit_4->setText(QString::number(mark1));

            name = students[m].speciality_student();

            ui->lineEdit_5->setText(name);

            break;
        }
    }
 }
}

void MainWindow::on_delete_abiturs_clicked()
{
     delete_abitura ();

     QFile file(fileName);

     try {

     file.open(QIODevice::WriteOnly | QIODevice::Truncate);

     file.close();
}
     catch(...) {
         QMessageBox::critical(this, "Внимание!", "Не удалось открыть выбранный вами файл!");
     }
}

void MainWindow::on_info_speciality_clicked()
{
    ui->edit_abitur->hide();

    ui->delete_abitur->hide();

    ui->fio->hide();

    ui->delete_abiturs->hide();

    ui->exit1->show();

    ui->studentsbox->hide();

    ui->pushButton_2->hide();

    ui->pushButton_5->hide();

    ui->pushButton_3->show();

    ui->pushButton_6->hide();

    ui->pushButton->hide();

    ui->textEdit->show();

    ui->list_of_abitur->show();

    ui->textEdit->clear();

    ui->info_speciality->hide();

    ui->list_of_abitur->hide();

    ui->info_special->show();

    ui->FilePath->hide();

    ui->choicepath->hide();

    QString speciality;

    int sum = 0;
    int counter = 0;
    bool tr = true;

    for (int c = 0; c < a; c++) {

        speciality = students[c].speciality_student().trimmed();
        tr = true;


                   if(c != 0) {
                    for(int g = 0; g < c; g++) {
                        if (speciality == students[g].speciality_student().trimmed()) {
                            tr = false;
                            break;
                        }
                    }
                   }


                if(tr){

                    if(c == 0) {
                    ui->textEdit->setText("\t\t\t\t" + speciality.toUpper() + "\t\t\t\t");
                    }

                    else if (c != 0){
                        ui->textEdit->append("\t\t\t\t" + speciality.toUpper() + "\t\t\t\t");
                    }

            for (int k = c; k < a; k++)    {

                if(speciality == students[k].speciality_student().trimmed()) {

            sum = students[k].math_mark() + students[k].rus_language_mark() + students[k].physics_mark() + students[k].aver_point() * 10;

            ui->textEdit->append("NAME: " + students[k].info_student());

            ui->textEdit->append("POINTS: " + QString::number(sum));
                }
                }
        }
    }
    ui->textEdit->setReadOnly(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString speciality;

    int sum = 0, comsum = 0, news, po = 0;
    int counter = 0, ii = 0;
    bool tr = true;

    ui->textEdit->clear();

    for (int k = 0; k < a; k++) {
        sum = students[k].math_mark() + students[k].rus_language_mark() + students[k].physics_mark() + students[k].aver_point() * 10;

        students[k].getsum(sum);
    }

    Student temp;

    for (int g = 0; g < a - 1; g++) {
        for (int m = 0; m < a - g - 1; m++) {
            if (students[m].compare(students[m], students[m + 1])) {
                temp = students[m];
                students[m] = students[m + 1];
                students[m + 1] = temp;
            }
        }
    }

    for (int c = 0; c < a; c++) {

        speciality = students[c].speciality_student().trimmed();
        tr = true;


                   if(c != 0) {
                    for(int g = 0; g < c; g++) {
                        if (speciality == students[g].speciality_student().trimmed()) {
                            tr = false;
                            break;
                        }
                    }
                   }


                if(tr){

                    if(c == 0) {
                    ui->textEdit->setText("\t\t\t\t" + speciality.toUpper() + "\t\t\t\t");
                    }

                    else if (c != 0){
                        ui->textEdit->append("\t\t\t\t" + speciality.toUpper() + "\t\t\t\t");
                    }

            for (int k = c; k < a; k++)    {

                if(speciality == students[k].speciality_student().trimmed()) {

            sum = students[k].math_mark() + students[k].rus_language_mark() + students[k].physics_mark() + students[k].aver_point() * 10;

            ui->textEdit->append("NAME: " + students[k].info_student());

            ui->textEdit->append("POINTS: " + QString::number(sum));
                }
                }
        }
    }
    ui->textEdit->setReadOnly(true);
}

void MainWindow::on_edit_abitur_clicked()
{
    ui->listWidget->clear();

    ui->edit_abitur->hide();

    ui->delete_abitur->hide();

    ui->info_special->hide();

    ui->info_speciality->hide();

    ui->fio->hide();

    ui->delete_abiturs->hide();

    ui->exit1->show();

    ui->studentsbox->hide();

    ui->pushButton_2->hide();

    ui->pushButton_5->hide();

    ui->pushButton_3->hide();

    ui->pushButton_6->hide();

    ui->pushButton->hide();

    ui->textEdit->hide();

    ui->pushButton_3->hide();

    ui->listWidget->show();

    ui->edit_ab->show();

    ui->list_of_abitur->show();

    ui->choice2->show();

    ui->FilePath->hide();

    ui->choicepath->hide();

    if (i > 0) {
    for(int j = 0; j < a; j++) {
        ui->listWidget->addItem(students[j].info_student());
    }
    }
}


void MainWindow::on_delete_abitur_clicked()
{
    ui->label_7->show();

    ui->edit_abitur->hide();

    ui->delete_abitur->hide();

    ui->info_special->hide();

    ui->info_speciality->hide();

    ui->fio->hide();

    ui->delete_abiturs->hide();

    ui->exit1->show();

    ui->studentsbox->hide();

    ui->pushButton_2->hide();

    ui->pushButton_5->hide();

    ui->pushButton_3->hide();

    ui->pushButton_6->hide();

    ui->pushButton->hide();

    ui->textEdit->hide();

    ui->pushButton_3->hide();

    ui->listWidget->show();

    ui->list_of_abitur->show();

    ui->listWidget->clear();

    ui->choice->show();

    ui->FilePath->hide();

    ui->choicepath->hide();

    if (i > 0) {
    for(int j = 0; j < a; j++) {
        ui->listWidget->addItem(students[j].info_student());
    }
    }
}

void MainWindow::on_choice_clicked()
{
    if(i != 0) {
    QString name;
    name = ui->listWidget->currentItem()->text();

    for(int j = 0; j < a - 1; j++) {
        if(name == students[j].info_student()) {
            std::swap(students[j], students[j + 1]);
        }
    }

    editsize();

    ui->listWidget->clear();

    for(int j = 0; j < a; j++) {
        ui->listWidget->addItem(students[j].info_student());
    }

    QFile file(fileName);
    QByteArray daata;

    try {

    file.open(QIODevice::WriteOnly | QIODevice::Truncate);

    file.close();

    file.open(QIODevice::Append);

     for(int j = 0; j < a; j++) {

        daata = QByteArray::fromStdString(students[j].info_student().toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(students[j].speciality_student().toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(QString::number(students[j].aver_point()).toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(QString::number(students[j].rus_language_mark()).toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(QString::number(students[j].physics_mark()).toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(QString::number(students[j].math_mark()).toStdString());

        file.write("\n" + daata);

        edit_combobox();

        file.close();

        QMessageBox::about(this, "ИНФОРМАЦИЯ", "Абитуриент '" + name + "' успешно удален из списка!");

        }
        }
    catch(...) {
        QMessageBox::critical(this, "Внимание!", "Не удалось открыть выбранный вами файл!");
    }
    }

}


void MainWindow::on_choice2_clicked()
{

    if(i != 0) {

        ui->choice2->hide();

        ui->listWidget->hide();

        ui->edit_ab->hide();

        ui->list_of_abitur->hide();

    QString name1, name = ui->listWidget->currentItem()->text();
    int index;

    Name = name;

    for(int j = 0; j < a; j++) {
        name1 = students[j].info_student();

        if(name == name1) {
            index = j;
            spec = students[j].speciality_student();
            averp = students[j].aver_point();
            mathp = students[j].math_mark();
            physicsp = students[j].physics_mark();
            rusp = students[j].rus_language_mark();
            break;
        }
    }

    ind = index;

    ui->label_8->show();

    ui->lineEdit_2->show();

    ui->lineEdit->show();

    ui->lineEdit_3->show();

    ui->lineEdit_4->show();

    ui->lineEdit_5->show();

    ui->ghj->show();

    ui->lineEdit_2->clear();

    ui->lineEdit->clear();

    ui->lineEdit_3->clear();

    ui->lineEdit_4->clear();

    ui->lineEdit_5->clear();

    ui->ghj->clear();

    ui->lineEdit->setReadOnly(false);

    ui->lineEdit_2->setReadOnly(false);

    ui->lineEdit_3->setReadOnly(false);

    ui->lineEdit_4->setReadOnly(false);

    ui->lineEdit_5->setReadOnly(false);

    ui->ghj->setReadOnly(false);

    ui->FIO->show();

    ui->label_2->show();

    ui->label_3->show();

    ui->label_4->show();

    ui->label_5->show();

    ui->label_6->show();

    ui->label->show();

    ui->editinfo->show();

    }
}


void MainWindow::on_editinfo_clicked()
{
    QString str;

    QString math_mark = ui->lineEdit_2->text().trimmed();

    QString physics_mark = ui->lineEdit->text().trimmed();

    QString rus_language_mark = ui->lineEdit_3->text().trimmed();

    QString average_point = ui->lineEdit_4->text().trimmed();

    QString speciality = ui->lineEdit_5->text().trimmed();

    QString fio = ui->ghj->toPlainText().trimmed();

    bool result = true;

    if(math_mark.size() == 0) {
        str = "Оценка по математике";
        QMessageBox::critical(this, "Внимание!", str + " введенa некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(physics_mark.size() == 0) {
        str = "Оценка по физике";
        QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(rus_language_mark.size() == 0) {
        str = "Оценка по русскому языку";
        QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(average_point.size() == 0) {
        str = "Средний балл аттестата";
        QMessageBox::critical(this, "Внимание!", str + " введен некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(speciality.size() == 0) {
        str = "Специальность";
        QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(fio.size() == 0) {
        str = "ФИО";
        QMessageBox::critical(this, "Внимание!", str + " введено некорректно!\nПовторите попытку!");
        result = false;
    }

    else if(1) {
        str = "Оценка по математике";
    for(int j = 0; j < math_mark.size(); j++) {
        if(!math_mark[j].isDigit()) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }

        else if(math_mark.toInt() > 100 || math_mark.toInt() < 1) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }
    }
    }

    if(result) {
        str = "Оценка по физике";

    for(int j = 0; j < physics_mark.size(); j++) {
        if(!(physics_mark[j].isDigit())) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }

        else if(physics_mark.toInt() > 100 || physics_mark.toInt() < 1) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }
    }
    }

    if(result) {
        str = "Оценка по русскому языку";

    for(int j = 0; j < rus_language_mark.size(); j++) {
        if(!rus_language_mark[j].isDigit()) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }

        else if(rus_language_mark.toInt() > 100
             || rus_language_mark.toInt() < 1) {
            QMessageBox::critical(this, "Внимание!", str + " введена некорректно!\nПовторите попытку!");
            result = false;
            break;
        }
    }
    }

    if(result) {
        str = "Средний балл";

    for(int j = 0; j < average_point.size(); j++) {
        if(!average_point[j].isDigit()) {
            if((j == 1 && average_point[j] == '.')
            || (j == 2 && average_point[0] == '1'
            && average_point[1] == '0'
            && average_point[j] == '.')) {
              result = true;
            }
            else {
            QMessageBox::critical(this, "Внимание!", str + " введен некорректно!\nПовторите попытку!");
            result = false;
            break;
            }
        }

        else if(average_point.toInt() > 10 || average_point.toInt() < 0) {
            QMessageBox::critical(this, "Внимание!", str + " введен некорректно!\nПовторите попытку!");
            result = false;
            break;
        }
    }
    }

    if(result){

    int math = math_mark.toInt();

    int physics = physics_mark.toInt();

    int rus_lang = rus_language_mark.toInt();

    double aver_point = average_point.toDouble();

    students[ind].SetInfo(fio, speciality, aver_point, math, rus_lang, physics);

    ui->lineEdit_2->clear();

    ui->lineEdit->clear();

    ui->lineEdit_3->clear();

    ui->lineEdit_4->clear();

    ui->lineEdit_5->clear();

    ui->ghj->clear();

    QFile file(fileName);
    QByteArray daata;

    try {

    file.open(QIODevice::WriteOnly | QIODevice::Truncate);

    file.close();

    if(file.open(QIODevice::Append)){

     for(int j = 0; j < a; j++) {

        daata = QByteArray::fromStdString(students[j].info_student().toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(students[j].speciality_student().toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(QString::number(students[j].aver_point()).toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(QString::number(students[j].rus_language_mark()).toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(QString::number(students[j].physics_mark()).toStdString());

        file.write("\n" + daata);

        daata = QByteArray::fromStdString(QString::number(students[j].math_mark()).toStdString());

        file.write("\n" + daata);


         }
     QMessageBox::about(this, "ИНФОРМАЦИЯ", "Данные успешно изменены!");

        }
    }

    catch(...) {
        QMessageBox::critical(this, "Внимание!", "Не удалось открыть выбранный вами файл!");
    }

    ui->edit_abitur->show();

    ui->delete_abiturs->show();

    ui->label_8->hide();

    ui->delete_abiturs->show();

    ui->delete_abitur->show();

    ui->fio->hide();

    ui->exit1->hide();

    ui->studentsbox->hide();

    ui->pushButton_2->show();

    ui->pushButton_5->show();

    ui->pushButton_3->hide();

    ui->info_special->hide();

    ui->info_speciality->show();

    ui->listWidget->hide();

    ui->pushButton_6->show();

    ui->pushButton->show();

    ui->textEdit->hide();

    ui->list_of_abitur->hide();

    ui->label->hide();

    ui->label_2->hide();

    ui->label_3->hide();

    ui->label_4->hide();

    ui->label_5->hide();

    ui->label_6->hide();

    ui->lineEdit_2->hide();

    ui->lineEdit->hide();

    ui->lineEdit_3->hide();

    ui->lineEdit_4->hide();

    ui->lineEdit_5->hide();

    ui->label_7->hide();

    ui->choice->hide();

    ui->edit_ab->hide();

    ui->choice2->hide();

    ui->FIO->hide();

    ui->ghj->hide();

    ui->editinfo->hide();

    ui->FilePath->show();

    ui->choicepath->show();

    ui->save->hide();
    }
}


void MainWindow::on_choicepath_clicked()
{
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
             result = 0;
    str = file.readLine().trimmed();
    if(str.size() == 0) {
         result++;
    }

    str = file.readLine().trimmed();
    if(str.size() == 0) {
         result++;
    }

    str = file.readLine().trimmed();
    bool prom_result = true;

    for(int j = 0; j < str.size(); j++) {
        if(!str[j].isDigit()) {
            if((j == 1 && str[j] == '.')
            || (j == 2 && str[0] == '1'
            && str[1] == '0'
            && str[j] == '.')) {
              prom_result = true;
            }
            else {
            prom_result = false;
            break;
            }
        }

        else if(str.toInt() > 10 || str.toInt() < 0) {
            prom_result = false;
            break;
        }
    }

    if(str.size() == 0 || !prom_result) {

         result++;
    }

    prom_result = true;

    str = file.readLine().trimmed();

    for(int j = 0; j < str.size(); j++) {
        if(!(str[j].isDigit())) {
            prom_result = false;
            break;
        }

        else if(str.toInt() > 100 || str.toInt() < 1) {
            prom_result = false;
            break;
        }
    }

    if(str.size() == 0 || !prom_result) {

         result++;
    }

    prom_result = true;

    str = file.readLine().trimmed();

    for(int j = 0; j < str.size(); j++) {
        if(!(str[j].isDigit())) {
            prom_result = false;
            break;
        }

        else if(str.toInt() > 100 || str.toInt() < 1) {
            prom_result = false;
            break;
        }
    }

    if(str.size() == 0 || !prom_result) {

         result++;
    }

    prom_result = true;

    str = file.readLine().trimmed();

    for(int j = 0; j < str.size(); j++) {
        if(!(str[j].isDigit())) {
            prom_result = false;
            break;
        }

        else if(str.toInt() > 100 || str.toInt() < 1) {
            prom_result = false;
            break;
        }
    }

    if(str.size() == 0 || !prom_result) {

         result++;
    }

    if(result == 0){
      fileName = nameFile;
       ui->FilePath->setText(fileName);
    }

    if(result > 0) {
         QMessageBox::critical(this, "Внимание!", "Выбранный вами файл не может быть использован\nв качестве источника ресурсов, так как он \nсодержит неподходящие данные");
         break;
    }

    }
    }

    catch (...) {
         QMessageBox::critical(this, "Внимание!", "Не удалось открыть выбранный вами файл!");
    }

}
