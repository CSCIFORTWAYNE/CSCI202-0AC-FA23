#ifndef STACKADT_H
#define STACKADT_H

template <class type>
class stackADT
{
public:
    virtual void initializeStack() = 0;
    virtual bool isFullStack() const = 0;
    virtual bool isEmptyStack() const = 0;
    virtual void push(const type &) = 0;
    virtual type top() const = 0;
    virtual type pop() = 0;
};

#endif