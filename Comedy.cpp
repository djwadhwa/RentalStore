#ifndef COMEDY_CPP
#define COMEDY_CPP

#include "Comedy.h"

bool Comedy::operator == (const Comedy& comedyObj) const
{
  if (getTitle() == comedyObj.getTitle() && getYear() == comedyObj.getYear())
  {
    return true;
  }
  return false;
}

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
