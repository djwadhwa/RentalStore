#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"

class Drama: public Movie
{
  friend std::ostream& operator<<(std::ostream &outStream, const Drama &d); //overload outStream operator

public:
  bool operator == (const Drama& dramaObj) const;
  bool operator < (const Drama& dramaObj) const;
  bool operator > (const Drama& dramaObj) const;
};

#endif
