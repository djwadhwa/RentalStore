#ifndef CLASSIC_H
#define CLASSIC_H

#include "Movie.h"
//tested
class Classic: public Movie
{

public:
  int getReleaseMonth() const;
  std::string getMajorActor() const;
  void setReleaseMonth(int);
  void setMajorActor(std::string);

  bool operator == (const Classic& classicObj) const;
  bool operator < (const Classic& classicObj) const;
  bool operator > (const Classic& classicObj) const;

private:
  int releaseMonth;
  std::string majorActor;
};

#endif
