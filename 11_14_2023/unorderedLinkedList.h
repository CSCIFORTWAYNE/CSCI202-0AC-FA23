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
    void mergeSort();

private:
    void recMergeSort(node<type> *&head);
    void divideList(node<type> *first1, node<type> *&first2);
    node<type> *mergeList(node<type> *first1, node<type> *first2);
};

template <class type>
inline void unorderedLinkedList<type>::insert(const type &newInfo)
{
    node<type> *newNode;
    newNode = new node<type>;
    newNode->data = new type(newInfo);
    newNode->link = nullptr;
    newNode->index = this->count;
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
    node<type> *current;
    node<type> *trailCurrent;
    bool found;
    if (this->isEmptyList())
        throw std::out_of_range("Cannot delete from empty list.");
    else
    {
        if (*(this->head->data) == deleteItem)
        {
            current = this->head;
            this->head = this->head->link;
            this->count--;
            if (this->head == nullptr)
                this->tail = nullptr;
            delete current;
        }
        else
        {
            found = false;
            trailCurrent = this->head;
            current = this->head->link;
            while (current != nullptr && !found)
            {
                if (*(current->data) != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }
            if (found)
            {
                trailCurrent->link = current->link;
                this->count--;
                if (this->tail == current)
                    this->tail = trailCurrent;
                delete current;
            }
            else
                throw std::out_of_range("Item not found in list. Cannot delete.");
        }
    }
}

template <class type>
inline bool unorderedLinkedList<type>::search(const type &searchItem) const
{
    node<type> *current;
    bool found = false;
    current = this->head;
    while (current != nullptr && !found)
    {
        if (*(current->data) == searchItem)
        {
            found = true;
        }
        else
        {
            current = current->link;
        }
    }
    return found;
}

template <class type>
void unorderedLinkedList<type>::mergeSort()
{
    recMergeSort(this->head);
    if (this->head == nullptr)
        this->tail = nullptr;
    else
    {
        this->tail = this->head;
        while (this->tail->link != nullptr)
            this->tail = this->tail->link;
    }
}

template <class type>
void unorderedLinkedList<type>::recMergeSort(node<type> *&head)
{
    node<type> *otherHead;
    if (head != nullptr)
        if (head->link != nullptr)
        {
            divideList(head, otherHead);
            recMergeSort(head);
            recMergeSort(otherHead);
            head = mergeList(head, otherHead);
        }
}

template <class type>
void unorderedLinkedList<type>::divideList(node<type> *first1, node<type> *&first2)
{
    node<type> *middle;
    node<type> *current;
    if (first1 == nullptr || first1->link == nullptr)
    {
        first2 = nullptr;
    }
    else
    {
        middle = first1;
        current = first1->link;
        if (current != nullptr)
            current = current->link;
        while (current != nullptr)
        {
            middle = middle->link;
            current = current->link;
            if (current != nullptr)
                current = current->link;
        }
        first2 = middle->link;
        middle->link = nullptr;
    }
}
template <class type>
node<type> *unorderedLinkedList<type>::mergeList(node<type> *first1, node<type> *first2)
{
    node<type> *lastSmall;
    node<type> *newHead;
    if (first1 == nullptr)
        return first2;
    if (first2 == nullptr)
        reutrn first1;
    else
    {
        if (*(first1->data) < *(first2->data))
        {
            newHead = first1;
            first1 = first1->link;
            lastSmall = newHead;
        }
        else
        {
            newHead = first2;
            first2 = first2->link;
            lastSmall = newHead;
        }
        while (first1 != nullptr && first2 != nullptr)
        {
            if (*(first1->data) < *(first2->data))
            {
                lastSmall->link = first1;
                lastSmall = lastSmall->link;
                first1 = first1->link;
            }
            else
            {
                lastSmall->link = first2;
                lastSmall = lastSmall->link;
                first2 = first2->link;
            }
        }
        if (first1 == nullptr)
        {
            lastSmall->link = first2;
        }
        else
        {
            lastSmall->link = first1;
        }
        return newHead;
    }
}
#endif