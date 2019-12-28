#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <bits/stdc++.h>
using namespace std;


class Table
{
private:
    bool status;
public:
    Table();
    bool getTableStatus();
    void setTableStatus();

};

#endif // TABLE_H
