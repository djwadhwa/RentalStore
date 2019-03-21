#include "DVDinventory.h"
using namespace std;

/**
 * Constructor for DVD inventory
 */
DVDInventory::DVDInventory()
{

}

/**
 * Destructor for DVD inventory
 */
DVDInventory::~DVDInventory()
{

}

/**
 * Method to borrow a DVD from the DVDInventory
 * @param DVDType the genre of the DVD
 * @param firstAttribute one of the attributes of the borrowed DVD
 * @param secondAttribute one of the attributes of the borrowed DVD
 */
void DVDInventory::borrowDVD(char DVDType, string firstAttribute, string secondAttribute)
{
  if (DVDType == 'D') //go to this if statement if the DVDType is Drama
  {
    std::set<Drama>::iterator it;
    Drama d;
    d.setDirector(firstAttribute);
    d.setTitle(secondAttribute);
    it = dramaDVDList.find(d);
    if (it != dramaDVDList.end())
    {
    d.setStock((*it).getStock()-1);
    d.setYear((*it).getYear());
    }
    dramaDVDList.erase(it);
    dramaDVDList.insert(d);
  }

  else if (DVDType == 'F') //go to this if statement if the DVDType is Comedy
  {
    std::set<Comedy>::iterator it;
        Comedy f;
        f.setTitle(secondAttribute);
        f.setYear (stoi(secondAttribute));
        it = comedyDVDList.find(f);
        if (it != comedyDVDList.end())
        {
          f.setStock((*it).getStock()-1);
          f.setDirector((*it).getDirector());
        }
        comedyDVDList.erase(it);
        comedyDVDList.insert(f);
  }
  else if (DVDType == 'C') //go to this if statement if the DVDType is Classic
  {
    std::set<Classic>::iterator it;
        Classic c;
        vector <string> tokens;
        stringstream s (firstAttribute);
        string intermediate;
        while(getline(s, intermediate, ' '))
            {
                tokens.push_back(intermediate);
            }
        c.setReleaseMonth(stoi(tokens[0]));
        c.setYear(stoi(tokens[1]));
        c.setMajorActor (secondAttribute);
        it = classicDVDList.find(c);
        if (it != classicDVDList.end())
        {
          c.setStock((*it).getStock()-1);
          c.setDirector((*it).getDirector());
          c.setTitle((*it).getTitle());
        }
        classicDVDList.erase(it);
        classicDVDList.insert(c);
  }
}

/**
 * Return a borrowed DVD to the DVDInventory
 * @param DVDType the genre of the DVD returned
 * @param firstAttribute one of the attributes of the returned DVD
 * @param secondAttribute one of the attributes of the returned DVD
 */
void DVDInventory::returnDVD(char DVDType, string firstAttribute, string secondAttribute)
{
  if (DVDType == 'D') //go to this if statement if the DVDType is Drama
  {
    std::set<Drama>::iterator it;
    Drama d;
    d.setDirector(firstAttribute);
    d.setTitle(secondAttribute);
    it = dramaDVDList.find(d);
    if (it != dramaDVDList.end())
    {
    d.setStock((*it).getStock()+1);
    d.setYear((*it).getYear());
    }
    dramaDVDList.erase(it);
    dramaDVDList.insert(d);
  }

  else if (DVDType == 'F') //go to this if statement if the DVDType is Comedy
  {
    std::set<Comedy>::iterator it;
        Comedy f;
        f.setTitle(secondAttribute);
        f.setYear (stoi(secondAttribute));
        it = comedyDVDList.find(f);
        if (it != comedyDVDList.end())
        {
          f.setStock((*it).getStock()+1);
          f.setDirector((*it).getDirector());
        }
        comedyDVDList.erase(it);
        comedyDVDList.insert(f);
  }
  else if (DVDType == 'C') //go to this if statement if the DVDType is Classic
  {
    std::set<Classic>::iterator it;
        Classic c;
        vector <string> tokens;
        stringstream s (firstAttribute);
        string intermediate;
        while(getline(s, intermediate, ' '))
            {
                tokens.push_back(intermediate);
            }
        c.setReleaseMonth(stoi(tokens[0]));
        c.setYear(stoi(tokens[1]));
        c.setMajorActor (secondAttribute);
        it = classicDVDList.find(c);
        if (it != classicDVDList.end())
        {
          c.setStock((*it).getStock()+1);
          c.setDirector((*it).getDirector());
          c.setTitle((*it).getTitle());
        }
        classicDVDList.erase(it);
        classicDVDList.insert(c);
  }
}

/**
 * Print the state of the DVDInventory
 */
void DVDInventory::printInventory()
{
  std::cout << "Comedies: " << '\n';
  for (Comedy const& f : comedyDVDList)
    {
        std::cout <<f.getTitle()<<" "<<f.getStock() <<" " << f.getYear()<< '\n';
    }
    std::cout << '\n';
    std::cout << "Dramas: " << '\n';
  for (Drama const& d : dramaDVDList)
    {
        std::cout << d.getTitle()<<" "<<d.getStock() <<" " << d.getYear()<< '\n';
    }
    std::cout << '\n';
    std::cout << "Classics: " << '\n';
  for (Classic const& c : classicDVDList)
    {
        std::cout << c.getTitle()<< " "<< c.getStock()<< " " <<c.getReleaseMonth() << " "<< c.getYear()<< " "<< c.getMajorActor()<< '\n';
    }
}

/**
 * Method to scan a file and get all the DVD for the DVDInventory
 * @param &infile the file that will be scanned
 */
void DVDInventory::fillInventory (ifstream &infile)
{
  while (!infile.eof())
  {
      string input, intermediate;
      getline(infile, input);
      vector <string> tokens;
      stringstream s (input);

      while (!infile.eof())
      {
          string input;
          getline(infile, input);

          std::vector <string> tokens;
          stringstream s (input);
          string intermediate;

          while(getline(s, intermediate, ','))
              {
                  tokens.push_back(intermediate);
              }

            if (tokens.size()!= 0)
            {
              if (tokens[0] == "D") //make a Drama DVD object
              {
                Drama dramaMovie;
                dramaMovie.setStock(stoi(tokens[1]));
                dramaMovie.setDirector(tokens[2].substr(1));
                dramaMovie.setTitle(tokens[3].substr(1));
                dramaMovie.setYear(stoi(tokens[4]));
                dramaDVDList.insert(dramaMovie);
              }
              else if (tokens[0] == "F") //make a Comedy DVD object
              {
                Comedy comedyMovie;
                comedyMovie.setStock(stoi(tokens[1]));
                comedyMovie.setDirector(tokens[2].substr(1));
                comedyMovie.setTitle(tokens[3].substr(1));
                comedyMovie.setYear(stoi(tokens[4]));
                comedyDVDList.insert(comedyMovie);
              }
              else if (tokens[0] == "C") //make a Classic DVD object
              {
                Classic classicMovie;
                classicMovie.setStock(stoi(tokens[1]));
                classicMovie.setDirector(tokens[2].substr(1));
                classicMovie.setTitle(tokens[3].substr(1));

                stringstream s2 (tokens[4]);
                std::vector<string> tokens2;

                while(getline(s2, intermediate, ' '))
                    {
                        tokens2.push_back(intermediate);
                    }
                classicMovie.setMajorActor(tokens2[1]+" "+tokens2[2]);
                classicMovie.setReleaseMonth(stoi(tokens2[3]));
                classicMovie.setYear(stoi(tokens2[4]));
                classicDVDList.insert (classicMovie);
              }
              else
              {
                  std::cout << "Incorrect code: " << tokens[0] << '\n';
              }
            }
      }
  }
}

