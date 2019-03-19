#include "Customer.h"
//#include <string>
//#include <iostream>
//using namespace std;

Customer::Customer()
{
  this->firstName = "";
  this->lastName = "";
  this->id = 0;
}

Customer::Customer(int id, string fn, string ln)
{
  this->firstName = fn;
  this->lastName = ln;
  this->id = id;
}

Customer::~Customer()
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

int Customer::getID()
{
  return id;
}

void Customer::printHistory()
{
  //print the linked list of the transaction
}
