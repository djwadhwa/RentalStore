#include "LinkedQueue.h"
//#include "LinkedStack.h"

#include <fstream>

using namespace std;
/**
 * Constructor for LinkedQueue
 */
template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
    this->head = NULL;
    this->size = 0;
}
/**
 * Destructor for LinkedQueue
 */
template <class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
    DeleteQueue();
}
/**
 * Build a LinkedQueue by using some data from a file
 * @param fileName the name of the file
 * @ret false if the method cannot find the file to be used to create nodes in the LinkedQueue
 * @ret true if the method finds the file 
 * and make nodes for the Linked Queue out of the data inside the file 
 */
template <class ItemType>
bool LinkedQueue<ItemType>::BuildQueue(string fileName)
{
    ifstream openFile;
    openFile.open(fileName);
    if(openFile.is_open())
    {
        ItemType data;
        while(openFile >> data)
        {
            Enqueue(&data);
        }
        openFile.close();
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * Queue a Node to a LinkedQueue object
 * @param *obj the pointer to the object that will be made as the data o a Node 
 * and then queue the Node to LinkedQueue
 */
template <class ItemType>
void LinkedQueue<ItemType>::Enqueue(ItemType *obj)
{
    Node *node = new Node;
    ItemType *newData = new ItemType;
    *newData = *obj;
    node->data = newData;
    node->next = NULL;
    if (this->size == 0 && this->head == NULL)
    {
        head = node;
        this->size += 1;
    }
    else if (this->size > 0 && this->head != NULL)
    {
        Node* curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        Node** addCurr = &(curr->next);
        *addCurr = node;
        this->size += 1;
    }
}
/**
 * Pull out a Node from a LinkedQueue
 * @param &result the referrence that will record the data of the Node that will be pulled out
 * @ret false if there are no Nodes in the LinkedQueue
 * @ret true if there are a Node or more in the LinkedQueue and remove the front Node successfully
 */
template <class ItemType>
bool LinkedQueue<ItemType>::Dequeue(ItemType &result)
{
    if (this->size == 0 && this->head == NULL)
    {
        return false;
    }
    else if (this->size > 0 && this->head != NULL)
    {
        Node* curr = head;
        Node** delCurr = &(head);
        result = *(curr->data);
        *delCurr = curr->next;
        head = curr->next;
        delete curr->data;
        delete curr;
        this->size -= 1;
        return true;
    }
}
/**
 * Take a look at the front Node in the LinkedQueue
 * @param &result the referrence that will record the data of tbe Node that will be peeked
 * @ret false if there are no Nodes in the LinkedQueue
 * @ret true if there are a Node or more in the LinkedQueue 
 * and peeked the data of the front Node successfully
 */
template <class ItemType>
bool LinkedQueue<ItemType>::Peek(ItemType &result) const
{
    if (this->size == 0 && this->head == NULL)
    {
        return false;
    }
    else if (this->size > 0 && this->head != NULL)
    {
        Node* curr = head;
        result = curr->data;
        curr = NULL;
        return true;
    }
}
/**
 * Check if there are Nodes in the LinkedQueue
 * @ret false if there is a Node or more in the LinkedQueue
 * @ret true if there are no Nodes in the LinekdQueue
 */
template <class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
    if (this->head == NULL && this->size == 0)
    {
        return true;
    }
    else if (this->head != NULL && this->size > 0)
    {
        return false;
    }
}
/**
 * Give the count of Nodes inside a LinkedQueue
 * @ret this->size the size of the LinkedQueue
 */
template <class ItemType>
int LinkedQueue<ItemType>::Size() const
{
    return this->size;
}
/**
 * Delete every Nodes inside a LinkedQueue
 */
template <class ItemType>
void LinkedQueue<ItemType>::DeleteQueue()
{
    Node* curr = head;
    this->size = 0;
    while (head != NULL)
    {
        head = head->next;
        delete curr->data;
        delete curr;
        curr = head;
    }
    delete curr;
    delete head;
    curr = NULL;
    head = NULL;
}
/**
 * Overload "==" overload
 * @param &queue the LinkedQueue that will be compared with the other LinkedQueue (this)
 * @ret true if every Nodes on each LinkedQueue that is compared are the same 
 * (same datas of each Node, Nodes' order, and size of the LinkedQueue)
 * @ret false if the two LinkedQueue are different
 */
template <class ItemType>
bool LinkedQueue<ItemType>::operator==(const LinkedQueue &queue) const
{
    if (this->size == queue.size)
    {
        Node* curr = head;
        Node* otherCurr = queue.head;
        while (curr != NULL && otherCurr != NULL)
        {
            if (*(curr->data) == *(otherCurr->data))
            {
                curr = curr->next;
                otherCurr = otherCurr->next;
            }
            else
            {
                curr = NULL;
                otherCurr = NULL;
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * Overload "!=" overload
 * @param &queue the LinkedQueue that will be compared with the other LinkedQueue (this)
 * @ret false if every Nodes on each LinkedQueue that is compared are the same 
 * (same datas of each Node, Nodes' order, and size of the LinkedQueue)
 * @ret true if the two LinkedQueue are different
 */
template <class ItemType>
bool LinkedQueue<ItemType>::operator!=(const LinkedQueue &queue) const
{
    return !(*this == queue);
}
template <class ItemType>
/**
 * Overload "=" overload, make a deep copy from a LinkedQueue to another LinkedQueue
 * @param &queue the referrence to a LinkedQueue that will be copied
 * @ret *this contains the copy of &queue
 */
LinkedQueue<ItemType>& LinkedQueue<ItemType>::operator=(const LinkedQueue &queue)
{
    DeleteQueue();
    Node* curr = queue.head;
    while(curr != NULL)
    {
        Enqueue(curr->data);
        curr = curr->next;
    }
    return *this;
}

template <class ItemType>
void LinkedQueue<ItemType>::printQueue()
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << *curr->data << endl;
        curr = curr->next;
    }
}
