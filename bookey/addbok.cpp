#include "addbok.h"
#include "control.h"
#include "ui_addbok.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <iostream>
#include <QString>

addbok::addbok(control *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addbok)
{
    this->c=c;
    ui->setupUi(this);
}

addbok::~addbok()
{
    delete ui;
}

void addbok::on_add_clicked()
{
    QString name=ui->name->text();
    QString jianjie=ui->jiajie->toPlainText();
    QSqlQuery query;
    ui->name->clear();
    ui->jiajie->clear();
    long long id;
    int flag = query.exec("select count(*) from book");
    if (flag && query.next()) {
        id = query.value(0).toLongLong() + 1;
    }
    std::cout<<id<<std::endl;
    Book book(id, name, false, jianjie);
    c->manager->appendBook(book);
    c->showAdmin();
}
