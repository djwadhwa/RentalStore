#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include "Movie.h"

class Drama: public Movie
{
public:
  bool operator == (const Drama& dramaObj) const;
  bool operator < (const Drama& dramaObj) const;
  bool operator > (const Drama& dramaObj) const;
};
#endif
