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

std::ostream& operator<<(std::ostream &outStream, const Drama &d)
{
  outStream<< d.getDirector() << " "<< d.getTitle();
	return outStream;
}

#endif
