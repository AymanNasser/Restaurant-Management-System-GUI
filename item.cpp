#include "item.h"



void Item::setItem(bool itemType, float itemPrice, bool itemStockState, int ItemID, QString itemName)
{
    type = itemType;
    price = itemPrice;
    stockState = itemStockState;
    itemID = ItemID;
    itemname = itemName;

}

float Item::get_price()
{
    return price;
}

bool Item::get_type()
{
    return type;
}

bool Item::get_stockState()
{
    return stockState;
}

float Item::get_totalPrice()
{
    return totalPrice;
}

int Item::get_itemID()
{
    return itemID;
}

QString Item::get_itemname()
{
    return itemname;
}

bool Item::operator ==(Item item1)
{
    if ( (item1.get_itemID() == itemID) && ((item1.get_itemname()) == itemname) \
         && (item1.get_price() == price) && (item1.get_stockState() == stockState)\
         && (item1.get_type() == type) )
    {

        return 1;
    }
    else
    {
        return 0;
    }
}
