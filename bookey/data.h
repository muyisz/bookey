#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
#include <vector>
#include "model.h"

class Database {
private:
    QSqlDatabase db;
public:
    Database();
    ~Database();
    bool checkLoginData(long long, QString, bool);
    std::vector<Book> getBookList();
    std::vector<Student> getStudentList();
    std::vector<Book> getStudentBooks(Student *);
};

#endif // DATABASE_H
