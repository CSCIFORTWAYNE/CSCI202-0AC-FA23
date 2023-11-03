#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "stackADT.h"
#include "node.h"
#include <stdexcept>

template <class t>
class linkedStack : public stackADT<t>
{
public:
    linkedStack(int = DEFAULT_STACK_SIZE);
    linkedStack(const linkedStack<t> &);
    const linkedStack<t> &operator=(const linkedStack<t> &);
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const t &);
    t top() const;
    t pop();
    ~linkedStack();
    const static int DEFAULT_STACK_SIZE = -1;

private:
    void copyStack(const linkedStack<t> &);
    node<t> *stackTop;
    int maxStackSize;
    int count;
};

#endif

template <class t>
inline linkedStack<t>::linkedStack(int max)
{
    maxStackSize = max;
    stackTop = nullptr;
    count = 0;
}

template <class t>
inline linkedStack<t>::linkedStack(const linkedStack<t> &othStack)
{
    stackTop = nullptr;
    copyStack(othStack);
}

template <class t>
inline const linkedStack<t> &linkedStack<t>::operator=(const linkedStack<t> &othStack)
{
    if (this != &othStack)
    {
        copyStack(othStack);
    }
    return *this;
}

template <class t>
inline void linkedStack<t>::initializeStack()
{
    node<t> *temp;
    while (stackTop != nullptr)
    {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
    count = 0;
}

template <class t>
inline bool linkedStack<t>::isEmptyStack() const
{
    return stackTop == nullptr;
}

template <class t>
inline bool linkedStack<t>::isFullStack() const
{
    if (maxStackSize <= 0)
        return false;
    else
        return count == maxStackSize;
}

template <class t>
inline void linkedStack<t>::push(const t &newItem)
{
    if (isFullStack())
    {
        throw std::overflow_error("Stack Overflow. Cannot add to a full stack.");
    }
    node<t> *newNode;
    newNode = new node<t>;
    newNode->data = new t(newItem);
    newNode->link = stackTop;
    stackTop = newNode;
    count++;
}

template <class t>
inline t linkedStack<t>::top() const
{
    if (isEmptyStack())
        throw std::out_of_range("Empty Stack");

    return *(stackTop->data);
}

template <class t>
inline t linkedStack<t>::pop()
{
    node<t> *temp;
    if (isEmptyStack())
        throw std::underflow_error("Stack underflow. Cannot remove from an empty stack.");

    t newt(*(stackTop->data));
    temp = stackTop;
    stackTop = stackTop->link;
    delete temp;
    count--;
    return newt;
}

template <class t>
inline linkedStack<t>::~linkedStack()
{
    initializeStack();
}

template <class t>
inline void linkedStack<t>::copyStack(const linkedStack<t> &othStack)
{
    node<t> *newNode, *current, *last;
    if (!isEmptyStack())
    {
        initializeStack();
    }
    if (othStack.isEmptyStack())
    {
        this->stackTop = nullptr;
    }
    else
    {
        current = othStack.stackTop;
        this->stackTop = new node<t>;
        this->stackTop->data = new t(*(current->data));
        this->stackTop->link = nullptr;
        last = this->stackTop;
        current = current->link;
        while (current != nullptr)
        {
            newNode = new node<t>;
            newNode->data = new t(*(current->data));
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
        this->count = othStack.count;
        this->maxStackSize = othStack.maxStackSize;
    }
}
