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

  //Open inventory object txt file
  ifstream infile1("data4movies.txt");
  if (!infile1) {
    std::cout << "file didnt open" << std::endl;
    return 1;
  }

  //Create RentalStore
  RentalStore store(infile1);
  //store.printCustomerList();
  std::cout << "INVENTORY BEFORE:" << std::endl;
  store.printInventory();

  //Open text file with list of transactions
  ifstream commandsFile("data4commands.txt");
  if (!commandsFile) {
    std::cout << "error: file didnt open" << std::endl;
    return 1;
  }

  store.readTransactions(commandsFile);

  std::cout << "INVENTORY AFTER:" << std::endl;
  store.printInventory();

  //print inventory to see if all the right movies were rented, print stocks

  return 0;
};
