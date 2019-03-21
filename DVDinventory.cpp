#include "DVDInventory.h"
#include "Drama.h"
#include "Comedy.h"
#include "Classic.h"
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;
DVDInventory::DVDInventory()
{

}

DVDInventory::~DVDInventory()
{

}

void DVDInventory::borrowDVD(char DVDType, string firstAttribute, string secondAttribute)
{
  if (DVDType == 'D')
  {

  }
  else if (DVDType = 'F')
  {

  }
  else if (DVDType = 'C')
  {

  }
}

void DVDInventory::returnDVD(char DVDType, string firstAttribute, string secondAttribute)
{
  if (DVDType == 'D')
  {
    
  }
  else if (DVDType = 'F')
  {

  }
  else if (DVDType = 'C')
  {

  }
}

void DVDInventory::printInventory()
{

}

void DVDInventory::readInventory (ifstream infile)
{
  while (!infile.eof())
  {
      string input;
      getline(infile, input);
      vector <string> tokens;
      stringstream s (input);
      string intermediate;

      while(getline(s, intermediate, ','))
          {
              tokens.push_back(intermediate);
          }

        if (tokens.size()!= 0)
        {
          if (tokens[0] == "D")
          {
            Drama dramaMovie;
            dramaMovie.setStock(stoi(tokens[1]));
            dramaMovie.setDirector(tokens[2]);
            dramaMovie.setTitle(tokens[3]);
            dramaMovie.setYear(stoi(tokens[4]));
            std::cout << dramaMovie.getTitle() << '\n';
            dramaDVDList.insert(dramaMovie);
          }
          if (tokens[0] == "F")
          {
            Comedy comedyMovie;
            comedyMovie.setStock(stoi(tokens[1]));
            comedyMovie.setDirector(tokens[2]);
            comedyMovie.setTitle(tokens[3]);
            comedyMovie.setYear(stoi(tokens[4]));
            comedyDVDList.insert(comedyMovie);
          }
          if (tokens[0] == "C")
          {
            Classic classicMovie;
            classicMovie.setStock(stoi(tokens[1]));
            classicMovie.setDirector(tokens[2]);
            classicMovie.setTitle(tokens[3]);
            // get the major actor and released date
            //
          }
        }
}
