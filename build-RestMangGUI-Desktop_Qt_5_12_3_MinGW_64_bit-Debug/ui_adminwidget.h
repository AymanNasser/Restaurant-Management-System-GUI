/********************************************************************************
** Form generated from reading UI file 'adminwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIDGET_H
#define UI_ADMINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWidget
{
public:
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit;
    QTreeWidget *treeWidget;
    QSpinBox *spinBox;

    void setupUi(QWidget *AdminWidget)
    {
        if (AdminWidget->objectName().isEmpty())
            AdminWidget->setObjectName(QString::fromUtf8("AdminWidget"));
        AdminWidget->resize(823, 561);
        lineEdit = new QLineEdit(AdminWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 170, 113, 22));
        plainTextEdit = new QPlainTextEdit(AdminWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(410, 80, 104, 87));
        treeWidget = new QTreeWidget(AdminWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(520, 170, 256, 192));
        spinBox = new QSpinBox(AdminWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(270, 230, 42, 22));

        retranslateUi(AdminWidget);

        QMetaObject::connectSlotsByName(AdminWidget);
    } // setupUi

    void retranslateUi(QWidget *AdminWidget)
    {
        AdminWidget->setWindowTitle(QApplication::translate("AdminWidget", "AdminWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWidget: public Ui_AdminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
