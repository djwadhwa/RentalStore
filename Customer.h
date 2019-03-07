#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>

class Customer
{
public:
  std::string getFirstName();
  std::string getLastName();
  std::string getID();
  void printHistory();

private:
  int ID;
  std::string firstName, lastName;
};
#endif
