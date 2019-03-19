#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include "Transaction.h"
#include "LinkedQueue.h"
using namespace std;
class Customer
{
    public:
        Customer();
        Customer(int);
        Customer(int, string, string);
        ~Customer();
        string getFirstName() const;
        string getLastName() const;
        int getID() const;
        void printHistory() const;
        void addHistory(Transaction );

    private:
        int id;
        string firstName, lastName;
        LinkedQueue<Transaction> transHist;     //linked list of the transaction for each customer

};
#endif
