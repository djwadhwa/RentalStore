#include "HashTable.h"

template<class ItemType>
HashTable<ItemType>::HashTable() {
  //fill hastable with head pointers
  //int TABLE_SIZE = 100;
  /*
  hashtable = new HashList*[TABLE_SIZE]; //change to constant
  for ( int i = 0; i < TABLE_SIZE; i++ ) {
    hashtable[i]->head = NULL;
  }
  */
  std::cout << "constructor";
  //filling array with 0's, first thing inserted would be hashnode
}
/*
template<class ItemType>
int HashTable<ItemType>::hashfunction( int key ) {
  return key % 100;
}

template<class ItemType>
bool HashTable<ItemType>::insert( int key, ItemType value ) {
  int index = hashfunction(key);

//if index is empty
  if (hashtable[index] == 0) {
    HashNode newNode = new HashNode;
    newNode.key = key;
    newNode.value = value;
    newNode.next = NULL;
    hashtable[index] = newNode;

  } else {  //collision case

  }


}

template<class ItemType>
ItemType& HashTable<ItemType>::getItem( int key ) {
  int index = hashfunction(key);
  if (hashtable[index] != NULL) // null or 0?
    return hashtable[index];
  return NULL;
}
*/
