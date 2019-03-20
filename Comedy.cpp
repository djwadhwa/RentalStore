#ifndef COMEDY_CPP
#define COMEDY_CPP

#include "Comedy.h"

bool operator == (const Comedy& comedyObj) const
{
if (getTitle() == comedyOb.getTitle())
{
  if (getYear() == comedyOb.getYear())
  {
    return true;
  }
  return false;
}
return false;
}

bool operator < (const Comedy& comedyObj) const
{
  if (getTitle() <= comedyOb.getTitle())
  {
    if (getYear() < comedyOb.getYear())
    {
      return true;
    }
    return false;
  }
  return false;
}

bool operator > (const Comedy& comedyObj) const
{
  if (getTitle() >= comedyOb.getTitle())
  {
    if (getYear() > comedyOb.getYear())
    {
      return true;
    }
    return false;
  }
  return false;
}
#endif
