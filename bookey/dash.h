#ifndef DASH_H
#define DASH_H

#include <QWidget>

namespace Ui {
class dash;
}

class control;

class dash : public QWidget
{
    Q_OBJECT

public:
    explicit dash(control *c,QWidget *parent = nullptr);
    ~dash();
    void getData();
private slots:
    void on_bor_clicked();

    void on_ret_clicked();

private:
    Ui::dash *ui;
    control *c;
};

#endif // DASH_H
