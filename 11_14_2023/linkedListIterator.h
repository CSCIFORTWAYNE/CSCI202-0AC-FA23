#ifndef LINKEDI_H
#define LINKEDI_H
#include "node.h"

template <class type>
class linkedListIterator
{
public:
    linkedListIterator();
    linkedListIterator(node<type> *);
    type &operator*();
    linkedListIterator<type> operator++();
    bool operator==(const linkedListIterator<type> &) const;
    bool operator!=(const linkedListIterator<type> &) const;
    int index();

private:
    node<type> *current;
};
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;
}

template <class type>
inline linkedListIterator<type>::linkedListIterator(node<type> *ptr)
{

    current = ptr;
}

template <class type>
inline type &linkedListIterator<type>::operator*()
{
    return *(current->data);
}

template <class type>
inline linkedListIterator<type> linkedListIterator<type>::operator++()
{
    current = current->link;
    return *this;
}

template <class type>
inline bool linkedListIterator<type>::operator==(const linkedListIterator<type> &right) const
{
    return (current == right.current);
}

template <class type>
inline bool linkedListIterator<type>::operator!=(const linkedListIterator<type> &right) const
{
    return (current != right.current);
}

template <class type>
inline int linkedListIterator<type>::index()
{

    return this->current->index;
}
#endif