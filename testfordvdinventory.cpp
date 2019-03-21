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
    ifstream openFile;
    openFile.open("data4movies.txt");
    dvdStorage.readInventory(openFile);
}