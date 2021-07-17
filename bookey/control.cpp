#include "control.h"
#include "admin.h"
#include <QString>

control::control()
{
    lo=new login(this);
    ad=new admin(this);
    da=new dash(this);
    bo=new bor(this);
    re=new ret(this);
    de=new deletebook(this);
    add=new addbok(this);
    widget=lo;
    widget->show();
    data = new Database();
}

void control::retBook(long long id){
    this->student->returnBook(id);
}

void control::showBor(){
    widget->hide();
    widget=bo;
    widget->show();
}

void control::showRet(){
    widget->hide();
    widget=re;
    widget->show();
}

void control::borBook(long long id){
    this->student->borrowBook(id);
}

control::~control(){
    delete re;
    delete bo;
    delete lo;
    delete ad;
    delete add;
    delete de;
    delete da;
    if (student != NULL) {
        delete student;
    }
    if (manager != NULL) {
        delete manager;
    }
    delete data;
}

void control::setUser(long long id, QString password, bool type){
    if (type == true) {
        // admin
        this->manager = new Admin(id, password);
        this->student = NULL;
    } else {
        // student
        this->student = new Student(id, password);
        this->manager = NULL;
    }
}

void control::showDash(){
    widget->hide();
    widget=da;
    da->getData();
    widget->show();
}

void control::showAdmin(){
    widget->hide();
    widget=ad;
    ad->getData();
    widget->show();
}

void control::showDeletebok(){
    widget->hide();
    widget=de;
    widget->show();
}

void control::showAddbok(){
    widget->hide();
    widget=add;
    add->show();
}

void control::showLogin(){
    widget->hide();
    widget=lo;
    widget->show();
}

bool control::checkUser(long long id,QString password,bool type){
    return this->data->checkLoginData(id, password, type);
}

std::vector<Book> control::getDashBook(){
    return this->data->getBookList();
}

long long control::getUserId(){
    return this->student->getID();
}

QString control::getUserName(){
    return this->student->getName();
}

std::vector<Book> control::getAdminBook(){
    return this->data->getBookList();
}

std::vector<Student> control::getAdminUser(){
    return this->data->getStudentList();
}

std::vector<Book> control::getDashMybook(){
    return this->data->getStudentBooks(this->student);
}

