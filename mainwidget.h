#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "customerwidget.h"
#include "adminwidget.h"


#include <bits/stdc++.h>
using namespace std;

class MainWidget : public QMainWindow
{
    Q_OBJECT
private:
    CustomerWidget *customer;

public:
    explicit MainWidget(QWidget *parent = nullptr);

//    vector <Order*> AllOrdersVect;
//        Order customizedOrder;

//        Table tablesArr;


signals:

public slots:
};

#endif // MAINWIDGET_H
