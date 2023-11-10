#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "queueADT.h"
#include "node.h"
#include <stdexcept>

template <class t>
class linkedQueue : public queueADT<t>
{
public:
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    t front() const;
    t back() const;
    void enqueue(const t &queueElement);
    t dequeue();
    const linkedQueue<t> &operator=(const linkedQueue<t> &);
    linkedQueue();
    linkedQueue(const linkedQueue<t> &);
    ~linkedQueue();

protected:
    node<t> *queueFront;
    node<t> *queueRear;
    void copyQueue(const linkedQueue<t> &);
};

template <class t>
inline bool linkedQueue<t>::isEmptyQueue() const
{
    return this->queueFront == nullptr;
}
template <class t>
inline bool linkedQueue<t>::isFullQueue() const
{
    return false;
}
template <class t>
inline void linkedQueue<t>::initializeQueue()
{
    node<t> *current;
    while (!isEmptyQueue())
    {
        current = this->queueFront;
        this->queueFront = this->queueFront->link;
        delete current;
        current = nullptr;
    }
    this->queueRear = nullptr;
}
template <class t>
inline t linkedQueue<t>::front() const
{
    if (this->isEmptyQueue())
        throw std::out_of_range("Cannot view an item in an empty queue.");

    return *(queueFront->data);
}
template <class t>
inline t linkedQueue<t>::back() const
{
    if (this->isEmptyQueue())
        throw std::out_of_range("Cannot view an item in an empty queue.");

    return *(queueRear->data);
}
template <class t>
inline void linkedQueue<t>::enqueue(const t &queueElement)
{
    node<t> *newNode;
    newNode = new node<t>;
    newNode->data = new t(queueElement);
    newNode->link = nullptr;
    if (this->isEmptyQueue())
    {
        this->queueFront = newNode;
        this->queueRear = newNode;
    }
    else
    {
        this->queueRear->link = newNode;
        this->queueRear = newNode;
        /* example for priority queue
        node<t> * current;
        node<t> * trailCurrent;
        current = queueFront;
        while(current != nullptr && !found)
        {
            if(*(current->data) < newElement)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if(current == queueFront)
        {
            newNode->link = queueFront;
            queueFront = newNode;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if(current == nullptr)
                queueRear = newNode;

        }
        */
    }
}
template <class t>
inline t linkedQueue<t>::dequeue()
{
    if (isEmptyQueue())
        throw std::out_of_range("Cannot remove from an empty queue.");

    node<t> *temp;
    temp = this->queueFront;
    this->queueFront = this->queueFront->link;
    t ret(*(temp->data));
    delete temp;
    return ret;
}
template <class t>
inline const linkedQueue<t> &linkedQueue<t>::operator=(const linkedQueue<t> &othQueue)
{
    if (this != &othQueue)
        copyQueue(othQueue);
    return *this;
}
template <class t>
inline linkedQueue<t>::linkedQueue()
{
    this->queueFront = nullptr;
    this->queueRear = nullptr;
}
template <class t>
inline linkedQueue<t>::linkedQueue(const linkedQueue<t> &othQueue)
{
    this->queueFront = nullptr;
    this->queueRear = nullptr;
    copyQueue(othQueue);
}
template <class t>
inline linkedQueue<t>::~linkedQueue()
{
    initializeQueue();
}
template <class t>
inline void linkedQueue<t>::copyQueue(const linkedQueue<t> &othQueue)
{
    this->initializeQueue();
    node<t> *current;
    current = othQueue.queueFront;
    while (current != nullptr)
    {
        this->enqueue(*(current->data));
        current = current->link;
    }
}
#endif