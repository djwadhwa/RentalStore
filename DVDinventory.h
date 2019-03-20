#ifndef DVDINVENTORY_H
#define DVDINVENTORY_H
#include <iostream>
#include <string>
#include "Inventory.h"
#include "BinTree.h"
using namespace std;

class DVDInventory : public Inventory
{
    public:
        DVDInventory();
        ~DVDInventory();
        void borrowItem(char ,string ,string );
        void returnItem(char ,string ,string );
        void printInventory();
        void readInventory(ifstream);

    private:
        //BinTree<Comedy> comedyDVDList;
        //BinTree<Classic> classicDVDList;
        //BinTree<Drama> dramaDVDList;
};
#endif
