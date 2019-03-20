#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

class Movie{

public:
  int getStock() const;
  void setStock(int);
  std::string getTitle() const;
  void setTitle(std::string);
  std::string getDirector() const;
  void setDirector(std::string );
  int getYear() const;
  void setYear(int);

protected:
  int stock, releaseYear;
  std::string title, director;
};

#endif
