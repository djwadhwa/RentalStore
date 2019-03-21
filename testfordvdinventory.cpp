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
}
