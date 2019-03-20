#ifndef MOVIE_CPP
#define MOVIE_CPP
#include "Movie.h"
int Movie::getStock() const
{
  return this->stock;
}
void Movie::setStock(int stock)
{
  this-> stock = stock;
}
int Movie::getYear() const
{
  return this->releaseYear;
}
void Movie::setYear(int year)
{
  this-> releaseYear = year;
}
std::string Movie::getTitle() const
{
  return this->title;
}
void Movie::setTitle(std::string title)
{
  this->title = title;
}
std::string Movie::getDirector() const
{
  return this->director;
}
void Movie::setDirector(std::string director)
{
  this->director = director;
}
#endif
