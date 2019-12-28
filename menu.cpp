#include "menu.h"

void Menu::addItem(Item myItem)
{
    MainMenu.push_back(myItem);
}

void Menu::deleteItem(int itemId)
{
    /* A loop iterating over the vector elements */
    for (unsigned int i = 0; i < MainMenu.size(); i++)
    {
        /* the item will be deleted if its ID is the same as the (required item to be deleted) ID,
                , the arrow operator is used to access the attribute(ID) of the current iterated object */
        if ((MainMenu[i].get_itemID()) == itemId)
        {
            MainMenu.erase(MainMenu.begin() + i);
        }
    }
}

int Menu::getMenuSize()
{
    return MainMenu.size();
}
