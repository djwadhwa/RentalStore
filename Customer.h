#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include "Transaction.h"
using namespace std;
class Customer
{
    public:
        Customer();
        Customer(int, string, string);
        ~Customer();
        string getFirstName();
        string getLastName();
        int getID();
        void printHistory();
        void addHistory(Transaction );

    private:
        int id;
        string firstName, lastName;
        //linked list of the transaction for each customer
};
#endif