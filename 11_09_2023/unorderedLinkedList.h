#ifndef UNORDERED_H
#define UNORDERED_H
#include "linkedList.h"

template <class type>
class unorderedLinkedList : public linkedListType<type>
{
public:
    void insert(const type &newInfo);
    void deleteNode(const type &deleteItem);
    bool search(const type &searchItem) const;
};

#endif

template <class type>
inline void unorderedLinkedList<type>::insert(const type &newInfo)
{
    node<type> *newNode;
    newNode = new node<type>;
    newNode->data = new type(newInfo);
    newNode->link = nullptr;
    if (this->isEmptyList())
    {
        this->head = newNode;
        this->tail = newNode;
        this->count++;
    }
    else
    {
        this->tail->link = newNode;
        this->tail = newNode;
        this->count++;
    }
}

template <class type>
inline void unorderedLinkedList<type>::deleteNode(const type &deleteItem)
{
}

template <class type>
inline bool unorderedLinkedList<type>::search(const type &searchItem) const
{
    return false;
}
