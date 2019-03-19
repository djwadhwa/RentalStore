#include "HashTable.h"
#include "Customer.h"
//#include <string>

int main() {

  std::string s1 = "John";
  std::string s2 = "Doe";
  int id = 1234;
  HashTable<Customer> h;
  Customer John( id, s1, s2 );
  h.insert( 1234, John );

/*
  HashTable<int> j;
  j.insert( 1334, 13 );
  j.insert(1234, 5);
  j.insert(1134, 85);

  j.printTable();

  std::cout << j.getItem(1234);
*/
  return 0;
}
