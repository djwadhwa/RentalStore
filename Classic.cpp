#ifndef CLASSIC_CPP
#define CLASSIC_CPP
#include "Classic.h"

int Classic::getReleaseMonth()
{
  return this->releaseMonth;
}
std::string Classic::getMajorActor()
{
  return this -> majorActor;
}
void Classic::setReleaseMonth(int month)
{
  this->releaseMonth = month;
}

void Classic::setMajorActor(std::string actorName)
{
  this->majorActor = actorName;
}

#endif
