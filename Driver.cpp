#include "RentalStore.h"

/*  @TinaFedorov
    Driver
    Creates inventory by reading in from text file
    Creates RentalStore with two Parameters
      1) Inventory object, copied to DVDinventory object in store
      2) file with customer to read in and fill customerList in store
    Reads in transaction commands
*/

int main() {

  //Open txt file and Read in Inventory Object

  ifstream infile1("data4movies.txt");
  if (!infile1) {
    return 1;
    //send error message?
  }

  //DVDinventory inventory;
  //inventory.fillInventory(infile1);

  //Open txt file and read in Customer object OR do it in Rental store
  /*ifstream infile2("data4customers.txt");
  if (!infile2) {
    return 1;
    std::cout << "error" << std::endl;
    //error msg?
  }
//  infile2.close();
*/
  //Create RentalStore
  RentalStore store(infile1);
  //store.readInCustomerList(infile1); //eventually in constructor
  //store.printCustomerList();

/*
  //Open text file with list of transactions
  ifstream infile3("data4commands.txt");
  if (!infile3) {
    return 1;
    std::cout << "error3" << std::endl;
    //error msg?
  }*/

  //store.readTransactions(infile3);

  //print inventory to see if all the right movies were rented, print stocks

  return 0;
};
