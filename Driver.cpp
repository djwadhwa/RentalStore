#include "RentalStore.h"
//#include "Inventory.h"  //or DVDinventory.h?
#include "Customer.h"
//#include "HashTable.h"
//#include "Movie.h"

int main() {

  //Open txt file and Read in Inventory Object
/*
  ifstream infile1("data4movies.txt");
  if (!infile1) {
    return 1;
    //send error message?
  }

//or DVDinventory
  Inventory.fillInventory(infile1);
*/
  //Open txt file and read in Customer object OR do it in Rental store
  ifstream infile2("data4customers.txt");
  if (!infile2) {
    return 1;
    std::cout << "error" << std::endl;
    //error msg?
  }
//  infile2.close();
  //Create RentalStore
  RentalStore store;
  store.readInCustomerList(infile2); //eventually in constructor
  //store.printCustomerList();


  ifstream infile3("data4commands.txt");
  if (!infile3) {
    return 1;
    std::cout << "error3" << std::endl;
    //error msg?
  }

  store.readTransactions(infile3);

  //print inventory to see if all the right movies were rented, print stocks

  return 0;
};
