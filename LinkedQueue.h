#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include <iostream>
#include <memory>

using namespace std;
template <class ItemType>
class LinkedQueue
{
    /**
     * Overload "<<" operator
     * Prints all the data inside every Nodesin a LinkedQueue
     * @param &queue the LinkedList that will be used and printed
     * @return outStream data that will be printed
     */
    friend ostream& operator<<(ostream& outStream, const LinkedQueue &queue)
    {
        Node *curr = queue.head;
        while (curr != NULL)
        {
            outStream << *curr->data << endl;
            curr = curr->next;
        }
        return outStream;
    }
    private:
    struct Node
    {
        Node* next;
        ItemType* data;
    };
    Node* head;
    int size;

    public:
    //constructor and destructor
    LinkedQueue();
    ~LinkedQueue();
    //methods
    bool BuildQueue(string fileName);
    void Enqueue( ItemType *obj );
    bool Dequeue(ItemType &result);
    bool Peek(ItemType &result) const;
    bool isEmpty() const;
    int Size() const;
    void DeleteQueue();
    void printQueue();
    //==, !=, and = operator overload
    bool operator==(const LinkedQueue &queue) const;
    bool operator!=(const LinkedQueue &queue) const;
    LinkedQueue& operator=(const LinkedQueue &queue);

};
#endif
