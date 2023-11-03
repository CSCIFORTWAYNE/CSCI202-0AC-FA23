#ifndef ASTACK_H
#define ASTACK_H
#include "stackADT.h"
#include <stdexcept>

template <class t>
class arrayStack : public stackADT<t>
{
public:
    arrayStack(int = DEFAULT_STACK_SIZE);
    arrayStack(const arrayStack<t> &);
    const arrayStack<t> &operator=(const arrayStack<t> &);
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const t &);
    t top() const;
    t pop();
    ~arrayStack();
    const static int DEFAULT_STACK_SIZE = 100;

private:
    int maxStackSize;
    int stackTop;
    t **list;
    void copyStack(const arrayStack<t> &);
};

template <class t>
inline arrayStack<t>::arrayStack(int max)
{
    if (max <= 0)
    {
        max = DEFAULT_STACK_SIZE;
    }
    maxStackSize = max;
    stackTop = 0;
    list = new t *[maxStackSize];
}
template <class t>
inline arrayStack<t>::arrayStack(const arrayStack<t> &othStack)
{
    stackTop = 0;
    copyStack(othStack);
}
template <class t>
inline const arrayStack<t> &arrayStack<t>::operator=(const arrayStack<t> &othStack)
{
    if (this != &othStack)
    {
        copyStack(othStack);
    }
    return *this;
}
template <class t>
inline void arrayStack<t>::initializeStack()
{
    if (!isEmptyStack())
    {
        for (int i = 0; i < stackTop; i++)
        {
            delete list[i];
        }
    }
    stackTop = 0;
}
template <class t>
inline bool arrayStack<t>::isEmptyStack() const
{
    return stackTop == 0;
}

template <class t>
inline bool arrayStack<t>::isFullStack() const
{
    return stackTop == maxStackSize;
}

template <class t>
inline void arrayStack<t>::push(const t &newItem)
{
    if (!isFullStack())
    {
        list[stackTop++] = new t(newItem);
    }
    else
    {
        throw std::overflow_error("Stack Overflow. Cannot add to a full stack.");
    }
}

template <class t>
inline t arrayStack<t>::top() const
{
    if (isEmptyStack())
    {
        throw std::out_of_range("Empty Stack");
    }
    return *(list[stackTop - 1]);
}

template <class t>
inline t arrayStack<t>::pop()
{
    if (isEmptyStack())
    {
        throw std::underflow_error("Stack underflow. Cannot remove from an empty stack.");
    }
    else
    {
        t newt(*(list[stackTop - 1]));
        delete list[--stackTop];
        return newt;
    }
}

template <class t>
inline arrayStack<t>::~arrayStack()
{
    initializeStack();
    delete[] list;
}

template <class t>
inline void arrayStack<t>::copyStack(const arrayStack<t> &othStack)
{
    if (!isEmptyStack())
    {
        initializeStack();
    }
    delete[] this->list;
    this->maxStackSize = othStack.maxStackSize;
    this->stackTop = othStack.stackTop;
    this->list = new t *[this->maxStackSize];
    for (int i = 0; i < this->stackTop; i++)
    {
        this->list[i] = new t(*(othStack.list[i]));
    }
}

#endif