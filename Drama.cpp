#ifndef DRAMA_CPP
#define DRAMA_CPP

#include "Drama.h"

bool Drama::operator == (const Drama& dramaObj) const
{
if (getDirector() == dramaObj.getDirector())
{
  if (getTitle() == dramaObj.getTitle())
  {
    return true;
  }
  return false;
}
return false;
}

bool Drama::operator < (const Drama& dramaObj) const
{
  if (getDirector() <= dramaObj.getDirector())
  {
    if (getTitle() < dramaObj.getTitle())
    {
      return true;
    }
    return false;
  }
  return false;
}

bool Drama::operator > (const Drama& dramaObj) const
{

  if (getDirector() >= dramaObj.getDirector())
  {
    if (getTitle() > dramaObj.getTitle())
    {
      return true;
    }
    return false;
  }
  return false;
}

#endif
