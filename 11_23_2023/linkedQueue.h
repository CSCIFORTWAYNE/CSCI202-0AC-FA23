#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "queueADT.h"
#include <stdexcept>

template <class t>
struct queueNode
{
    t *data;
    queueNode<t> *link;
    ~queueNode()
    {
        delete data;
    }
};

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
    queueNode<t> *queueFront;
    queueNode<t> *queueRear;
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
void linkedQueue<t>::initializeQueue()
{
    queueNode<t> *current;
    while (this->queueFront != nullptr)
    {
        current = this->queueFront;
        this->queueFront = this->queueFront->link;
        delete current;
    }
    this->queueRear = nullptr;
}

template <class t>
inline t linkedQueue<t>::front() const
{
    if (this->isEmptyQueue())
        throw std::out_of_range("Cannot view item in an empty queue.");
    return *(queueFront->data);
}

template <class t>
inline t linkedQueue<t>::back() const
{
    if (this->isEmptyQueue())
        throw std::out_of_range("Cannot view item in an empty queue.");
    return *(queueRear->data);
}

template <class t>
void linkedQueue<t>::enqueue(const t &queueElement)
{
    queueNode<t> *newNode;
    newNode = new queueNode<t>;
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
    }
}

template <class t>
inline t linkedQueue<t>::dequeue()
{
    if (isEmptyQueue())
        throw std::out_of_range("Cannot remove from an empty queue.");
    else
    {
        queueNode<t> *temp;
        temp = this->queueFront;
        this->queueFront = this->queueFront->link;
        t ret(*(temp->data));
        delete temp;
        return ret;
    }
}

template <class t>
inline const linkedQueue<t> &linkedQueue<t>::operator=(const linkedQueue<t> &otherQueue)
{
    if (this != &otherQueue)
        copyQueue(otherQueue);

    return *this;
}

template <class t>
inline linkedQueue<t>::linkedQueue()
{
    this->queueFront = nullptr;
    this->queueRear = nullptr;
}

template <class t>
inline linkedQueue<t>::linkedQueue(const linkedQueue<t> &otherQueue)
{
    queueFront = nullptr;
    queueRear = nullptr;
    copyQueue(otherQueue);
}

template <class t>
linkedQueue<t>::~linkedQueue()
{
    initializeQueue();
}

template <class t>
void linkedQueue<t>::copyQueue(const linkedQueue<t> &otherQueue)
{
    this->initializeQueue();
    queueNode<t> *current;
    current = otherQueue.queueFront;
    while (current != nullptr)
    {
        this->enqueue(*(current->data));
        current = current->link;
    }
}
#endif