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
private:
  int releaseMonth;
  std::string majorActor;
};
#endif
