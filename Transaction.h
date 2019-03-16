#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <iostream>
using namespace std;

class Transaction
{
public:
  void printTransaction();

private:
  char transType, mediaType;
  string title;
}
