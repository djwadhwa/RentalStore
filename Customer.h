#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
using namespace std
class Customer
{
public:
  string getFirstName();
  string getLastName();
  string getID();
  void printHistory();

private:
  int ID;
  string firstName, lastName;
  //linked list of the transaction for each customer
};
#endif
