#include "HashTable.h"

HashTable::HashTable() {
  cout << "constructor";
  //filling array with 0's, first thing inserted would be hashnode
}

int HashTable::hashfunction( int key ) {
  return key % 100;
}

bool HashTable::insert( int key, ItemType value ) {
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

ItemType& HashTable::getItem( int key ) {

}

#endif
