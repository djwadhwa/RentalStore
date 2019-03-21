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
        // Inventory();
        // Inventory(const Inventory&);
        // ~Inventory();
        void fillInventory(fstream);
        void borrowItem(char ,char ,string ,string );
        void returnItem(char ,char ,string ,string );
        void printInventory();
};
#endif
