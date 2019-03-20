#include "RentalStore.h"

RentalStore::RentalStore() {
  std::cout << "constructed" << std::endl;
}
/*
RentalStore::RentalStore( Inventory inventoryObj, ifstream& infile ) {
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
          bool setInfo = setItemInfo(infile, itemType, genre, custID, attr1, attr2);
          if (!setInfo) //if itemtype or genre was not valid, cant borrow
            break;
          //borrow()
          //bool valid = DVDinventory.borrowItem( genre, attr1, attr2 ); //change stock #
          if (valid) {
            cust = customerList.get(custID);
            if (cust != NULL) {
              std::cout << "customer: " << cust->getID() << std::endl;
              //add transaction missing title from classics
              //cust.addHistory('B', mediaType, title ) media, and genre?
            }else {
              std::cout << "error: customer not found" << std::endl;
            }
          } else {
            std::cout << "error: movie not found" << std::endl;
          }
          //get Movie object using ID
          //add borrow transaction to movie object
          //moviePointer->addTransaction('B', itemType, genre, attr1, attr2);
          // or have addBorrowTransaction method to Customer class


          break;
      case 'R':   //return item
          std::cout << "return item" << std::endl;
          bool setInfo = setItemInfo(infile, itemType, genre, custID, attr1, attr2);
          if (!setInfo) //if itemtype or genre was not valid, cant borrow
            break;

          //bool valid = DVDinventory.returnItem( genre, attr1, attr2 ); //change stock #
          //get Customer pointer using ID
          //add borrow transaction to movie object
          //moviePointer->addTransaction('R', itemType, genre, attr1, attr2);
          // or have addReturnTransaction method to Customer class
          if (valid) {
            cust = customerList.get(custID);
            if (cust != NULL) {
              std::cout << "customer: " << cust->getID() << std::endl;
              //add transaction missing title from classics
              //cust.addHistory('R', itemType, genre, ___)
            } else {
              std::cout << "error: customer not found" << std::endl;
            }
          } else {
              std::cout << "error: movie not found" << std::endl;
          }
          break;
      case 'H':   //print transaction history of customer
          std::cout << "print History" << std::endl;
          infile >> custID;
          //get Customer obj pointer
          cust = customerList.get( custID );
          if (cust != NULL) {    //check if cust exists
            std::cout << "customer: " << cust->getID() << std::endl;
          } else {
            std::cout << "error: customer doesn't exist" << std::endl;
          }
            //cust->printHistory();
          break;
      case 'I':   //print store inventory
          std::cout << "print Inventory" << std::endl;
          //DVDinventory.printInventory();
          break;
      default:
        //if invalid action, error message?
        std::cout << "invalid action" << std::endl;
        std::string junk;
        getline(infile, junk, '\n');
    }
  }
}


//completed
void RentalStore::readInCustomerList(ifstream& infile) {

  int id; std::string firstName, lastName;
  while ( infile >> id >> firstName >> lastName ) {
    //std::cout << id << firstName << lastName;
    Customer newCustomer(id, firstName, lastName);
    customerList.insert(id, newCustomer);
  }

}

//temporary, replace with method from customer class? or make my own?
void RentalStore::printCustomerList() {
  customerList.printTable();
}

bool RentalStore::setItemInfo( ifstream& infile, char& itemType, char& genre, int& custID, std::string& attr1, std::string& attr2 ) {
  //char itemType, genre; int custID; std::string attr1, attr2;
  infile >> custID >> itemType >> genre;
  if (itemType == 'D') {
    if ( genre == 'F') {
      getline(infile, attr1, ',');
      getline(infile, attr2, '\n');
    } else if ( genre == 'D') {
      getline(infile, attr1, ',');
      getline(infile, attr2, ',');
    } else if ( genre == 'C') {
      //getline(infile, )
      std::string a1, a2, a3, a4;
      infile >> a1 >> a2;
      //concatenate day and year released
      attr1 = a1 + " " + a2;
      std::cout << attr1 << std::endl;
      infile >> a3 >> a4;
      //concatenate major actor
      attr2 = a3 + " " + a4;
      std::cout << attr2 << std::endl;
    } else {
      std::string junk;
      std::cout << "error: genre doesnt exist" << std::endl;
      getline(infile, junk, '\n');
      return false;
    }
  } else {
    std::string junk;
    std::cout << "error: item type doesnt exist" << std::endl;
    getline(infile, junk, '\n');
    return false;
  }
  return true;
}
