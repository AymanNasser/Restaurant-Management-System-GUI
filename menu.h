#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "item.h"
#include <bits/stdc++.h>

using namespace std;

class Menu {
public:
    /* The Menu class will be a vector of pointers to Item class objects */
    vector<Item> MainMenu;

    /* the addItem method can be used to add an item to the vectors by passing the Item object address */
    void addItem(Item myItem);
    /* Deleting an item will be done by sending the required item ID to the function deleteItem */
    void deleteItem(int itemId);

    /* Returning vector size*/
    int getMenuSize();

};

#endif // MENU_H
