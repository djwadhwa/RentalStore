#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <iostream>

/*    @TinaFedorov
      HashTable template class represents the hashtable data structure.
      An array of HashNode pointers is used for storage, and each object inserted
      is stored in HashNode as "value".
      Collision is handled with open hashing approach with linkedlists made up
      of HashNode objects.

      Invariants:
        - only holds up to 100 buckets
*/

template<class ItemType>
class HashTable {

  public:
    HashTable();  //default constructor

    int hashfunction( int key ); //used to hash the key and find index
    bool insert( int key, ItemType value ); //insert object into hashtable
    ItemType* get( int key );    //returns pointer to object so it can be manipulated
    void printTable();           //print every object in hashtable

  private:

    struct HashNode {
      int key;        //key before hashing (not the index)
      ItemType value; //the template object
      HashNode* next; //maybe needs struct infront?
    };

    HashNode** hashtable; //100 buckets
    const int TABLE_SIZE = 100; //default size of the array

};

/*   Default constructor, sets all "buckets"/pointers to NULL.
*/
template<class ItemType>
HashTable<ItemType>::HashTable() {
  hashtable = new HashNode*[TABLE_SIZE];

  for ( int i = 0; i < TABLE_SIZE; i++ ) {
    hashtable[i] = NULL;
  }
}

/*   hashfunction accepts unique key and returns the index where object identified
     by unique key will be placed.
*/
template<class ItemType>
int HashTable<ItemType>::hashfunction( int key ) {
  return key % 100;
}

/*   Inserts HashNode to hashtable. Key is used to identify which index to place
    HashNode. The value is stored as "value" in the HashNode.
    Collision is handled with open hashing approach with "linkedlist" of HashNodes
*/
template<class ItemType>
bool HashTable<ItemType>::insert( int key, ItemType value ) {
  int index = hashfunction(key);

  if ( hashtable[index] == NULL ) {
      hashtable[index] = new HashNode;
      hashtable[index]->key = key;
      hashtable[index]->value = value;
      hashtable[index]->next = NULL;

    } else {  //collision case
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

/*    Prints out every object value in hashtable
*/
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

//returns pointer to the object thats identified by unique key parameter.
template<class ItemType>
ItemType* HashTable<ItemType>::get( int key ) {
  int index = hashfunction(key);

  if (hashtable[index] == NULL)
    return NULL;

  HashNode* current = hashtable[index];
  while (current != NULL) {
    if ( current->key == key ) {
      return (&current->value);
    }
    current = current->next;
  }

  return NULL;
}

#endif
