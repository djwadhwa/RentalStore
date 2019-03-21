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
int main()
{
  set <Drama> D;
  set <Comedy> F;
  set <Classic> C;
ifstream infile("data4movies.txt");

Drama dr;
dr.setDirector("Steven Spielberg");
dr.setTitle("Schindler's List");

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
        if (tokens[0] == "D")
        {
          Drama dramaMovie;
          dramaMovie.setStock(stoi(tokens[1]));
          dramaMovie.setDirector(tokens[2]);
          dramaMovie.setTitle(tokens[3]);
          dramaMovie.setYear(stoi(tokens[4]));
          std::cout << dramaMovie == dr << '\n';
          D.insert(dramaMovie);
        }
        else if (tokens[0] == "F")
        {
          Comedy comedyMovie;
          comedyMovie.setStock(stoi(tokens[1]));
          comedyMovie.setDirector(tokens[2]);
          comedyMovie.setTitle(tokens[3]);
          comedyMovie.setYear(stoi(tokens[4]));
          F.insert(comedyMovie);
        }
        else if (tokens[0] == "C")
        {
          Classic classicMovie;
          classicMovie.setStock(stoi(tokens[1]));
          classicMovie.setDirector(tokens[2]);
          classicMovie.setTitle(tokens[3]);

          stringstream s2 (tokens[4]);
          std::vector<string> tokens2;

          while(getline(s2, intermediate, ' '))
              {
                  tokens2.push_back(intermediate);
              }

          classicMovie.setMajorActor(tokens2[1]+" "+tokens2[2]);
          classicMovie.setReleaseMonth(stoi(tokens2[3]));
          classicMovie.setYear(stoi(tokens2[4]));
          C.insert (classicMovie);
        }
        else
        {
            //std::cout << "Incorrect code: " << tokens[0] << '\n';
        }
      }
  }
  // std::cout << "Comedies: " << '\n';
  // for (Comedy const& f : F)
  //   {
  //       std::cout <<f.getTitle()<<" "<<f.getStock() <<" " << f.getYear()<< '\n';
  //   }
  //   std::cout << "Dramas: " << '\n';
  // for (Drama const& d : D)
  //   {
  //       std::cout << d.getTitle()<<" "<<d.getStock() <<" " << d.getYear()<< '\n';
  //   }
  //   std::cout << "Classics: " << '\n';
  // for (Classic const& c : C)
  //   {
  //       std::cout << c.getTitle()<< " "<< c.getStock()<< " " << c.getYear()<< " "<< c.getMajorActor()<< '\n';
  //   }
std::set<Drama>::iterator it;

if (D.find(dr) != D.end())
{
  std::cout << *D.find(dr)<< '\n';;
}

return 0;
}
