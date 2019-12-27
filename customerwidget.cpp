#include "customerwidget.h"

CustomerWidget::CustomerWidget(QWidget *parent) : QWidget(parent)
{
        toolBar = new QToolBar();
        custGrid = new QGridLayout();
        errorMessage = new QMessageBox();
        submit = new QPushButton("Submit FeedBack");

        adjustToolBar();
        connectSigSlot();

        this->setLayout(this->custGrid);


}

void CustomerWidget::adjustToolBar()
{

    QIcon I_Order("F:/Restaurant-Management-System-GUI/Icons/meal.png"); QString S_Order("Order");
    QIcon I_Menu("F:/Restaurant-Management-System-GUI/Icons/menu.png"); QString S_Menu("Menu");
    QIcon I_FeedBack("F:/Restaurant-Management-System-GUI/Icons/questionnaire.png"); QString S_FeedBack("FeedBack");
    QIcon I_Table("F:/Restaurant-Management-System-GUI/Icons/table.png"); QString S_Table("Table");
    QIcon I_Status("F:/Restaurant-Management-System-GUI/Icons/loading.png"); QString S_Status("Status");

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

void CustomerWidget::connectSigSlot()
{
    // Toolbar Connect
    connect(toolBar,SIGNAL(actionTriggered(QAction *)),this,SLOT(handleToolBar(QAction*)));


    // Submit QPushButton connect
    connect(submit,SIGNAL(clicked()),this,SLOT(feedbackSubmitted()));

}

void CustomerWidget::handleToolBar(QAction *trigAction)
{
    if(trigAction->text() == "Order")
    {

    }
    else if (trigAction->text() == "Menu")
    {

    }
    else if (trigAction->text() == "Status")
    {

    }

    else if (trigAction->text() == "FeedBack")
    {

        plainText = new QPlainTextEdit();

        custGrid->addWidget(plainText,1,0,-1,4);
        custGrid->addWidget(submit,5,4,1,1);

    }
    else if (trigAction->text() == "Table")
    {

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

    QFile feedbackFile("F:/Restaurant-Management-System-GUI/feedback.txt");

    if(feedbackFile.open(QIODevice::NewOnly))
    {
        feedbackFile.reset();
        QTextStream stream(&feedbackFile);
        char i =0;
        while(i < list->size())
        {

            stream << list->at(i) +"\n";
            i++;
        }

        feedbackFile.close();
    }
    else
    {
      errorMessage->setInformativeText("hd");
      errorMessage->show();
    }


}














