#include "customerwidget.h"


CustomerWidget::CustomerWidget(QWidget *parent) : QWidget(parent)
{
    custGrid = new QGridLayout();
    this->setLayout(this->custGrid);

    toolBar = new QToolBar();
    errorMessage = new QMessageBox();

    // MainToolbar Connect
    connect(toolBar,SIGNAL(actionTriggered(QAction *)),this,SLOT(handleToolBar(QAction*)));

    // Calling GUI Flow Functions
    adjustMainToolBar();

}

void CustomerWidget::adjustMainToolBar()
{

QIcon I_Menu(iconPath + "menu.png"); QString S_Menu("Menu");
QIcon I_FeedBack(iconPath + "questionnaire.png"); QString S_FeedBack("FeedBack");
QIcon I_Table(iconPath + "table.png"); QString S_Table("Table");
QIcon I_Status(iconPath + "loading.png"); QString S_Status("Status");

toolBar->setIconSize(QSize(70,70));
toolBar->setOrientation(Qt::Horizontal);
toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
toolBar->setFont(QFont("Helvetica [Cronyx]",9,65,0));
toolBar->setAllowedAreas(Qt::ToolBarArea::LeftToolBarArea);

toolBar->addAction(I_Menu,S_Menu);
toolBar->addAction(I_FeedBack,S_FeedBack);
toolBar->addAction(I_Table,S_Table);
toolBar->addAction(I_Status,S_Status);



custGrid->addWidget(toolBar,0,0,1,1,Qt::AlignTop);

// Initializing The Global Flags
TABLE_FLAG = false;
FEEDBACK_FLAG = false;
MENU_FLAG = false;


}

void CustomerWidget::adjustMenuToolBar()
{
toolBarMenu->setIconSize(QSize(60,60));
toolBarMenu->setOrientation(Qt::Horizontal);
toolBarMenu->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
toolBarMenu->setFont(QFont("Helvetica [Cronyx]",9,65,0));
}

void CustomerWidget::adjustTableToolBar()
{
for (int i = 0;i<3;i++)
{
    toolBarTable[i]->setIconSize(QSize(100,100));
    toolBarTable[i]->setOrientation(Qt::Vertical);
    toolBarTable[i]->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
    toolBarTable[i]->setFont(QFont("Helvetica [Cronyx]",9,65,0));
}
}

void CustomerWidget::connectSigSlot()
{
connect(reserveTable,SIGNAL(clicked()),this,SLOT(setTable()));
}



