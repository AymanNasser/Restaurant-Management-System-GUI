#include "adminwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminWidget w;
    w.showNormal();

    return a.exec();
}
