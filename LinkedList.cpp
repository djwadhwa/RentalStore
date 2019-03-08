#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP
#include "LinkedList.h"
#include <iostream>

template <class ItemType>
LinkedList<ItemType>::LinkedList()
{
  this->head = nullptr; //set head to null
  size =0; //set size to zero
}
template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
  DeleteList(); //destructor calls DeleteList;
}
template <class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
  return this->head==nullptr; //if head points to null, the list is empty
}
template <class ItemType>
int LinkedList<ItemType>::getSize() const{
return this->size; //returns the size of the list
}
template <class ItemType>
bool LinkedList<ItemType>::Insert(ItemType *obj)
{
  Node *n = new Node; //create new node;
  ItemType *object = new ItemType; //create object that is stored on the heap
  *object = *obj; //copy the value of obj into the object in heap
  n->value = object; //point node value to the object in heap
  if (isEmpty())
  {
    head = n; //if the list is empty then make a new node and point the head to that node
     n->next = nullptr; //set next pointer to null
    size++; //increment size
    return true; //return true
  }
  if (*(head->value) >= *n->value) //if value entered is less or equal to than head->value then:
  {
    if (*(head->value) == *n->value)
    {
      //delete from heap because it is a duplicate
      delete object;
      delete n;
      return false; //return false
    }
    //else point n->next to head and then set head to the new node
    n->next = head;
    head =n;
    size++; // increment size
    return true; //return true
  }
  else // else if we are inserting after the head
  {
  Node * current = head; //create pointer current that points to head
  Node **currentAddress=&current; //create another pointe that points to the address of current, this allows to make changes to previous nodes
  while (current!=nullptr && *(current->value)<= *(n->value)) // while current isn't null and its value is lest than the new node's value:
  {
      if (*(current->value)== *(n->value))
      { //if the values are the same then they are duplicates
        delete object; //delete object from heap
        delete n; //delete node from heap
        return false; //return false
      }
      currentAddress = &current->next;
      current = current->next;
    }
    n->next = current;
    *currentAddress=n;
    size++;
    return true;
  }

}
template <class ItemType>
bool LinkedList<ItemType>::Peek(ItemType target, ItemType &result)
{
  Node * current = head;
  while (current!=nullptr )
  {
    if (*(current->value )==target)
    {
      result = *(current->value);
      return true;
    }
      current = current->next;
}
return false;
}
template <class ItemType>
bool LinkedList<ItemType>::Remove(ItemType target, ItemType &result)
{
  Node * current = head;
  Node **currentAddress = &current;
  while (current!=nullptr )
  {
    if (*(current->value )==target)
    {
      result = *(current->value);
      *currentAddress = current->next;
      delete current->value;
      delete current;
      size--;
      return true;
    }
    currentAddress=&current->next;
    current = current->next;
}
return false;
}
template <class ItemType>
void LinkedList<ItemType>::DeleteList()
{
  Node * current = head;
  while (current != nullptr)
  {
    Node * temp = current;
    delete temp->value;
    current=current->next;
    delete (temp);

  }
  head = nullptr;
}
template <class ItemType>
bool LinkedList<ItemType>::Merge(LinkedList & listObject)
{
  if (* this == listObject)
  {
    return false;
  }
  Node* current = listObject.head;
  while (current !=nullptr)
  {
      ItemType *temp = new ItemType;
      *temp = *(current->value);
      Insert(temp);
      current = current->next;
  }
  listObject.DeleteList();
  return true;
}

template <class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType>& listObject) const
{
  Node * current1 = this->head;
  Node * current2 = listObject.head;
if (this->size == listObject.getSize()){
  while (current1 != nullptr && current2!= nullptr)
  {
    if (*(current1->value)!=*(current2->value))
    {
      return false;
    }
    current1= current1->next;
    current2= current2->next;
  }
  return true;
}
  return false;
}
template <class ItemType>
bool LinkedList<ItemType>::operator!=(const LinkedList<ItemType>& listObject) const
{
  Node * current1 = this->head;
  Node * current2 = listObject.head;
if (this->size !=listObject. getSize())
{
  return true;
}
while (current1 != nullptr && current2!= nullptr)
{
  if (*(current1->value)!=*(current2->value))
  {
    return true;
  }
  current1= current1->next;
  current2= current2->next;
}
return false;
}
template <class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList<ItemType> & listObject)
{
    DeleteList();
    Node* current = listObject.head;
    while (current !=nullptr)
    {
        ItemType *temp = new ItemType;
        *temp = *(current->value);
        Insert(temp);
        current = current->next;
    }
    return *this;
}
template <class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator+=(const LinkedList<ItemType>& listObject)
{
  Node* current = listObject.head;
  while (current !=nullptr)
  {
      ItemType *temp = new ItemType;
      *temp = *(current->value);
      Insert(temp);
      current = current->next;
  }
  return *this;
}
template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList<ItemType>& listObject)
{
  LinkedList <ItemType>list;
  Node* current = listObject.head;
  while (current !=nullptr)
  {
      ItemType *temp = new ItemType;
      *temp = *(current->value);
      list.Insert(temp);
      current = current->next;
  }
  return list;
}
#endif
