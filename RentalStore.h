#ifndef RENTALSTORE_H
#define RENTALSTORE_H
#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"
#include "Customer.h"
#include "DVDinventory.h"

/*    @TinaFedorov
      RentalStore class represents a store that contains
      - a list of customers (customerList hashtable)
      - an inventory of movie objects (only DVD so far)

      In constructor, file is inputted as parameter to then fill inventory.
      customerList is filled with file that is opened within constructor after
      the inventory file closes.

      readTransactions method is the main driver of this class. It reads in
      commands, the options are Borrow movie, Return movie, Print inventory, or
      Print transaction history of a customer.

      Invariants:
        - customerList and DVDinventoryObj have to be filled before accessing
        other methods, especially readTransactions.
*/

class RentalStore {
private:
  DVDInventory DVDinventoryObj;  //should be Inventory or DVD?
  HashTable<Customer> customerList;

public:
  RentalStore();
  RentalStore( ifstream& ); //fills in inventory, and customerList
  void readTransactions( ifstream& );
  void readInCustomerList();
  void printCustomerList();
  bool setItemInfo(ifstream&, char& itemType, char& genre, int& custID, std::string& attr1, std::string& attr2);
  //print inventory should be in inventory class
  void printInventory();

};

#endif
