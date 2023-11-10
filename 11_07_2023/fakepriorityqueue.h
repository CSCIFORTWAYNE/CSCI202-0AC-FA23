#include "linkedQueue.h"

template <class t>
class fakepriorityqueue : public linkedQueue<t>
{
public:
    void enqueue(const t &);
};

template <class t>
inline void fakepriorityqueue<t>::enqueue(const t &queueElement)
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
    }
}
