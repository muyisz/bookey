#include "ret.h"
#include "ui_ret.h"
#include "control.h"

ret::ret(control *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ret)
{
    this->c=c;
    ui->setupUi(this);
}

ret::~ret()
{
    delete ui;
}

void ret::on_re_clicked()
{
    long long id=ui->id->text().toLongLong();
    c->retBook(id);
    c->showDash();
}
