#include "deletebok.h"
#include "ui_deletebok.h"
#include "control.h"

deletebok::deletebok(control *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deletebok)
{
    this->c=c;
    ui->setupUi(this);
}

deletebok::~deletebok()
{
    delete ui;
}


void deletebok::on_del_clicked()
{
 //   QString id=ui->id->text();
//    c->manager->deleteBook(id.toLongLong());
    c->showDash();
}
