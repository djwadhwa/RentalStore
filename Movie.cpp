#ifndef MOVIE_CPP
#define MOVIE_CPP
#include "Movie.h"

/**
 * Return the stock of a DVD type
 * @return stock
 */
int Movie::getStock() const
{
  return this->stock;
}

/**
 * Set the stock of a DVD 
 * @param stock the updated amount of stock
 */
void Movie::setStock(int stock)
{
  this-> stock = stock;
}

/**
 * Return the release year of a DVD
 * @return releaseYear
 */
int Movie::getYear() const
{
  return this->releaseYear;
}

/**
 * Set the release year of a DVD
 * @param year the updated release year
 */
void Movie::setYear(int year)
{
  this-> releaseYear = year;
}

/**
 * Return the title of a DVD 
 * @return title
 */
std::string Movie::getTitle() const
{
  return this->title;
}

/**
 * Set the title of a DVD
 * @param the title of a DVD type
 */
void Movie::setTitle(std::string title)
{
  this->title = title;
}

/**
 * Return the director of a DVD
 * @return stock
 */
std::string Movie::getDirector() const
{
  return this->director;
}

/**
 * Set the director of a DVD
 * @param director the updated director
 */
void Movie::setDirector(std::string director)
{
  this->director = director;
}
#endif
