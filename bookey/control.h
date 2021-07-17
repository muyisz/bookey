#ifndef CONTROL_H
#define CONTROL_H

#include "admin.h"
#include "dash.h"
#include "login.h"
#include "model.h"
#include "QWidget"
#include "deletebook.h"
#include "data.h"
#include "bor.h"
#include "ret.h"
#include "addbok.h"
#include <vector>

class control
{
public:
    Admin *manager;
    Student *student;
    Database *data;
    control();
    ~control();
    void showLogin();
    void showDash();
    void showAdmin();
    void showBor();
    void showRet();
    void showDeletebok();
    void showAddbok();
    void setUser(long long, QString, bool);
    bool checkUser(long long,QString,bool);
    std::vector<Book> getAdminBook();
    std::vector<Student> getAdminUser();
    long long getUserId();
    QString getUserName();
    std::vector<Book> getDashBook();
    std::vector<Book> getDashMybook();
    void borBook(long long id);
    void retBook(long long id);
private:
    admin *ad;
    dash *da;
    login *lo;
    bor *bo;
    addbok *add;
    deletebook *de;
    ret *re;
    // object for now use
    QWidget *widget;
};

#endif // CONTROL_H
