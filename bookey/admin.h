#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>

namespace Ui {
class admin;
}

class control;

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(control *c,QWidget *parent = nullptr);
    ~admin();
    void getData();

private slots:
    void on_addbook_clicked();

    void on_delbook_clicked();

private:
    Ui::admin *ui;
    control *c;
};

#endif // ADMIN_H
