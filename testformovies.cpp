#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
//#include "DVDInventory.h"
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
using namespace std;

int main()
{
    // DVDInventory dvdStorage;
    // ifstream openFile;
    // openFile.open("data4movies.txt");
    // dvdStorage.readInventory(openFile);
    Classic classic1, classic2;
    Comedy comedy1, comedy2;
    Drama drama1, drama2;
    classic1.setReleaseMonth(5);
    classic1.setMajorActor("DJ Wadhwa");
    classic2.setReleaseMonth(4);
    classic2.setMajorActor("Tarcisius Daniel");
    if (classic1 == classic2)
    {
        cout << "true";
    }

    return 0;
}