#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>

#include <bits/stdc++.h>
using namespace std;


class Table
{
private:
    bool status;
public:
    Table();
    QString getTableStatus();
    void setTableStatus();

};

#endif // TABLE_H
