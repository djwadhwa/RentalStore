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
    dvdStorage.borrowDVD('D', "Steven Spielberg", "Schindler's List");
    dvdStorage.printInventory();

    dvdStorage.borrowDVD('C', "9 1938", "Cary Grant");
    dvdStorage.printInventory();
}
