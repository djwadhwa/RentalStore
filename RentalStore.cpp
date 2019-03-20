#include "RentalStore.h"

RentalStore::RentalStore() {
  std::cout << "constructed" << std::endl;

}
/*
RentalStore::RentalStore( Inventory inventoryObj, fstream infile ) {
  //copy inventoryObj to the inventory in RentalStore
  DVDinventory = inventoryObj;
  //read in customers from file, or option 2: copy obj
  readInCustomerList(infile);
}
*/

void RentalStore::readTransactions( ifstream& infile ) {
  //declare variables:
  char action, itemType, genre; int custID; std::string attr1, attr2;
  Customer* cust = NULL; //one customer per action
  //read in the action
  while ( infile >> action ) {
    switch (action) {
      case 'B':   //borrow item
          std::cout << "borrow item" << std::endl;
          infile >> custID >> itemType >> genre >> custID >> attr1 >> attr2;
          //bool valid = DVDinventory.borrowItem( genre, attr1, attr2 ); //change stock #
          //get Movie object using ID
          //add borrow transaction to movie object
          //moviePointer->addTransaction('B', itemType, genre, attr1, attr2);
          // or have addBorrowTransaction method to Customer class
          cust = customerList.get(custID);
          std::cout << "customer: " << cust->getID() << std::endl;
          break;
      case 'R':   //return item
          std::cout << "return item" << std::endl;
          infile >> custID >> itemType >> genre >> custID >> attr1 >> attr2;
          //bool valid = DVDinventory.returnItem( genre, attr1, attr2 ); //change stock #
          //get Customer pointer using ID
          //add borrow transaction to movie object
          //moviePointer->addTransaction('R', itemType, genre, attr1, attr2);
          // or have addReturnTransaction method to Customer class
          cust = customerList.get(custID);
          std::cout << "customer: " << cust->getID() << std::endl;
          break;
      case 'H':   //print transaction history of customer
          std::cout << "print History" << std::endl;
          infile >> custID;
          //get Customer obj pointer
          cust = get( custID );
          if (cust != NULL)    //check if cust exists
            std::cout << "customer: " << cust->getID() << std::endl;
            //cust->printHistory();
          break;
      case 'I':   //print store inventory
          std::cout << "print Inventory" << std::endl;
          //DVDinventory.printInventory();
          break;
      default:
        //if invalid action, error message?
        std::cout << "invalid action" << std::endl;
    }
  }
}


//completed
void RentalStore::readInCustomerList(ifstream& infile) {

  int id; std::string firstName, lastName;
  while ( infile >> id >> firstName >> lastName ) {
    std::cout << id << firstName << lastName;
    Customer newCustomer(id, firstName, lastName);
    customerList.insert(id, newCustomer);
  }

}

//temporary, replace with method from customer class? or make my own?
void RentalStore::printCustomerList() {
  customerList.printTable();
}
