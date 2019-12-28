#include "table.h"



Table::Table()
{
    status = 1;
}

QString Table::getTableStatus()
{
    if(status == 0)
    {
        return "Reserved";
    }
    return "Not Reserved";
}

void Table::setTableStatus()
{
    status = 0;
}
