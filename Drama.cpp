#ifndef DRAMA_CPP
#define DRAMA_CPP

#include "Drama.h"

/**
 * "==" operator overload for drama
 * @param &dramaObj the drama object that will be compared with the assigned drama movie
 * @return false if they are not the same
 * @return true if they are the same
 */
bool Drama::operator == (const Drama& dramaObj) const
{
  if (getDirector() == dramaObj.getDirector() && getTitle() == dramaObj.getTitle())
  {
    return true;
  }
    return false;
}

/**
 * "<" operator overload for drama
 * @param &dramaObj the Comedy object that will be compared with the assigned drama movie
 * @return false if the assigned drama movie is bigger in comparison than &dramaObj
 * @return true if the assigned drama movie is smaller in comparison than &dramaObj
 */
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

/**
 * ">" operator overload for drama
 * @param &dramaObj the Drama object that will be compared with the assigned drama movie
 * @return true if the assigned drama movie is bigger in comparison than &dramaObj
 * @return false if the assigned drama movie is smaller in comparison than &dramaObj
 */
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

/**
 * "<<" operator overload
 * @param &d the Drama object that will be printed
 * @param &outStream the statement that will be printed
 * @return outStream the statement that will be printed
 */
std::ostream& operator<<(std::ostream &outStream, const Drama &d)
{
  outStream<< d.getDirector() << " "<< d.getTitle();
	return outStream;
}

#endif
