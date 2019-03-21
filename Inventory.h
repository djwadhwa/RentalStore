#ifndef INVENTORY_H
#define INVENTORY_H
#include "Drama.h"
#include "Comedy.h"
#include "Classic.h"
#include <set>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Inventory
{
public:
        void fillInventory(fstream);
        bool borrowItem(char, string, string );
        bool returnItem(char, string , string );
        void printInventory();
};
#endif
