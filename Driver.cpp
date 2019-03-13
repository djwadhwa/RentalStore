#include "RentalStore.h"
#include "Inventory.h"  //or DVDinventory.h?
#include "Customer.h"
#include "HashTable.h"
#include "movie.h"

int main() {

  //Open txt file and Read in Inventory Object
  ifstream infile1("data4movies.txt");
  if (!infile1) {
    return 1;
    //send error message?
  }

//or DVDinventory
  Inventory.fillInventory(infile1);

  //Open txt file and read in Customer object OR do it in Rental store
  ifstream infile2("data4customers.txt");
  if (!infile2) {
    return 1;
    //error msg?
  }
  //Create RentalStore

  return 0;
}
