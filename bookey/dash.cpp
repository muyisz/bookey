#include "dash.h"
#include "ui_dash.h"
#include "control.h"
#include <vector>
#include <QMenu>
#include <QAction>

dash::dash(control *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dash)
{
    this->c=c;
    ui->setupUi(this);
    ui->bookTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->bookTable->setColumnWidth(0,50);
    ui->bookTable->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    ui->bookTable->verticalHeader()->setVisible(false);

    ui->mybook->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->mybook->setColumnWidth(0,50);
    ui->mybook->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->mybook->verticalHeader()->setVisible(false);
}

void dash::getData(){
    ui->bookTable->clearContents();
    ui->bookTable->setRowCount(0);
    ui->mybook->clearContents();
    ui->mybook->setRowCount(0);
    ui->idView->setText(QString::number(c->getUserId()));
    ui->nameView->setText(c->getUserName());
    std::vector<Book> book=c->getDashBook();
    QTableWidgetItem *item[4];
    for(auto i : book)
    {
        int nCount = ui->bookTable->rowCount();
        ui->bookTable->insertRow(nCount);
        QString id=QString::number(i.getID());
        QString name=(i.getName());
        QString info=(i.getInfo());
        QString state;
        switch (i.getState()) {
        case true: state="被借出";break;
        case false: state="未借出";break;
        }
        item[0]=new QTableWidgetItem(id);
        item[1]=new QTableWidgetItem(name);
        item[2]=new QTableWidgetItem(state);
        item[3]=new QTableWidgetItem(info);
        ui->bookTable->setItem(nCount,0,item[0]);
        ui->bookTable->setItem(nCount,1,item[1]);
        ui->bookTable->setItem(nCount,2,item[2]);
        ui->bookTable->setItem(nCount,3,item[3]);
    }

    std::vector<Book> mybook=c->getDashMybook();
    for(auto i:mybook){
        int nCount = ui->mybook->rowCount();
         ui->mybook->insertRow(nCount);
         QString id=QString::number(i.getID());
         QString name=i.getName();
         item[0]=new QTableWidgetItem(id);
         item[1]=new QTableWidgetItem(name);
         ui->mybook->setItem(nCount,0,item[0]);
         ui->mybook->setItem(nCount,1,item[1]);
    }

}

dash::~dash()
{
    delete ui;
}

void dash::on_bor_clicked()
{
    c->showBor();
}

void dash::on_ret_clicked()
{
    c->showRet();
}

