#ifndef CLASSIC_H
#define CLASSIC_H
#include <iostream>
#include <string>
#include "Movie.h"
class Classic: public Movie
{

public:
  int getReleaseMonth();
  std::string getMajorActor();
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
