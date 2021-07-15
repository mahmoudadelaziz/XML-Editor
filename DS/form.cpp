#include "form.h"
#include "ui_form.h"

Form::Form (QString s) :
    QDialog(),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    //extEdit->setText(s);
}

Form::~Form()
{
    delete ui;
}
