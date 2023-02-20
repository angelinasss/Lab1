<<<<<<< Updated upstream
#include "students.h"
#include "ui_students.h"

Students::Students(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Students)
{
    ui->setupUi(this);
}

Students::~Students()
{
    delete ui;
}

void Student::SetInfo(QString Surname, QString Speciality, double Average_point, int Math, int Rus_language, int Physics)
{
  surname = Surname;

  speciality = Speciality;

  average_point = Average_point;

  math = Math;

  rus_language = Rus_language;

  physics = Physics;
}

void Student::FIO(QString Surname)
{
  surname = Surname;
}

void Student::specialit(QString Speciality)
{
 speciality = Speciality;
}

void Student::averpo(double Average_point)
{
 average_point = Average_point;
}

void Student::mathem(int Math)
{
    math = Math;
}

void Student::ruslang(int Rus_language)
{
 rus_language = Rus_language;
}

void Student::phys(int Physics)
{
 physics = Physics;
}

int Student::math_mark()
{
  return math;
}

int Student::physics_mark()
{
  return physics;
}

int Student::rus_language_mark()
{
  return rus_language;
}

double Student::aver_point()
{
  return average_point;
}

QString Student::info_student()
{
  return surname;
}

QString Student::speciality_student()
{
  return speciality;
}

void Student::getsum(int Sum) {
    sum = Sum;
}

bool Student::compare(Student a, Student b) {
    return a.sum < b.sum;
};

=======
#include "students.h"
#include "ui_students.h"

Students::Students(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Students)
{
    ui->setupUi(this);
}

Students::~Students()
{
    delete ui;
}

void Student::SetInfo(QString Surname, QString Speciality, double Average_point, int Math, int Rus_language, int Physics)
{
  surname = Surname;

  speciality = Speciality;

  average_point = Average_point;

  math = Math;

  rus_language = Rus_language;

  physics = Physics;
}

void Student::FIO(QString Surname)
{
  surname = Surname;
}

void Student::specialit(QString Speciality)
{
 speciality = Speciality;
}

void Student::averpo(double Average_point)
{
 average_point = Average_point;
}

void Student::mathem(int Math)
{
    math = Math;
}

void Student::ruslang(int Rus_language)
{
 rus_language = Rus_language;
}

void Student::phys(int Physics)
{
 physics = Physics;
}

int Student::math_mark()
{
  return math;
}

int Student::physics_mark()
{
  return physics;
}

int Student::rus_language_mark()
{
  return rus_language;
}

double Student::aver_point()
{
  return average_point;
}

QString Student::info_student()
{
  return surname;
}

QString Student::speciality_student()
{
  return speciality;
}

void Student::getsum(int Sum) {
    sum = Sum;
}

bool Student::compare(Student a, Student b) {
    return a.sum < b.sum;
};

>>>>>>> Stashed changes
