#include "table.h"



Table::Table()
{
    status = 1;
}

bool Table::getTableStatus()
{
    return status;
}

void Table::setTableStatus()
{
    status = 0;
}
