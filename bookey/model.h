#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <vector>

class Book {
private:
    long long id;
    QString name;
    bool state;
    QString info;
public:
    Book(long long id, QString name, bool state, QString info);
    long long getID();
    QString getName();
    bool getState();
    QString getInfo();
    ~Book();
};

class User {
private:
    long long id;
    QString password;
public:
    User(long long, QString);
    virtual ~User()=0;
    long long getID();
    QString getPassword();
};

class Student:public User {
private:
    QString name;
    std::vector<int> have;
public:
    Student(long long, QString);
    ~Student();
    void setName(QString);
    void initInfo();
    QString getName();
    std::vector<int> showMyBooks();
    void borrowBook(long long id);
    void returnBook(long long id);
};

class Admin:public User {
public:
    Admin(long long, QString);
    ~Admin();
    void appendBook(Book);
    void deleteBook(long long id);
};

#endif // MODEL_H
