#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>

template<class ItemType>
class HashTable {

  public:
    HashTable();

    int hashfunction( int key );
    bool insert( int key, ItemType value );
    ItemType getItem( int key );
    void printTable();

  private:

    struct HashNode {
      int key;
      ItemType value;
      HashNode* next; //maybe needs struct infront?
    };

    HashNode** hashtable;
    const int TABLE_SIZE = 100; //default size of the array

};


template<class ItemType>
HashTable<ItemType>::HashTable() {
  hashtable = new HashNode*[TABLE_SIZE];

  for ( int i = 0; i < TABLE_SIZE; i++ ) {
    hashtable[i] = NULL;
  }
}

template<class ItemType>
int HashTable<ItemType>::hashfunction( int key ) {
  return key % 100;
}

template<class ItemType>
bool HashTable<ItemType>::insert( int key, ItemType value ) {
  int index = hashfunction(key);

  if ( hashtable[index] == NULL ) {
      hashtable[index] = new HashNode;
      hashtable[index]->key = key;
      hashtable[index]->value = value;
      hashtable[index]->next = NULL;

    } else {  //collision case
      std::cout << "collision case";

      HashNode* current = hashtable[index];
      while (current->next != NULL )
        current = current->next;

      current->next = new HashNode;
      current = current->next;
      current->key = key;
      current->value = value;
      current->next = NULL;
    }

  return true;

}

template<class ItemType>
void HashTable<ItemType>::printTable() {
  for ( int i = 0; i < TABLE_SIZE; i++ ) {
    if ( hashtable[i] == NULL ) {
      std::cout << i << " set to null" << std::endl;
    } else {
      HashNode* current = hashtable[i];
      std::cout << i;
       while (current != NULL) {
        std::cout << " " << current->value ;
        current = current->next;
      }
      std::cout << std::endl;

    }
  }
}

template<class ItemType>
ItemType HashTable<ItemType>::getItem( int key ) {
  int index = hashfunction(key);

  if (hashtable[index] == NULL)
    return NULL;

  HashNode* current = hashtable[index];
  while (current != NULL) {
    if ( current->key == key ) {
      return current->value;
    }
    current = current->next;
  }

  return NULL;
}

#endif
