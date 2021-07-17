#ifndef BOR_H
#define BOR_H

#include <QWidget>

namespace Ui {
class bor;
}

class control;

class bor : public QWidget
{
    Q_OBJECT

public:
    explicit bor(control *c,QWidget *parent = nullptr);
    ~bor();

private slots:
    void on_bo_clicked();

private:
    Ui::bor *ui;
    control *c;
};

#endif // BOR_H
