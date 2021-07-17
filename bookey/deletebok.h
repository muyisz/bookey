#ifndef DELETEBOK_H
#define DELETEBOK_H

#include <QWidget>

namespace Ui {
class deletebok;
}

class control;

class deletebok : public QWidget
{
    Q_OBJECT

public:
    explicit deletebok(control *c,QWidget *parent = nullptr);
    ~deletebok();

private slots:

    void on_del_clicked();

private:
    Ui::deletebok *ui;
    control *c;
};

#endif // DELETEBOK_H
