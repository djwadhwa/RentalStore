#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
using namespace std;

class Customer
{
public:
  Customer();
  Customer(int, string, string);
  ~Customer();
  string getFirstName();
  string getLastName();
  int getID();
  void printHistory();

private:
  int id;
  string firstName, lastName;
  //linked list of the transaction for each customer
};
#endif
