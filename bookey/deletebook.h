#ifndef DELETEBOOK_H
#define DELETEBOOK_H

#include <QWidget>

namespace Ui {
class deletebook;
}

class control;

class deletebook : public QWidget
{
    Q_OBJECT

public:
    explicit deletebook(control *c,QWidget *parent = nullptr);
    ~deletebook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deletebook *ui;
    control *c;
};

#endif // DELETEBOOK_H
