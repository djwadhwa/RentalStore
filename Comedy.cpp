#ifndef COMEDY_CPP
#define COMEDY_CPP

#include "Comedy.h"

bool Comedy::operator == (const Comedy& comedyObj) const
{
if (getTitle() == comedyObj.getTitle())
{
  if (getYear() == comedyObj.getYear())
  {
    return true;
  }
  return false;
}
return false;
}

bool Comedy::operator < (const Comedy& comedyObj) const
{
  if (getTitle() <= comedyObj.getTitle())
  {
    if (getYear() < comedyObj.getYear())
    {
      return true;
    }
    return false;
  }
  return false;
}

bool Comedy::operator > (const Comedy& comedyObj) const
{
  if (getTitle() >= comedyObj.getTitle())
  {
    if (getYear() > comedyObj.getYear())
    {
      return true;
    }
    return false;
  }
  return false;
}
#endif
