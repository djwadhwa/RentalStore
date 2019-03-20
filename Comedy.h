#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"

class Comedy : public Movie
{
public:

  bool operator == (const Comedy& comedyObj) const;
  bool operator < (const Comedy& comedyObj) const;
  bool operator > (const Comedy& comedyObj) const;
};
#endif
