#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>

template<ItemType>
class HashTable {

public:
  HashTable();
  int hashfunction( int key );
  bool insert( int key, ItemType value );
  //remove function
  ItemType& getItem( int key ); //??


private:
  //ItemType* hashTable;
  //int size;
  struct HashNode {
    int key;
    ItemType value;
    HashNode* next; //maybe needs struct infront?
  };

  ItemType hashtable[100];  //make 100 constant var

};

#include "HashTable.cpp"
#endif
