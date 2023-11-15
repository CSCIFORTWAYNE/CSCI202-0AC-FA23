#ifndef LINKED_H
#define LINKED_H

#include <iostream>
#include <stdexcept>
#include "node.h"
#include "linkedListIterator.h"

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
    void print(std::ostream &, std::string = " ") const;
    void destroyList();
    type *front() const;
    type *back() const;
    virtual void insert(const type &newInfo) = 0;
    virtual void deleteNode(const type &deleteItem) = 0;
    virtual bool search(const type &searchItem) const = 0;
    linkedListIterator<type> begin();
    linkedListIterator<type> end();

protected:
    node<type> *head;
    node<type> *tail;
    int count;
    void copyList(const linkedListType<type> &otherList);
};

template <class type>
linkedListType<type>::linkedListType()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class type>
inline linkedListType<type>::linkedListType(const linkedListType<type> &otherList)
{
    count = 0;
    head = nullptr;
    tail = nullptr;
    copyList(otherList);
}

template <class type>
inline const linkedListType<type> &linkedListType<type>::operator=(const linkedListType<type> &otherList)
{
    if (this != &otherList) // no self copy
    {
        copyList(otherList);
    }
    return *this;
}

template <class type>
bool linkedListType<type>::isEmptyList() const
{
    return count == 0 || head == nullptr;
}

template <class type>
void linkedListType<type>::print(std::ostream &out, std::string sep) const
{
    if (!isEmptyList())
    {
        node<type> *current;
        current = head;
        while (current != nullptr)
        {
            out << *(current->data) << sep;
            current = current->link;
        }
    }
}

template <class type>
int linkedListType<type>::length() const
{
    return count;
}

template <class type>
void linkedListType<type>::destroyList()
{
    if (!isEmptyList())
    {
        node<type> *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->link;
            delete temp;
        }
        tail = nullptr;
        count = 0;
    }
}

template <class type>
void linkedListType<type>::initializeList()
{
    destroyList();
}

template <class type>
linkedListType<type>::~linkedListType()
{
    destroyList();
}

template <class t>
t *linkedListType<t>::front() const
{
    if (isEmptyList())
        throw std::out_of_range("Cannout get first item of an empty list");
    return head->data;
}

template <class t>
t *linkedListType<t>::back() const
{
    if (isEmptyList())
        throw std::out_of_range("Cannout get last item of an empty list");
    return tail->data;
}

template <class type>
inline linkedListIterator<type> linkedListType<type>::begin()
{
    linkedListIterator<type> temp(head);
    return temp;
}

template <class type>
inline linkedListIterator<type> linkedListType<type>::end()
{
    linkedListIterator<type> temp;
    return temp;
}

template <class type>
void linkedListType<type>::copyList(const linkedListType<type> &otherList)
{
    node<type> *newNode;
    node<type> *current;
    if (!isEmptyList())
    {
        destroyList();
    }
    if (otherList.isEmptyList())
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.head;
        count = otherList.count;
        this->head = new node<type>;
        this->head->data = new type(*(current->data));
        this->head->link = nullptr;
        this->tail = this->head;
        current = current->link;
        while (current != nullptr)
        {
            newNode = new node<type>;
            newNode->data = new type(*(current->data));
            newNode->link = nullptr;
            tail->link = newNode;
            current = current->link;
            tail = newNode;
        }
    }
}

#endif