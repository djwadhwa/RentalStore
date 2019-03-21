#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Inventory
{
    public:
        Inventory();
        Inventory(const Inventory&);
        ~Inventory();
        void readInventory(fstream);
        void borrowItem(char ,char ,string ,string );
        void returnItem(char ,char ,string ,string );
        void printInventory();
};
#endif
