#include "Transaction.h"
#include <string>
#include <iostream>
using namespace std;

Transaction::Transaction()
{
    this->transType = NULL;
    this->mediaType = NULL;
    this->title = "";
}
Transaction::Transaction(char transType, char mediaType, string title)
{
    this->transType = transType;
    this->mediaType = mediaType;
    this->title = title;
}

Transaction::~Transaction()
{

}

char Transaction::getMediaType()
{
    return this->mediaType;
}

char Transaction::getTransType()
{
    return this->transType;
}

string Transaction::getTitle()
{
    return this->title;
}

ostream& operator<< (ostream &outStream, const Transaction &trans)
{
    outStream << trans.transType << " " <<  trans.mediaType << " " << trans.title;
    return outStream;
}
