#include "deletebook.h"
#include "ui_deletebook.h"
#include <QString>
#include "control.h"

deletebook::deletebook(control *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deletebook)
{
    this->c=c;
    ui->setupUi(this);
}

deletebook::~deletebook()
{
    delete ui;
}

void deletebook::on_pushButton_clicked()
{
    QString id=ui->id->text();
    c->manager->deleteBook(id.toULongLong());
    ui->id->clear();
    c->showAdmin();
}
