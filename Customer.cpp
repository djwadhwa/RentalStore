#include "Customer.h"
#include <string>
#include <iostream>
using namespace std;

Customer::Customer()
{
    this->firstName = "";
    this->lastName = "";
    this->id = 0;
}

Customer::Customer(int id)
{
    this->firstName = "";
    this->lastName = "";
    this->id = id;
}

Customer::Customer(int id, string fn, string ln)
{
    this->firstName = fn;
    this->lastName = ln;
    this->id = id;
}

Customer::~Customer()
{

}

string Customer::getFirstName() const
{
    return firstName;
}

void Customer::setFirstName( string name ) {
  firstName = name;
}

string Customer::getLastName() const
{
    return lastName;
}

int Customer::getID() const
{
    return id;
}
/*
void Customer::printHistory() const
{
    cout << firstName << "'s current transactions history:" << endl;
    cout << transHist;
}*/
/*
void Customer::addHistory(Transaction t)
{
    transHist.Enqueue(&t);
}
*/
bool Customer::operator==(const Customer &cus) const
{
    if (this->firstName == cus.firstName)
    {
        if (this->lastName == cus.firstName)
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

bool Customer::operator!=(const Customer &cus) const
{
    return !(*this == cus);
}
Customer& Customer::operator=(const Customer &cus)
{
    this->firstName = cus.firstName;
    this->lastName = cus.lastName;
    this->id = cus.id;
    return *this;
}

ostream& operator<< (ostream &outStream, const Customer &cus)
{
    outStream << cus.id << ", " << cus.firstName << ", " << cus.lastName << endl;
    return outStream;
}
