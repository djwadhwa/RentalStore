#include "DVDInventory.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;
DVDInventory::DVDInventory()
{

}

DVDInventory::~DVDInventory()
{

}

void DVDInventory::borrowItem(char ,string ,string )
{

}

void returnItem(char ,string ,string )
{

}

void printInventory()
{

}

void DVDInventory::readInventory (ifstream file)
{
    if (file.is_open())
    {
        string s, director, title, year;
        int stock;
        char genre;
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string value;
            while (getline(ss, value, ','))
            {
                file >> genre;
                file >> stock;
                file >> director >> title;
                if (genre == 'F' || genre == 'D')
                {
                    file >> year;
                }
                else if (genre = 'C')
                {
                    string actorAndDate;
                    file >> actorAndDate;
                }
            }
        }
           
    }
}
