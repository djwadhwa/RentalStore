#ifndef DVDINVENTORY_H
#define DVDINVENTORY_H

#include "Inventory.h"

using namespace std;

class DVDInventory : public Inventory
{
    public:
        DVDInventory();
        ~DVDInventory();
        bool borrowItem(char, string, string );
        bool returnItem(char, string, string );
        void printInventory();
        void fillInventory(ifstream &);

    private:
        set<Comedy> comedyDVDList;
        set<Classic> classicDVDList;
        set<Drama> dramaDVDList;
};
#endif
