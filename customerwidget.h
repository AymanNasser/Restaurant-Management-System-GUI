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
#include "menu.h"
#include <bits/stdc++.h>

using namespace std;


class CustomerWidget : public QWidget
{
    Q_OBJECT

private:
    QToolBar *toolBar, *toolBarMenu;
    QGridLayout *custGrid;
    QMessageBox *errorMessage;
    QPlainTextEdit *plainText;
    QPushButton *submit;





public:
    explicit CustomerWidget(QWidget *parent = nullptr);

    Menu *integratedMenu;

    // Adjusting Main ToolBar
    void adjustMainToolBar();

    // Adjusting Menu ToolBar
    void adjustMenuToolBar();

    // Connect signals & slots in a single function
    void connectSigSlot();

    void viewMenu();






signals:

public slots:
    void handleToolBar(QAction*);
    void feedbackSubmitted();


};

#endif // CUSTOMERWIDGET_H
