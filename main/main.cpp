#include "City.h"
#include "Table.h"
#include <iostream>
#include <vector>


int main()
{
    auto name = choseCity();
    City city(name);
    city.getName();
    city.getFootballclub(true);
    city.printTable();
}
