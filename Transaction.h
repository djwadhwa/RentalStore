#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <iostream>
using namespace std;

class Transaction
{
    friend ostream& operator<< (ostream &outStream, const Transaction &trans);
    
    public:
        Transaction();
        Transaction(char, char, string);
        ~Transaction();
        char getMediaType();
        char getTransType();
        string getTitle();
        void printTransaction();

    private:
        char transType, mediaType;
        string title;
};
#endif
