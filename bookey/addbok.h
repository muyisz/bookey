#ifndef ADDBOK_H
#define ADDBOK_H

#include <QWidget>

namespace Ui {
class addbok;
}

class control;

class addbok : public QWidget
{
    Q_OBJECT

public:
    explicit addbok(control *c,QWidget *parent = nullptr);
    ~addbok();

private slots:
    void on_add_clicked();

private:
    control *c;
    Ui::addbok *ui;
};

#endif // ADDBOK_H
