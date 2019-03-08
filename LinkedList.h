#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

template <class ItemType> //templatize class to type ItemType
class LinkedList
{
  friend std::ostream& operator<<(std::ostream& out, const LinkedList& listObject)
  {
    //overload << operator to print contents of linked list when "cout<<" is called
    Node * current = listObject.head;
    while (current != nullptr)
    {
      out << *(current->value);
      current = current->next;
    }
    return out;
  }
public:
  LinkedList(); //constructor
  ~LinkedList(); //destructor

  bool Insert(ItemType *obj); //inserts element and sort from smallest to largest
  bool isEmpty() const; //return true if Linked List is empty
  bool Peek(ItemType target, ItemType &result); //returns the value of target as result if it exists in the Linked List
  bool Remove(ItemType target, ItemType &result); // same as Peek but also removes the element
  bool Merge(LinkedList &listObject); //merges two lists together in sorted order
  void DeleteList(); //deletes contents of the linked list
  int getSize() const; //returns the size of the LinkedList
  bool operator==(const LinkedList<ItemType>& listObject) const; //operator overload for ==
  bool operator!=(const LinkedList<ItemType>& listObject) const; //operator overload for !=
  LinkedList<ItemType>& operator=(const LinkedList<ItemType> & listObject); //operator overload for =
  LinkedList<ItemType>& operator+=(const LinkedList<ItemType>& listObject);//operator overload for +=
  LinkedList<ItemType> operator+(const LinkedList<ItemType>& listObject); //operator overload for +

private:
  struct Node //node struct definition
  {
    ItemType *value;
    Node *next;
  };
  Node *head; //head Node
  int size; //size of the LinkedList
};
#include "LinkedList.cpp" //include LinkedList.cpp in order to templatize class
#endif
