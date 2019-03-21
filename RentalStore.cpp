#include "RentalStore.h"

RentalStore::RentalStore() {
  std::cout << "constructed" << std::endl;
}

/*  Constructor accepts file as parameter which is used to fill the inventory.
    Then calls readInCustomer method that opens second file to read in customers
    and fill in customerList.
*/
RentalStore::RentalStore( ifstream& inventoryFile ) {
  DVDinventoryObj.fillInventory( inventoryFile );
  inventoryFile.close();
  //fill customerList
  readInCustomerList();
}

/*  Reads in transactions from a txtfile. Each line is a transaction.
    Options are Borrow, Return, Print History of Customer, and Print Inventory
    (all represented by the cases in switch)
    Pre-req: Inventory and customerList have to be filled.
    Post-req: Inventory and customerList same, transactions added to some customers,
    and stock levels will vary depending on # of borrows and returns.
*/
void RentalStore::readTransactions( ifstream& infile ) {
  //declare variables:
  char action, itemType, genre; int custID; std::string attr1, attr2;
  Customer* cust = NULL; //one customer per action
  bool setInfo, valid;
  //read in action
  while ( infile >> action ) {
    switch (action) {

      case 'B':   //borrow item
          std::cout << "borrow item" << std::endl;
          //read in info from file for borrowing
          setInfo = setItemInfo(infile, itemType, genre, custID, attr1, attr2);
          if (!setInfo) //if itemtype or genre was not valid, cant borrow
            break;

          //valid = DVDinventoryObj.borrowItem( genre, attr1, attr2 ); //change stock #
          valid = true; //temp
          if (valid) {
            cust = customerList.get(custID);

            if (cust != NULL) {
              std::cout << "customer: " << cust->getID() << std::endl;
              //add transaction missing title from classics
              std::string title = attr1 + " " + attr2;
              cust->addHistory('B', itemType, genre, title );

            } else {
              std::cout << "error: customer not found" << std::endl;
            }

          } else {
            std::cout << "error: movie not found" << std::endl;
          }

          break;


      case 'R':   //return item
          std::cout << "return item" << std::endl;
          setInfo = setItemInfo(infile, itemType, genre, custID, attr1, attr2);
          if (!setInfo) //if itemtype or genre was not valid, cant borrow
            break;

          //valid = DVDinventoryObj.returnItem( genre, attr1, attr2 ); //change stock #
          valid = true; //temp
          if (valid) {
            cust = customerList.get(custID);

            if (cust != NULL) {
              std::cout << "customer: " << cust->getID() << std::endl;
              //add transaction missing title from classics
              std::string title = attr1 + " " + attr2;
              cust->addHistory('R', itemType, genre, title);

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
            cust->printHistory();
          } else {
            std::cout << "error: customer doesn't exist" << std::endl;
          }

          break;


      case 'I':   //print store inventory
          std::cout << "print Inventory" << std::endl;
          //DVDinventory.printInventory();
          break;
      default:
        //if invalid action, error message?
        std::cout << "error: invalid action" << std::endl;
        std::string junk;
        getline(infile, junk, '\n');
    }
  }
}

/*  Reads in customers (unique id, first name, and last name) from text file,
    creates a Customer object for each, and adds them to the customerList hashtable,
    where the key is their unique id.
    Pre-req: customer text file needs to exist and be filled.
    Post-req: customerList is filled.
*/
void RentalStore::readInCustomerList() {
  //open customer file
  ifstream infile("data4customers.txt");
  if (!infile) {
    //return 1;
    std::cout << "error: file didn't open" << std::endl;
  }

  //read in customers
  int id; std::string firstName, lastName;
  while ( infile >> id >> firstName >> lastName ) {
    //std::cout << id << firstName << lastName;
    Customer newCustomer(id, firstName, lastName);
    customerList.insert(id, newCustomer);
  }

}

//  Prints out each customer per line. Unique id, first name, last name.
void RentalStore::printCustomerList() {
  customerList.printTable();
}

/*  Helper function to method readTransactions.
    Reads in all necessary info from textfile to complete a borrow or return transaction.
    attr1 and attr2 refer to unique attributes of each movie genre.
    Comedy: movie title, year released
    Drama: director, movie title
    Classic: release date, major actor
    Handles errors (prints error): invalid item type, invalid genre.
    Post-req: Parameters are all set in readTransactions method.
*/
bool RentalStore::setItemInfo( ifstream& infile, char& itemType, char& genre, int& custID, std::string& attr1, std::string& attr2 ) {
  infile >> custID >> itemType >> genre;

  if (itemType == 'D') {

      if ( genre == 'F') {
        getline(infile, attr1, ',');          //movie title
        getline(infile, attr2, '\n');         //year released

      } else if ( genre == 'D') {
        getline(infile, attr1, ',');          //director
        getline(infile, attr2, ',');          //movie title

      } else if ( genre == 'C') {
        std::string a1, a2, a3, a4;
        infile >> a1 >> a2;

        //concatenate day and year released
        attr1 = a1 + " " + a2;                //release date (month + year)
        std::cout << attr1 << std::endl;
        infile >> a3 >> a4;

        //concatenate major actor
        attr2 = a3 + " " + a4;                //major actor (first + lastname)
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
