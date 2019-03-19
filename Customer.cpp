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

string Customer::getLastName() const
{
    return lastName;
}

int Customer::getID() const
{
    return id;
}

void Customer::printHistory() const
{
    cout << firstName << "'s current transactions history:" << endl;
    cout << transHist;
}

void Customer::addHistory(Transaction t)
{
    transHist.Enqueue(&t);
}
