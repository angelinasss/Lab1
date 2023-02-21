#ifndef STUDENTS_H
#define STUDENTS_H

#include <QDialog>

namespace Ui {
class Students;
}

class Students : public QDialog
{
    Q_OBJECT

public:
    explicit Students(QWidget *parent = nullptr);
    ~Students();

private:
    Ui::Students *ui;
};

class Student
{
    QString surname, speciality;
    double average_point;
    int math, rus_language, physics, sum;

public:
   void SetInfo(QString Surname, QString Speciality, double Average_point, int Math, int Rus_language, int Physics);

   int math_mark();

   int physics_mark();

   int rus_language_mark();

   double aver_point();

   QString info_student();

   QString speciality_student();

   void FIO(QString Surname);

   void specialit(QString Speciality);

   void averpo(double Average_point);

   void mathem(int Math);

   void ruslang(int Rus_language);

   void phys(int Physics);

   void getsum(int Sum);

   bool compare(Student a, Student b);

};

#endif // STUDENTS_H
