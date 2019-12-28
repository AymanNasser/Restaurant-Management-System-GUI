#include "customerwidget.h"

CustomerWidget::CustomerWidget(QWidget *parent) : QWidget(parent)
{
        toolBar = new QToolBar();
        custGrid = new QGridLayout();
        errorMessage = new QMessageBox();

        toolBarMenu = new QToolBar();
        submit = new QPushButton("Submit FeedBack");
        reserveTable = new QPushButton("Reserve Table");

        tableNumber = new QLineEdit();

        toolBarTable[0] = new QToolBar();
        toolBarTable[1] = new QToolBar();
        toolBarTable[2] = new QToolBar();


        systemTable = new Table[6];

        adjustMainToolBar();
        //adjustMenuToolBar();
        adjustTableToolBar();

        connectSigSlot();

        this->setLayout(this->custGrid);


        integratedMenu = new Menu();

        Item menuItems ;

        menuItems.setItem(0,55.65,1,1,"Shay");
        integratedMenu->addItem(menuItems);

        menuItems.setItem(1,30,1,2,"Salata");
        integratedMenu->addItem(menuItems);

        menuItems.setItem(1,80,1,3,"la7ma");
        integratedMenu->addItem(menuItems);

        menuItems.setItem(1,70.5,4,1,"fra5");
        integratedMenu->addItem(menuItems);

        menuItems.setItem(1,10.5,4,1,"Betngan");
        integratedMenu->addItem(menuItems);





}

void CustomerWidget::adjustMainToolBar()
{
    QString iconPath = QCoreApplication::applicationDirPath() + "/../../Icons/";

    QIcon I_Order(iconPath + "meal.png"); QString S_Order("Order");
    QIcon I_Menu(iconPath + "menu.png"); QString S_Menu("Menu");
    QIcon I_FeedBack(iconPath + "questionnaire.png"); QString S_FeedBack("FeedBack");
    QIcon I_Table(iconPath + "table.png"); QString S_Table("Table");
    QIcon I_Status(iconPath + "loading.png"); QString S_Status("Status");

    toolBar->setIconSize(QSize(70,70));
    toolBar->setOrientation(Qt::Horizontal);
    toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    toolBar->setFont(QFont("Helvetica [Cronyx]",9,65,0));

    toolBar->addAction(I_Order,S_Order);
    toolBar->addAction(I_Menu,S_Menu);
    toolBar->addAction(I_FeedBack,S_FeedBack);
    toolBar->addAction(I_Table,S_Table);
    toolBar->addAction(I_Status,S_Status);

    custGrid->addWidget(toolBar,0,0,1,-1);
}

void CustomerWidget::adjustMenuToolBar()
{
    toolBarMenu->setIconSize(QSize(70,70));
    toolBarMenu->setOrientation(Qt::Horizontal);
    toolBarMenu->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    toolBarMenu->setFont(QFont("Helvetica [Cronyx]",9,65,0));
}

void CustomerWidget::adjustTableToolBar()
{
    for (int i = 0;i<3;i++)
    {
        toolBarTable[i]->setIconSize(QSize(70,70));
        toolBarTable[i]->setOrientation(Qt::Vertical);
        toolBarTable[i]->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        toolBarTable[i]->setFont(QFont("Helvetica [Cronyx]",9,65,0));
    }
}

void CustomerWidget::connectSigSlot()
{
    // Toolbar Connect
    connect(toolBar,SIGNAL(actionTriggered(QAction *)),this,SLOT(handleToolBar(QAction*)));


    // Submit QPushButton connect
    connect(submit,SIGNAL(clicked()),this,SLOT(feedbackSubmitted()));

    connect(reserveTable,SIGNAL(clicked()),this,SLOT(setTable()));
}



