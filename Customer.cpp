#include "Customer.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * Default constructor for Customer
 */
Customer::Customer()
{
    this->firstName = "";
    this->lastName = "";
    this->id = 0;
    head = nullptr;
}

/**
 * Constructor for Customer, specify the ID
 */
Customer::Customer(int id)
{
    this->firstName = "";
    this->lastName = "";
    this->id = id;
    head=nullptr;
}

/**
 * Constructor for Customer, specify the ID, first name, and last name
 */
Customer::Customer(int id, string fn, string ln)
{
    this->firstName = fn;
    this->lastName = ln;
    this->id = id;
    head = nullptr;
}

/**
 * Destructor for Customer
 */
Customer::~Customer()
{

}

/**
 * Get the customer's first name
 * @return firstName the Customer's first name
 */
string Customer::getFirstName() const
{
    return firstName;
}

/**
 * Change the customer's first name
 * @param name the updated first name
 */
void Customer::setFirstName( string name ) {
  firstName = name;
}

/**
 * Get the customer's last name
 * @return lastName the customer's last name
 */
string Customer::getLastName() const
{
    return lastName;
}

/**
 * Get the customer's ID
 * @return id the customer's ID
 */
int Customer::getID() const
{
    return id;
}

/**
 * Print all the Customer's transactions with the Rental Store
 */
void Customer::printHistory() const
{
    cout << firstName << lastName << "'s current transactions history:" << endl;
    if (head == nullptr)
    {
      std::cout << "customer has no history" << '\n';
    }
    TransNode * current = head;
    while (current != nullptr)
    {
      std::cout << (current->transType) <<" "<< (current->mediaType) <<" "<< (current->genre) <<" "<< (current->title) << '\n';
      current = current-> next;
    }
}

/**
 * Add a transaction to the customer's transactions history
 * @param transType the transaction type
 * @param mediaType the media in the transaction
 * @param genre the genre of the media type
 * @param title specific details of the item
 */
void Customer::addHistory(char transType, char mediaType, char genre, string title)
{
  if (head == nullptr)
  {
    TransNode * node = new TransNode;
    head = node;
    node->transType = transType;
    node->mediaType = mediaType;
    node->genre = genre;
    node-> title = title;
    node->next = nullptr;
  }
  else
  {
    TransNode * current = head;

    while (current != nullptr)
    {
      if (current->next == nullptr)
      {
        TransNode * node = new TransNode;
        node->transType = transType;
        node->mediaType = mediaType;
        node->genre = genre;
        node-> title = title;
        current->next= node;
        node-> next = nullptr;
        break;
      }
      current = current->next;
    }

  }

}

/**
 * "==" operator overload for customer
 * @param &cus the Customer that will be compared with the assigned Customer
 * @return false if they are not the same
 * @return true if they are the same
 */
bool Customer::operator==(const Customer &cus) const
{
    if (this->firstName == cus.firstName)
    {
        if (this->lastName == cus.lastName)
        {
            if (this->id == cus.id)
            {
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

/**
 * "!=" operator overload for customer
 * @param &cus the Customer that will be compared with the assigned Customer
 * @return false if they are the same
 * @return true if they are not the same
 */
bool Customer::operator!=(const Customer &cus) const
{
    return !(*this == cus);
}

/**
 * "=" operator overload for customer
 * @param &cus the Customer that will be copied to the assigned Customer
 * @return *this the updated, assigned Customer
 */
Customer& Customer::operator=(const Customer &cus)
{
    this->firstName = cus.firstName;
    this->lastName = cus.lastName;
    this->id = cus.id;
    return *this;
}

/**
 * "<<" operator overload for customer
 * @param &outStream the statements that will be printed
 * @param &cus the Customer that will be printed
 * @return outStream the printed statements
 */
ostream& operator<< (ostream &outStream, const Customer &cus)
{
    outStream << cus.id << ", " << cus.firstName << ", " << cus.lastName << endl;
    return outStream;
}
