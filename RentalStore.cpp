#include "RentalStore.h"

RentalStore::RentalStore() {

}

RentalStore::RentalStore( Inventory inventoryObj, fstream infile ) {
  //copy inventoryObj to the inventory in RentalStore

  //read in customers from file, or option 2: copy obj
}

void RentalStore::readTransactions( fstream infile ) {
  //declare variables:
  char action, itemType, genre; int custID; string attr1, attr2;
  //read in the action
  infile >> action;
  switch (action) {
    case 'B':   //borrow item
        infile >> custID >> itemType >> genre >> custID >> attr1 >> attr2;
        bool valid = DVDinventory.borrowItem( genre, attr1, attr2 ); //change stock #
        //get Movie object using ID
        //add borrow transaction to movie object
        moviePointer->addTransaction('B', itemType, genre, attr1, attr2);
        // or have addBorrowTransaction method to Customer class
        break;
    case 'R':   //return item
        infile >> custID >> itemType >> genre >> custID >> attr1 >> attr2;
        bool valid = DVDinventory.returnItem( genre, attr1, attr2 ); //change stock #
        //get Customer pointer using ID
        //add borrow transaction to movie object
        moviePointer->addTransaction('R', itemType, genre, attr1, attr2);
        // or have addReturnTransaction method to Customer class
        break;
    case 'H':   //print transaction history of customer
        infile >> custID;
        //get Customer obj pointer
        Customer* ptr = get( custID );
        if (ptr != NULL)    //check if cust exists
          ptr->printHistory();
        break;
    case 'I':   //print store inventory
        DVDinventory.printInventory();
        break;
    default:
      //if invalid action, error message?
  }
}
