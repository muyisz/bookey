#include "data.h"

Database::Database() {
    QMessageBox alert;
    this->db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("49.234.35.49");
    db.setPort(3306);
    db.setDatabaseName("bookey");
    db.setUserName("root");
    db.setPassword("256275");
    if (!db.open()) {
        alert.setText("Can't connect with the database!");
        alert.exec();
    }
}

Database::~Database() {
    this->db.close();
}

bool Database::checkLoginData(long long nowID,QString nowPassword, bool type) {
    if (type == true) {
        QSqlQuery query;
        QString sql = "select password from admin where id = %1";
        sql = sql.arg(nowID);
        int flag = query.exec(sql);
        if (flag && query.next()) {
            QString pwd = query.value(0).toString();
            if (nowPassword == pwd) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        QSqlQuery query;
        QString sql = "select password from student where id = %1";
        sql = sql.arg(nowID);
        int flag = query.exec(sql);
        if (flag && query.next()) {
            QString pwd = query.value(0).toString();
            if (nowPassword == pwd) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}

std::vector<Book> Database::getBookList() {
    QSqlQuery query;
    int flag = query.exec("select * from book");
    std::vector<Book> res;
    while(flag && query.next()) {
        long long id = query.value(0).toLongLong();
        QString name = query.value(1).toString();
        bool state = query.value(2).toBool();
        QString info = query.value(3).toString();
        Book book(id, name, state, info);
        res.push_back(book);
    }
    return res;
}

std::vector<Student> Database::getStudentList() {
    QSqlQuery query;
    int flag = query.exec("select * from student");
    std::vector<Student> res;
    while(flag && query.next()) {
        long long id = query.value(0).toLongLong();
        QString password = query.value(1).toString();
        QString name = query.value(2).toString();
        Student student(id, password);
        student.setName(name);
        res.push_back(student);
    }
    return res;
}

std::vector<Book> Database::getStudentBooks(Student *student) {
    std::vector<Book> res;
    auto list = student->showMyBooks();
    for (auto i : list) {
        QString sql = "select * from book where id = %1";
        sql = sql.arg(i);
        QSqlQuery query;
        int flag = query.exec(sql);
        if (flag && query.next()) {
            long long id = query.value(0).toLongLong();
            QString name = query.value(1).toString();
            bool state = query.value(2).toBool();
            QString info = query.value(3).toString();
            Book book(id, name, state, info);
            res.push_back(book);
        }
    }
    return res;
}
