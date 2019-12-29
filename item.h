#ifndef ITEM_H
#define ITEM_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSpinBox>
#include <bits/stdc++.h>

using namespace std;

class Item {
private:
    /* Each item object has price , tax , total price , type (0 for drink and 1 for food),
    stockState ( 0 for out of stock and 1 for available , itemID & itemname */
    float price, tax = ((price * 14) / 100), totalPrice = price + tax;
    bool type, stockState;
    int itemID;
    QString itemname;
public:

    /* A function to set the attributes of items , it take input itemtype , price , stockstate , itemit, itemname */
    void setItem(bool itemType, float itemPrice, bool itemStockState, int ItemID, QString itemName);
    /* The following are functions to view the item details */
    float get_price();
    bool get_type();
    bool get_stockState();
    float get_totalPrice();
    int get_itemID();
    QString get_itemname();

    /* Operator Overloaded to compare between two item objects */
    bool operator == (Item item1);

};

#endif // ITEM_H
