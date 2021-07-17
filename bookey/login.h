#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class control;

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(control *c,QWidget *parent = nullptr);
    ~login();

private slots:
    void on_loginButton_clicked();

private:
    Ui::login *ui;
    control *c;
};

#endif // LOGIN_H
