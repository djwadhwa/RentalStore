#ifndef DRAMA_CPP
#define DRAMA_CPP

#include "Drama.h"

bool Drama::operator == (const Drama& dramaObj) const
{
  if (getDirector() == dramaObj.getDirector() && getTitle() == dramaObj.getTitle())
  {
    return true;
  }
    return false;
}

bool Drama::operator < (const Drama& dramaObj) const
{
  if (getDirector() < dramaObj.getDirector())
  {
    return true;
  }
  else if (getDirector() == dramaObj.getDirector() && getTitle() < dramaObj.getTitle())
  {
    return true;
  }
  return false;
}

bool Drama::operator > (const Drama& dramaObj) const
{
  if (getDirector() > dramaObj.getDirector())
  {
    return true;
  }
  else if (getDirector() == dramaObj.getDirector() && getTitle() > dramaObj.getTitle())
  {
    return true;
  }
  return false;
}

#endif
