#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>

using namespace std;
class Customer
{
    friend ostream& operator<< (ostream &outStream, const Customer &cus);

    public:
        Customer();
        Customer(int);
        Customer(int, string, string);
        ~Customer();
        string getFirstName() const;
        string getLastName() const;
        int getID() const;
        void setFirstName( string name );
        void printHistory() const;
        void addHistory(char transType, char mediaType, string title);
        bool operator==(const Customer &cus) const;
        bool operator!=(const Customer &cus) const;
        Customer& operator=(const Customer &cus);

    private:
        int id;
        string firstName, lastName;

        struct TransNode {
          char transType;
          char mediaType;
          string title;
          TransNode* next;
      };
      TransNode* head;
};
#endif
