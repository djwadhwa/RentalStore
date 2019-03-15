#include "Customer.h"
#include <string>
#include <iostream>
using namespace std;

Customer()
{
  this->firstName = "";
  this->lastName = "";
  this->id = 0;
}

Customer(int id, string fn, string ln)
{
  this->firstName = fn;
  this->lastName = ln;
  this->id = id;
}

~Customer()
{
}

string Customer::getFirstName()
{
  return firstName;
}

string Customer::getLastName()
{
  return lastName;
}

string Customer::getID()
{
  return id;
}

void Customer::printHistory()
{
  //print the linked list of the transaction
}
