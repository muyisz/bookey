#ifndef RET_H
#define RET_H

#include <QWidget>

namespace Ui {
class ret;
}

class control;

class ret : public QWidget
{
    Q_OBJECT

public:
    explicit ret(control *c,QWidget *parent = nullptr);
    ~ret();

private slots:
    void on_re_clicked();

private:
    Ui::ret *ui;
    control *c;
};

#endif // RET_H
