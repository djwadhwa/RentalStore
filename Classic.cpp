#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "Classic.h"

/**
 * Return the release month of the movie
 * @return releaseMonth
 */
int Classic::getReleaseMonth() const
{
  return this->releaseMonth;
}

/**
 * Return the major actor of the movie
 * @return majorActor
 */
std::string Classic::getMajorActor() const
{
  return this -> majorActor;
}

/**
 * Set the release month of the movie
 * @param month the updated month
 */
void Classic::setReleaseMonth(int month)
{
  this->releaseMonth = month;
}

/**
 * Set the major actor of the movie
 * @return actorName the updated major actor
 */
void Classic::setMajorActor(std::string actorName)
{
  this->majorActor = actorName;
}

/**
 * "==" operator overload for classic
 * @param &classicObj the classic object that will be compared with the assigned classic movie
 * @return false if they are not the same
 * @return true if they are the same
 */
bool Classic::operator == (const Classic& classicObj) const
{
if (getYear() == classicObj.getYear() && getReleaseMonth() == classicObj.getReleaseMonth() && getMajorActor() == classicObj.getMajorActor())
    {
      return true;
    }
  return false;
}

/**
 * "<" operator overload for classic
 * @param &classicObj the classic object that will be compared with the assigned classic movie
 * @return false if the assigned classic movie is bigger in comparison than &classicObj
 * @return true if the assigned classic movie is smaller in comparison than &classicObj
 */
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

/**
 * ">" operator overload for classic
 * @param &classicObj the classic object that will be compared with the assigned classic movie
 * @return true if the assigned classic movie is bigger in comparison than &classicObj
 * @return false if the assigned classic movie is smaller in comparison than &classicObj
 */
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