void CustomerWidget::handleToolBar(QAction *trigAction)
{
if (trigAction->text() == "Menu")
{
    MENU_FLAG = true;
    if(TABLE_FLAG == 1)
    {
        deleteTable();
        TABLE_FLAG = false;
    }
    if (FEEDBACK_FLAG == 1)
    {
        deleteFeedback();
        FEEDBACK_FLAG = false;
    }

        toolBarMenu = new QToolBar();
        order = new QPushButton("Order");
        order->setMaximumSize(QSize(300,300));
        order->setStyleSheet("QPushButton{ background-color:rgba(125, 219, 70, 0.904);border-radius:10%;font-size: 17px;} "
                             "QPushButton:hover { background-color: rgba(32, 99, 30, 0.849); border-radius:10%; color:white;}");

        // Order QToolButton connect
        connect(order,SIGNAL(clicked()),this,SLOT(orderButton()));

        adjustMenuToolBar();
        menuInit();
        viewMenu();

        custGrid->addWidget(toolBarMenu,1,2,1,1,Qt::AlignCenter);

        custGrid->addWidget(order,4,3,2,2,Qt::AlignBottom);


}
else if (trigAction->text() == "Status")
{

}

else if (trigAction->text() == "FeedBack")
{
    FEEDBACK_FLAG = true;
    if(TABLE_FLAG == 1)
    {
        deleteTable();
        TABLE_FLAG = false;
    }
    if (MENU_FLAG == 1)
    {
        deleteMenu();
        MENU_FLAG = false;
    }
        submit = new QPushButton("Submit");
        submit->setMinimumSize(100,100);
        submit->setStyleSheet("QPushButton{ background-color:rgba(125, 219, 70, 0.904);border-radius:10%;font-size: 17px;} "
                              "QPushButton:hover { background-color: rgba(32, 99, 30, 0.849); border-radius:10%; color:white;}");
        plainText = new QPlainTextEdit();
        plainText->setStyleSheet("background-color:grey; font-size: 15px; color:white;");
        plainText->setPlaceholderText("Insert Your FeedBack");

        // Submit QToolButton connect
        connect(submit,SIGNAL(clicked()),this,SLOT(feedbackSubmitted()));

        // Adding Widgets to GridLayout
        custGrid->addWidget(plainText,1,1,1,-1);

        custGrid->addWidget(submit,5,5,1,1);

}
else if (trigAction->text() == "Table")
{
    TABLE_FLAG = true;
    if(MENU_FLAG == 1)
    {
        deleteMenu();
        MENU_FLAG = false;
    }
    if (FEEDBACK_FLAG == 1)
    {
        deleteFeedback();
        FEEDBACK_FLAG = false ;
    }
        viewTable();
        connect(reserveTable,SIGNAL(clicked()),this,SLOT(reserveTables()));
        adjustTableToolBar();

}

else{}


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

void CustomerWidget::orderButton()
{
calcOrderPrice();
}

void CustomerWidget::reserveTables()
{
setTable();
}

void CustomerWidget::viewMenu()
{
for (unsigned char i =0 ; i < MENU_ITEM_NO ; i++)
{
    spinBox[i] = new QSpinBox();
    spinBox[i]->setStyleSheet("border-radius:5%;border-width: 0.5px; color:black;border-style: solid; "
                              "border-color: gray ; background-color:rgb(201, 201, 201);");
    spinBox[i]->setMaximumSize(QSize(50,50));
    custGrid->addWidget(spinBox[i],2,i,1,1,Qt::AlignHCenter);
}


for (unsigned char i =0 ; i <MENU_ITEM_NO ; i++)
{
    QIcon I_Order(iconPath + QString::number(i+1) + ".png");
    QString item(integratedMenu->MainMenu[i].get_itemname());
    toolBarMenu->addAction(I_Order,item);
}

}

void CustomerWidget::viewTable()
{

reserveTable = new QPushButton("Reserve Table");
reserveTable->setMinimumSize(QSize(200,100));
reserveTable->setStyleSheet("QPushButton{ background-color:rgba(160, 160, 160, 0.849);border-radius:10%; font-size: 17px;} "
                            "QPushButton:hover { background-color: white; border-radius:10%;border-width: 0.5px; border-style: solid; "
                            "border-color: gray ;} ");
tableNumber = new QLineEdit();
tableNumber->setStyleSheet("border-radius:5%;border-width: 0.5px;color:black; border-style: solid; border-color: gray ; "
                           "background-color:rgb(201, 201, 201);");

systemTable = new Table[6];

custGrid->addWidget(reserveTable,3,1,1,1,Qt::AlignBottom | Qt::AlignCenter);
custGrid->addWidget(tableNumber,3,2,1,1,Qt::AlignBottom | Qt::AlignCenter);

toolBarTable[0] = new QToolBar();
toolBarTable[1] = new QToolBar();
toolBarTable[2] = new QToolBar();

QIcon I_Table1(iconPath + "dinner-table.png"); QString S_Table1("Table 1 \nStatus: " + systemTable[0].getTableStatus());
QIcon I_Table2(iconPath + "dinner-table.png"); QString S_Table2("Table 2 \nStatus: " + systemTable[1].getTableStatus());
QIcon I_Table3(iconPath + "dinner-table.png"); QString S_Table3("Table 3 \nStatus: " + systemTable[2].getTableStatus());
QIcon I_Table4(iconPath + "dinner-table.png"); QString S_Table4("Table 4 \nStatus: " + systemTable[3].getTableStatus());
QIcon I_Table5(iconPath + "dinner-table.png"); QString S_Table5("Table 5 \nStatus: " + systemTable[4].getTableStatus());
QIcon I_Table6(iconPath + "dinner-table.png"); QString S_Table6("Table 6 \nStatus: " + systemTable[5].getTableStatus());

toolBarTable[0]->addAction(I_Table1,S_Table1);
toolBarTable[0]->addAction(I_Table2,S_Table2);


toolBarTable[1]->addAction(I_Table3,S_Table3);
toolBarTable[1]->addAction(I_Table4,S_Table4);


toolBarTable[2]->addAction(I_Table5,S_Table5);
toolBarTable[2]->addAction(I_Table6,S_Table6);

custGrid->addWidget(toolBarTable[0],0,1,1,1,Qt::AlignVCenter | Qt::AlignLeft);
custGrid->addWidget(toolBarTable[1],0,2,1,1,Qt::AlignVCenter | Qt::AlignLeft);
custGrid->addWidget(toolBarTable[2],0,3,1,1,Qt::AlignVCenter | Qt::AlignLeft);

}

void CustomerWidget::menuInit()
{
integratedMenu = new Menu();
Item menuItems ;

menuItems.setItem(0,12,1,1,"Tea");
integratedMenu->addItem(menuItems);

menuItems.setItem(1,22,1,2,"Salad");
integratedMenu->addItem(menuItems);

menuItems.setItem(1,80,1,3,"Beef");
integratedMenu->addItem(menuItems);

menuItems.setItem(1,65,1,4,"Chicken");
integratedMenu->addItem(menuItems);

menuItems.setItem(0,8,1,5,"Water");
integratedMenu->addItem(menuItems);

menuItems.setItem(0,30,1,6,"Juice");
integratedMenu->addItem(menuItems);

}

void CustomerWidget::calcOrderPrice()
{
float sum = 0;
for (unsigned char i = 0; i < MENU_ITEM_NO ;i++)
{
    sum += spinBox[i]->value() * integratedMenu->MainMenu.at(i).get_price();
}
errorMessage->setIcon(QMessageBox::Information);
errorMessage->setTextFormat(Qt::TextFormat::RichText);
errorMessage->setInformativeText("Order Price is: " + QString::number(sum) + " L.E");
errorMessage->show();
}

void CustomerWidget::deleteMenu()
{
delete toolBarMenu;
//delete orderPrice;
delete order;
for (unsigned char i=0; i< MENU_ITEM_NO; i++)
{
    delete spinBox[i];
}
}

void CustomerWidget::deleteTable()
{
delete reserveTable;
delete tableNumber;
for (unsigned char i=0; i< TABLES_BAR ; i++)
{
    delete toolBarTable[i];
}
}

void CustomerWidget::deleteFeedback()
{
delete plainText;
delete submit;

}

void CustomerWidget::setTable()
{
if(tableNumber->isModified())
{
    systemTable[tableNumber->text().toInt()-1].setTableStatus();
}

else
{
    errorMessage->setInformativeText("Please Specify Table No.");
    errorMessage->setIcon(QMessageBox::Warning);
    errorMessage->setTextFormat(Qt::TextFormat::RichText);
    errorMessage->show();
}

}














