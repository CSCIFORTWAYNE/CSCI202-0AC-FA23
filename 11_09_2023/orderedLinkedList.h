#ifndef ORDERED_H
#define ORDERED_H
#include "linkedList.h"
#include <iostream>

template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
public:
    bool search(const Type &searchItem) const;
    void insert(const Type &newItem);
    void deleteNode(const Type &deleteItem);
    orderedLinkedList(int (*compareFunc)(Type, Type));
    orderedLinkedList(const orderedLinkedList<Type> &otherList);
    const orderedLinkedList<Type> &operator=(const orderedLinkedList<Type> &);

private:
    int (*compareFunc)(Type, Type);
    void copyList(const orderedLinkedList<Type> &otherList);
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type &searchItem) const
{
    bool found = false;
    node<Type> *current;
    current = this->head;
    while (current != nullptr && !found)
        if (compareFunc(*(current->data), searchItem) == 1 ||
            compareFunc(*(current->data), searchItem) == 0) //*(current->data) >= searchItem)
            found = true;
        else
            current = current->link;
    if (found)
        found = (compareFunc(*(current->data), searchItem) == 0); //*(current->data) == searchItem);
    return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type &newItem)
{
    node<Type> *current;
    node<Type> *trailCurrent = nullptr;
    node<Type> *newNode;

    bool found;
    newNode = new node<Type>;
    newNode->data = new Type(newItem);
    newNode->link = nullptr;

    if (this->head == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
        this->count++;
    }
    else
    {
        current = this->head;
        found = false;
        while (current != nullptr && !found)
        {
            if (compareFunc(*(current->data), newItem) == 1 ||
                compareFunc(*(current->data), newItem) == 0) //*(current->data) >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == this->head)
        {
            newNode->link = this->head;
            this->head = newNode;
            this->count++;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == nullptr)
                this->tail = newNode;
            this->count++;
        }
    }
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type &deleteItem)
{
    node<Type> *current;
    node<Type> *trailCurrent = nullptr;

    bool found;

    if (this->head == nullptr)
        std::cout << "Cannot delete from an empty list." << std::endl;
    else
    {
        current = this->head;
        found = false;
        while (current != nullptr && !found)
        {
            if (compareFunc(*(current->data), deleteItem) == 1 ||
                compareFunc(*(current->data), deleteItem) == 0) //*(current->data) >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == nullptr)
            std::cout << "The item to be deleted is not in the list." << std::endl;
        else if (compareFunc(*(current->data), deleteItem) == 0) //*(current->data) == deleteItem)
        {
            if (this->head == current)
            {
                this->head = this->head->link;
                if (this->head == nullptr)
                    this->tail = nullptr;
                delete current;
            }
            else
            {
                trailCurrent->link = current->link;
                if (current == this->tail)
                    this->tail = trailCurrent;
                delete current;
            }
            this->count--;
        }
        else
            std::cout << "The item to be deleted is not in the list." << std::endl;
    }
}

template <class Type>
inline orderedLinkedList<Type>::orderedLinkedList(int (*compareFunc)(Type, Type))
{
    this->compareFunc = compareFunc;
}

template <class Type>
inline void orderedLinkedList<Type>::copyList(const orderedLinkedList<Type> &otherList)
{
    this->compareFunc = otherList->compareFunc;
    linkedListType<Type>::copyList(otherList);
}

#endif