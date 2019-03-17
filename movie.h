#ifndef MOVIE_H
#define MOVIE_H
#include <string>
class Movie{
public:
  int getStock();
  void setStock(int);
  std::string getTitle();
  void setTitle(std::string);
  std::string getDirector();
  void setDirector(std::string );
  int getYear();
  void setYear(int);
protected:
  int stock, releaseYear;
  std::string title, director;
};
#endif
