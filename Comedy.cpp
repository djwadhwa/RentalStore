#ifndef COMEDY_CPP
#define COMEDY_CPP

#include "Comedy.h"

/**
 * "==" operator overload for comedy
 * @param &comedyObj the Comedy object that will be compared with the assigned comedy movie
 * @return false if they are not the same
 * @return true if they are the same
 */
bool Comedy::operator ==(const Comedy& comedyObj) const
{
  if (getTitle() == comedyObj.getTitle() && getYear() == comedyObj.getYear())
  {
    return true;
  }
  return false;
}

/**
 * "<" operator overload for comedy
 * @param &comedyObj the Comedy object that will be compared with the assigned comedy movie
 * @return false if the assigned comedy movie is bigger in comparison than &comedyObj
 * @return true if the assigned comedy movie is smaller in comparison than &comedyObj
 */
bool Comedy::operator < (const Comedy& comedyObj) const
{
  if (getTitle() < comedyObj.getTitle())
  {
    return true;
  }
  else if (getTitle() == comedyObj.getTitle() && getYear() < comedyObj.getYear())
  {
    return true;
  }
  return false;
}

/**
 * ">" operator overload for comedy
 * @param &comedyObj the Comedy object that will be compared with the assigned comedy movie
 * @return true if the assigned comedy movie is bigger in comparison than &comedyObj
 * @return false if the assigned comedy movie is smaller in comparison than &comedyObj
 */
bool Comedy::operator > (const Comedy& comedyObj) const
{
  if (getTitle() > comedyObj.getTitle())
  {
    return true;
  }
  else if (getTitle() == comedyObj.getTitle() && getYear() > comedyObj.getYear())
  {
    return true;
  }
  return false;
}
#endif
