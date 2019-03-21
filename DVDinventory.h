#ifndef DVDINVENTORY_H
#define DVDINVENTORY_H

#include "Inventory.h"

using namespace std;

class DVDInventory : public Inventory
{
    public:
        DVDInventory();
        ~DVDInventory();
        void borrowDVD(char ,string ,string );
        void returnDVD(char ,string ,string );
        void printInventory();
        void readInventory(ifstream);

    private:
        set<Comedy> comedyDVDList;
        set<Classic> classicDVDList;
        set<Drama> dramaDVDList;
};
#endif
