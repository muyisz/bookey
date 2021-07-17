#include "bor.h"
#include "ui_bor.h"
#include "control.h"

bor::bor(control *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bor)
{
    this->c=c;
    ui->setupUi(this);
}

bor::~bor()
{
    delete ui;
}

void bor::on_bo_clicked()
{
    long long id=ui->id->text().toLongLong();
    ui->id->clear();
    c->borBook(id);
    c->showDash();
}
