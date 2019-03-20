#ifndef DRAMA_CPP
#define DRAMA_CPP

#include "Drama.h"

bool operator == (const Drama& dramaObj) const
{
if (getDirector() == dramaObj.getDirector())
{
  if (getTitle() == dramaObj.getTitle())
  {
    return true;
  }
}
}

bool operator < (const Drama& dramaObj) const
{
  if (getDirector() <= dramaObj.getDirector())
  {
    if (getTitle() < dramaObj.getTitle())
    {
      return true;
    }
  }
}

bool operator > (const Drama& dramaObj) const
{

  if (getDirector() >= dramaObj.getDirector())
  {
    if (getTitle() > dramaObj.getTitle())
    {
      return true;
    }
  }
}

#endif