void CustomerWidget::handleToolBar(QAction *trigAction)
{
    float sum = 0;
    static char flag1 = 0;
    static char flag2 = 0;
    static char flag3 = 0;
    static char flag4 = 0;

    if(trigAction->text() == "Order" && flag1 == 0)
    {

        flag2 = 0; flag3 = 0; flag4 = 0;
        for (unsigned int i = 0;i < integratedMenu->getMenuSize();i++)
        {
            sum += integratedMenu->MainMenu[i].getSpinBox()->value() *
                   integratedMenu->MainMenu[i].get_price();

        }
        flag1 = 1;

    }
    else if (trigAction->text() == "Menu" && flag2 == 0)
    {
        if(flag4 == 1 )
        {

            delete toolBarTable[0];
            delete toolBarTable[1];
            delete toolBarTable[2];
            delete reserveTable;
            delete tableNumber;
        }
        else if (flag3 == 1)
        {
            delete plainText;
            delete submit;
        }
        flag1 = 0; flag3 = 0; flag4 = 0;
        viewMenu();
        flag2 = 1;

    }
    else if (trigAction->text() == "Status")
    {

    }

    else if (trigAction->text() == "FeedBack" && flag3 == 0)
    {
        if(flag4 == 1 )
        {

            delete toolBarTable[0];
            delete toolBarTable[1];
            delete toolBarTable[2];
            delete reserveTable;
            delete tableNumber;
        }
        else if (flag2 == 1)
        {
            delete toolBarMenu;
            for (int i =0;i< integratedMenu->getMenuSize() ;i++)
            {
                delete integratedMenu->MainMenu[i].getSpinBox();
            }
        }
        flag1 = 0; flag2 = 0; flag4 = 0;
        plainText = new QPlainTextEdit();
        custGrid->addWidget(plainText,1,0,-1,4);
        custGrid->addWidget(submit,5,4,1,1);
        flag3 = 1;
    }
    else if (trigAction->text() == "Table" && flag4 == 0)
    {
        if(flag3 == 1 )
        {
            delete plainText;
            delete submit;
        }
        else if (flag2 == 1)
        {
            delete toolBarMenu;
            for (int i =0;i< integratedMenu->getMenuSize() ;i++)
            {
                delete integratedMenu->MainMenu[i].getSpinBox();
            }
        }
        flag1 = 0; flag2 = 0; flag3 = 0;
        viewTable();
        custGrid->addWidget(tableNumber,7,3,1,1);
        custGrid->addWidget(reserveTable,6,3,1,1);
        flag4 = 1;
    }
    else
    {

    }


}

void CustomerWidget::feedbackSubmitted()
{

    QStringList *list = new QStringList();
    QString *temp = new QString(plainText->toPlainText());
    list->append(temp->split("\n"));

    QFile feedbackFile( QCoreApplication::applicationDirPath() + "/../../feedback.txt");
    if(feedbackFile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&feedbackFile);
        char i =0;
        while(i < list->size())
        {

            stream << list->at(i) +"\n";
            i++;
        }

        feedbackFile.close();
        delete plainText;
        delete submit;

    }
    else{}

}

void CustomerWidget::viewMenu()
{
    toolBarMenu = new QToolBar();
    for (int i =0;i< integratedMenu->getMenuSize() ;i++)
    {
        integratedMenu->MainMenu[i].setSpinBox();
    }
    adjustMenuToolBar();
    QString iconPath = QCoreApplication::applicationDirPath() + "/../../Icons/";
    for (int i =0;i< integratedMenu->getMenuSize() ;i++)
    {
        QIcon I_Order(iconPath + "meal.png");
        QString item(integratedMenu->MainMenu[i].get_itemname());
        toolBarMenu->addAction(I_Order,item);
        custGrid->addWidget(integratedMenu->MainMenu[i].getSpinBox(),3,1+i,1,1);
    }
    custGrid->addWidget(toolBarMenu,2,1,2,2);
}

void CustomerWidget::viewTable()
{

    QString tableIconPath = QCoreApplication::applicationDirPath() + "/../../Icons/";

    QIcon I_Table1(tableIconPath + "table.png"); QString S_Table1("Table 1 \nStatus: " + systemTable[0].getTableStatus());
    QIcon I_Table2(tableIconPath + "table.png"); QString S_Table2("Table 2 \nStatus: " + systemTable[1].getTableStatus());
    QIcon I_Table3(tableIconPath + "table.png"); QString S_Table3("Table 3 \nStatus: " + systemTable[2].getTableStatus());
    QIcon I_Table4(tableIconPath + "table.png"); QString S_Table4("Table 4 \nStatus: " + systemTable[3].getTableStatus());
    QIcon I_Table5(tableIconPath + "table.png"); QString S_Table5("Table 5 \nStatus: " + systemTable[4].getTableStatus());
    QIcon I_Table6(tableIconPath + "table.png"); QString S_Table6("Table 6 \nStatus: " + systemTable[5].getTableStatus());

    toolBarTable[0]->addAction(I_Table1,S_Table1);
    toolBarTable[0]->addAction(I_Table2,S_Table2);

    toolBarTable[1]->addAction(I_Table3,S_Table3);
    toolBarTable[1]->addAction(I_Table4,S_Table4);

    toolBarTable[2]->addAction(I_Table5,S_Table5);
    toolBarTable[2]->addAction(I_Table6,S_Table6);

    custGrid->addWidget(toolBarTable[0],5,2,1,1);
    custGrid->addWidget(toolBarTable[1],5,3,1,1);
    custGrid->addWidget(toolBarTable[2],5,4,1,1);

}

void CustomerWidget::setTable()
{
    if(tableNumber->isModified())
    {
        systemTable[tableNumber->text().toInt()-1].setTableStatus();
        viewTable();

    }

    else
    {
        errorMessage->setInformativeText("Please Specify Table No.");
        errorMessage->show();
    }

}














