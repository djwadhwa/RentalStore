#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "DVDinventory.h"

int main()
{
    DVDInventory dvdStorage;
    ifstream openFile("data4movies.txt");
    dvdStorage.fillInventory(openFile);
    dvdStorage.printInventory();
    dvdStorage.borrowItem('D', "Steven Spielberg", "Schindler's List");
    dvdStorage.printInventory();

    dvdStorage.borrowItem('C', "9 1938", "Cary Grant");
    dvdStorage.printInventory();
}
