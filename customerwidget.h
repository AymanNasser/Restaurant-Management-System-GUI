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
#include <QSize>
#include <QFont>
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
#include <QToolButton>

#include <bits/stdc++.h>


#include "menu.h"
#include "table.h"

#define MENU_ITEM_NO 5
using namespace std;


static bool MENU_FLAG, FEEDBACK_FLAG, TABLE_FLAG;


class CustomerWidget : public QWidget
{
    Q_OBJECT

private:
    QToolBar *toolBar, *toolBarMenu;
    QToolBar *toolBarTable[3];
    QGridLayout *custGrid;
    QMessageBox *errorMessage;
    QPlainTextEdit *plainText;
    QPushButton *reserveTable;
    Table *systemTable;
    QLineEdit *tableNumber, *orderPrice;
    QPushButton *order,*submit;
    QSpinBox *spinBox[MENU_ITEM_NO];
    const QString iconPath = QCoreApplication::applicationDirPath() + "/../../Icons/";




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

    void menuInit();

    void calcOrderPrice();

signals:

public slots:
    void handleToolBar(QAction*);
    void feedbackSubmitted();
    void orderButton();
    void setTable();


};

#endif // CUSTOMERWIDGET_H
