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
  dramaDVDList.clear();
  comedyDVDList.clear();
  classicDVDList.clear();
}

/**
 * Method to borrow a DVD from the DVDInventory
 * @param DVDType the genre of the DVD
 * @param firstAttribute one of the attributes of the borrowed DVD
 * @param secondAttribute one of the attributes of the borrowed DVD
 */
bool DVDInventory::borrowItem(char DVDType, string firstAttribute, string secondAttribute)
{
  // std::cout << firstAttribute<<","<<secondAttribute << '\n';
  if (DVDType == 'D') //go to this if statement if the DVDType is Drama
  {//firstAttribute for drama is director, secondAttribute is title
    std::set<Drama>::iterator it;
    Drama d;
    d.setDirector(firstAttribute);
    d.setTitle(secondAttribute);
    it = dramaDVDList.find(d); //set is a const data structure and therefore cannot be changed
    if (it != dramaDVDList.end()) //therfore need to erase and reinsert
    {
      if((*it).getStock() == 0)
      {
        return false;
      }
    d.setStock((*it).getStock()-1);
    d.setYear((*it).getYear());
    dramaDVDList.erase(it);
    dramaDVDList.insert(d);
    return true;
    }
    return false;
  }

  else if (DVDType == 'F')
  {//firstAttribute for comedy is title and second is year
    std::set<Comedy>::iterator it;
        Comedy f;
        f.setTitle(firstAttribute);
        f.setYear (stoi(secondAttribute));
        it = comedyDVDList.find(f);
        if (it != comedyDVDList.end())
        {
          if((*it).getStock() == 0)
          {
            return false;
          }
          f.setStock((*it).getStock()-1);
          f.setDirector((*it).getDirector());
        comedyDVDList.erase(it);
        comedyDVDList.insert(f);
        return true;
      }
      return false;
  }
  else if (DVDType == 'C')
  {
    //first attribute for classic is month and year, therefore need to tokenize
      //second attribute is majorActor
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
          if((*it).getStock() == 0)
          {
            return false;
          }
          c.setStock((*it).getStock()-1);
          c.setDirector((*it).getDirector());
          c.setTitle((*it).getTitle());
          classicDVDList.erase(it);
          classicDVDList.insert(c);
          return true;
        }
        return false;
  }
  return false;
}

/**
 * Return a borrowed DVD to the DVDInventory
 * @param DVDType the genre of the DVD returned
 * @param firstAttribute one of the attributes of the returned DVD
 * @param secondAttribute one of the attributes of the returned DVD
 */
bool DVDInventory::returnItem(char DVDType, string firstAttribute, string secondAttribute)
{
  if (DVDType == 'D') //go to this if statement if the DVDType is Drama
  {//firstAttribute for drama is
    std::set<Drama>::iterator it;
    Drama d;
    d.setDirector(firstAttribute);
    d.setTitle(secondAttribute);
    it = dramaDVDList.find(d);
    if (it != dramaDVDList.end())
    {
    d.setStock((*it).getStock() +1);
    d.setYear((*it).getYear());
    dramaDVDList.erase(it);
    dramaDVDList.insert(d);
    return true;
    }
    return false;
  }

  else if (DVDType == 'F')
  {
    std::set<Comedy>::iterator it;
        Comedy f;
        f.setTitle(firstAttribute);
        f.setYear (stoi(secondAttribute));
        it = comedyDVDList.find(f);
        if (it != comedyDVDList.end())
        {
          f.setStock((*it).getStock() + 1);
          f.setDirector((*it).getDirector());
        comedyDVDList.erase(it);
        comedyDVDList.insert(f);
        return true;
      }
      return false;
  }
  else if (DVDType == 'C')
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
          c.setStock((*it).getStock() + 1);
          c.setDirector((*it).getDirector());
          c.setTitle((*it).getTitle());
          classicDVDList.erase(it);
          classicDVDList.insert(c);
          return true;
        }
        return false;
      }
      return false;
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
                classicDVDList.insert(classicMovie);
              }
              else
              {
                  std::cout << "Incorrect code: " << tokens[0] << '\n';
              }
            }
      }
  }
}
