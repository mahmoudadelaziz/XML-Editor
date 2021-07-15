#ifndef FORM_H
#define FORM_H
#include<QDialog>
#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(QString s);
    ~Form();

private:
Ui::Form *ui;
//Ui::Form *TextEdit;
};

#endif // FORM_H
