#ifndef LINKED_H
#define LINKED_H

#include <iostream>
#include <stdexcept>
#include "node.h"

template <class type>
class linkedListType
{
public:
    linkedListType();
    linkedListType(const linkedListType<type> &otherList);
    const linkedListType<type> &operator=(const linkedListType<type> &);
    ~linkedListType();
    void initializeList();
    bool isEmptyList() const;
    int length() const;
    void destroyList();
    type *front() const;
    type *back() const;
    virtual void insert(const type &newInfo) = 0;
    virtual void deleteNode(const type &deleteItem) = 0;
    virtual bool search(const type &searchItem) const = 0;

protected:
    node<type> *head;
    node<type> *tail;
    int count;

private:
    void copyList(const linkedListType<type> &otherList);
};

#endif