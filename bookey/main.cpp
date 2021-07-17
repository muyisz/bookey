#include "control.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    control c;
    qDebug()<<"可执行文件所在目录:"<<QCoreApplication::applicationDirPath();
    return a.exec();
}
