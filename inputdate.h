#ifndef INPUTDATE_H
#define INPUTDATE_H
#include <QDialog>

namespace Ui {
class InputDate;
}

class InputDate : public QDialog
{
    Q_OBJECT

public:
    explicit InputDate(QWidget *parent = nullptr);
    ~InputDate();

private slots:
    void on_pushButtonOK_clicked();

private:
    Ui::InputDate *ui;
};

#endif // INPUTDATE_H
