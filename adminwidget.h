#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <bits/stdc++.h>

namespace Ui {
class AdminWidget;
}

class AdminWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWidget(QWidget *parent = nullptr);
    ~AdminWidget();

private:
    Ui::AdminWidget *ui;
};

#endif // ADMINWIDGET_H
