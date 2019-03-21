#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "Classic.h"

int Classic::getReleaseMonth() const
{
  return this->releaseMonth;
}
std::string Classic::getMajorActor() const
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

bool Classic::operator == (const Classic& classicObj) const
{
if (getYear() == classicObj.getYear() && getReleaseMonth() == classicObj.getReleaseMonth() && getMajorActor() == classicObj.getMajorActor())
    {
      return true;
    }
  return false;
}

bool Classic::operator < (const Classic& classicObj) const
{
  if (getYear() < classicObj.getYear())
  {
    return true;
  }
    else if (getYear() == classicObj.getYear() && getReleaseMonth() < classicObj.getReleaseMonth())
    {
      return true;
    }
  else if (getYear() == classicObj.getYear() && getReleaseMonth() == classicObj.getReleaseMonth() && getMajorActor() < classicObj.getMajorActor())
      {
        return true;
      }
  return false;
}

bool Classic::operator > (const Classic& classicObj) const
{
  if (getYear() > classicObj.getYear())
  {
    return true;
  }
    else if (getYear() == classicObj.getYear() && getReleaseMonth() > classicObj.getReleaseMonth())
    {
      return true;
    }
  else if (getYear() == classicObj.getYear() && getReleaseMonth() == classicObj.getReleaseMonth() && getMajorActor() > classicObj.getMajorActor())
      {
        return true;
      }
  return false;
}

#endif
