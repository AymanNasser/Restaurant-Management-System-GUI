#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminWidget w;
    CustomerWidget c;
    MainWidget m;
    c.showNormal();

    return a.exec();
}
