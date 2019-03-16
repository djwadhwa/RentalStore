#ifndef RENTALSTORE_H

#include <fstream>

class RentalStore {
private:
  DVD DVDinventory;  //should be Inventory or DVD?
  Hashtable<Customer> customerList;

public:
  RentalStore();
  RentalStore( Inventory, fstream ); //or just create customer object beforehand,and make copy constr in customer
  void readTransactions( fstream );

  //print inventory should be in inventory class

}
