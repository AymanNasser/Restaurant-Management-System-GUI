#ifndef CUSTOMERWIDGET_H
#define CUSTOMERWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPlainTextEdit>
#include <QToolBar>
#include <QAction>
#include <QGridLayout>
#include <QString>
#include <QIcon>
#include <QCoreApplication>
#include <QMessageBox>
#include <QPushButton>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QSpinBox>
#include <QDebug>
#include <QLineEdit>

#include <bits/stdc++.h>


#include "menu.h"
#include "table.h"

using namespace std;


class CustomerWidget : public QWidget
{
    Q_OBJECT

private:
    QToolBar *toolBar, *toolBarMenu;
    QToolBar *toolBarTable[3];
    QGridLayout *custGrid;
    QMessageBox *errorMessage;
    QPlainTextEdit *plainText;
    QPushButton *submit,*reserveTable;
    Table *systemTable;
    QLineEdit *tableNumber;




public:
    explicit CustomerWidget(QWidget *parent = nullptr);

    Menu *integratedMenu;

    // Adjusting Main ToolBar
    void adjustMainToolBar();

    // Adjusting Menu ToolBar
    void adjustMenuToolBar();

    // Adjusting table toolbar
    void adjustTableToolBar();

    // Connect signals & slots in a single function
    void connectSigSlot();

    void viewMenu();

    void viewTable();


signals:

public slots:
    void handleToolBar(QAction*);
    void feedbackSubmitted();
    void setTable();


};

#endif // CUSTOMERWIDGET_H
