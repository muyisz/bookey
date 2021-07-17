#include "model.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include <iostream>
#include <QVariant>

User::User(long long id, QString password){
    this->id=id;
    this->password=password;
}

User::~User(){
}

long long User::getID(){
    return id;
}

QString Student::getName(){
    return name;
}

void Student::setName(QString name) {
    this->name = name;
}

Student::Student(long long id, QString password):User(id,password){}

Student::~Student(){}

std::vector<int> Student::showMyBooks() {
    return this->have;
}

void Student::initInfo() {
    QString sql = "select * from student where id = %1";
    QString id = QString::number(this->getID());
    sql = sql.arg(id);
    QSqlQuery query;
    int flag = query.exec(sql);
    if (flag && query.next()) {
        this->setName(query.value(2).toString());
        QString books = query.value(3).toString();
        auto temp = books.split(" ");
        for (int i = 0; i < temp.length(); i++) {
            int book = temp[i].toInt();
            this->have.push_back(book);
        }
    }
}

void Student::borrowBook(long long id){
    if (find(have.begin(), have.end(), id) == have.end()) {
        have.push_back(id);
    }
    QString books;
    for (auto i : have) {
        books += QString::fromStdString(std::to_string(i)) + " ";
    }
    QSqlQuery query;
    QString sql = "update student set book = %1 where id = %2";
    sql = sql.arg(books);
    sql = sql.arg(this->getID());
    query.exec(sql);
    sql = "update book set state = %1 where id = %2";
    sql = sql.arg(true);
    sql = sql.arg(id);
    query.exec(sql);
}

void Student::returnBook(long long id){
    auto it = find(have.begin(), have.end(), id);
    if (it != have.end()) {
        have.erase(it);
    }
    QString books;
    for (auto i : have) {
        books += QString::fromStdString(std::to_string(i)) + " ";
    }
    QSqlQuery query;
    QString sql = "update student set book = %1 where id = %2";
    sql = sql.arg(books);
    sql = sql.arg(this->getID());
    query.exec(sql);
    sql = "update book set state = %1 where id = %2";
    sql = sql.arg(false);
    sql = sql.arg(id);
    query.exec(sql);
}

Admin::Admin(long long id, QString password):User(id,password){}

Admin::~Admin(){}

void Admin::appendBook(Book book) {
    QString sql = "insert into book(id,name,state,info) values(%1,%2,%3,%4)";
    sql = sql.arg(book.getID());
    sql = sql.arg("\""+book.getName()+"\"");
    sql = sql.arg(book.getState());
    sql = sql.arg("\""+book.getInfo()+"\"");
    QSqlQuery query;
    int fa=query.exec(sql);
    std::cout<<fa<<std::endl;
}

void Admin::deleteBook(long long id) {
    QSqlQuery query;
    QString sql = "delete from book where id = %1";
    sql = sql.arg(id);
    query.exec(sql);
}

QString Book::getName(){
    return name;
}

QString Book::getInfo(){
    return info;
}

bool Book::getState(){
    return state;
}

long long Book::getID(){
    return id;
}

Book::Book(long long id, QString name, bool state, QString info){
    this->id=id;
    this->name=name;
    this->info=info;
    this->state=state;
}

Book::~Book(){}

//insert into book(id,name,state,info) values(2,asd,0,asd);
