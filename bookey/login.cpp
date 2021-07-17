#include "login.h"
#include "ui_login.h"
#include "control.h"
#include <QString>
#include <iostream>
#include <QMessageBox>
#include "model.h"

login::login(control *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    this->c=c;
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    long long id=ui->usernameEdit->text().toLongLong();
    QString password=ui->passwordEdit->text();
    if(!ui->adminButton->isChecked()){
        if(c->checkUser(id, password, true)){
             c->setUser(id, password, false);
             c->student->initInfo();
             c->showDash();
        }else{
            std::cout<<"w1\n";
        }
    }else{
        if(c->checkUser(id, password, false)){
            c->setUser(id, password, true);
            c->showAdmin();
        }else{
            std::cout<<"w2\n";
        }
    }
}
