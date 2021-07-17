#include "admin.h"
#include "ui_admin.h"
#include "control.h"
admin::admin(control *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    this->c=c;
    ui->setupUi(this);
    ui->book->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->book->setColumnWidth(0,50);
    ui->book->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    ui->book->verticalHeader()->setVisible(false);
    ui->name->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->name->setColumnWidth(0,100);
    ui->name->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->name->verticalHeader()->setVisible(false);
}

admin::~admin()
{
    delete ui;
}

void admin::getData(){
    ui->book->clearContents();
    ui->book->setRowCount(0);
    ui->name->clearContents();
    ui->name->setRowCount(0);
     QTableWidgetItem *item[4];
    std::vector<Student> stu=c->getAdminUser();
    for(auto i:stu){
        int nCount = ui->name->rowCount();
         ui->name->insertRow(nCount);
         QString id=QString::number(i.getID());
         QString name=i.getName();
         item[0]=new QTableWidgetItem(id);
         item[1]=new QTableWidgetItem(name);
         ui->name->setItem(nCount,0,item[0]);
         ui->name->setItem(nCount,1,item[1]);
    }

    std::vector<Book> book=c->getAdminBook();
    for(auto i : book)
    {
        int nCount = ui->book->rowCount();
        ui->book->insertRow(nCount);
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
        ui->book->setItem(nCount,0,item[0]);
        ui->book->setItem(nCount,1,item[1]);
        ui->book->setItem(nCount,2,item[2]);
        ui->book->setItem(nCount,3,item[3]);
    }
}

void admin::on_addbook_clicked()
{
    c->showAddbok();
}

void admin::on_delbook_clicked()
{
    c->showDeletebok();
}
