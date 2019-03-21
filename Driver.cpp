#include "RentalStore.h"

/*  @TinaFedorov
    Driver
    Opens Inventory txtFile
    Creates RentalStore
      1) Inventory file is read and fills in inventory obj in rental store
      2) customers are read in the constructor of rental store
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

  //Open text file with list of transactions
  ifstream commandsFile("data4commands.txt");
  if (!commandsFile) {
    std::cout << "error: file didnt open" << std::endl;
    return 1;
  }

  //Transactions from file
  store.readTransactions(commandsFile);



  return 0;
};
