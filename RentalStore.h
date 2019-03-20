#ifndef RENTALSTORE_H
#define RENTALSTORE_H
#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"
#include "Customer.h"
//#include "Inventory.h"
//using namespace std;

class RentalStore {
private:
  //DVD DVDinventory;  //should be Inventory or DVD?
  HashTable<Customer> customerList;

public:
  RentalStore();
//  RentalStore( Inventory, ifstream& ); //or just create customer object beforehand,and make copy constr in customer
  void readTransactions( ifstream& );
  void readInCustomerList( ifstream& );
  void printCustomerList();
  bool setItemInfo(ifstream&, char& itemType, char& genre, int& custID, std::string& attr1, std::string& attr2);
  //print inventory should be in inventory class

};

#endif
