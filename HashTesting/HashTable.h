#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>

template<class ItemType>
class HashTable {

  public:
    HashTable();
    /*
    int hashfunction( int key );
    bool insert( int key, ItemType value );
    //remove function
    ItemType& getItem( int key ); //??
*/

  private:
    /*
    struct HashList {

      struct HashNode {
        int key;
        ItemType value;
        HashNode* next; //maybe needs struct infront?
      };

      HashNode* head;

    };

    HashList** hashtable;  //make 100 constant var; array of pointers
    const int TABLE_SIZE = 101; //default size of the array
*/
};

#include "HashTable.cpp"
#endif
