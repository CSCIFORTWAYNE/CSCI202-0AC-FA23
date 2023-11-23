#ifndef SEARCH_H
#define SEARCH_H
#include "binaryTree.h"
#include <stdexcept>

template <class T>
class binarySearchTree : public binaryTree<T>
{
public:
    bool search(const T &searchItem) const;
    void insert(const T &insertItem);
    void deleteNode(const T &deleteItem);
    std::string printItem(T &searchItem) const;

private:
    void deleteFromTree(binaryNode<T> *&p);
    bool search(const T &searchItem, binaryNode<T> *p) const;
    void insert(binaryNode<T> *&insertItem, binaryNode<T> *&p);
    std::ostringstream printItem(T &searchItem, binaryNode<T> *p) const;
};

#endif

template <class T>
bool binarySearchTree<T>::search(const T &searchItem) const
{
    return search(searchItem, this->root);
}

template <class T>
void binarySearchTree<T>::insert(const T &insertItem)
{
    binaryNode<T> *newNode;
    newNode = new binaryNode<T>;
    newNode->data = new T(insertItem);
    newNode->lTree = nullptr;
    newNode->rTree = nullptr;
    insert(newNode, this->root);
}

template <class T>
void binarySearchTree<T>::deleteNode(const T &deleteItem)
{
    binaryNode<T> *current;
    binaryNode<T> *trailCurrent;
    bool found = false;
    if (this->root == nullptr)
        throw std::invalid_argument("Cannot delete from an empty tree");
    else
        current = this->root;
    trailCurrent = this->root;
    while (current != nullptr && !found)
    {
        if (*current->data == deleteItem)
            found = true;
        else
        {
            trailCurrent = current;
            if (*current->data > deleteItem)
                current = current->lTree;
            else
                current = current->rTree;
        }
    }
    if (current == nullptr || !found)
        throw std::invalid_argument("The item to be deleted is not in the tree.");
    else if (found)
    {
        if (current == this->root)
            deleteFromTree(this->root);
        else if (*trailCurrent->data > deleteItem)
            deleteFromTree(trailCurrent->lTree);
        else
            deleteFromTree(trailCurrent->rTree);
    }
}

template <class T>
std::string binarySearchTree<T>::printItem(T &searchItem) const
{
    if (search(searchItem))
        return printItem(searchItem, this->root).str();

    return "The item does not exist in the tree.";
}

template <class T>
void binarySearchTree<T>::deleteFromTree(binaryNode<T> *&p)
{
    binaryNode<T> *current;
    binaryNode<T> *trailCurrent;
    binaryNode<T> *temp;
    if (p == nullptr)
        throw std::invalid_argument("The item to be deleted is not in the tree.");
    else if (p->lTree == nullptr && p->rTree == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if (p->lTree == nullptr)
    {
        temp = p;
        p = temp->rTree;
        delete temp;
    }
    else if (p->rTree == nullptr)
    {
        temp = p;
        p = temp->lTree;
        delete temp;
    }
    else
    {
        current = p->lTree;
        trailCurrent = nullptr;
        while (current->rTree != nullptr)
        {
            trailCurrent = current;
            current = current->rTree;
        }
        T *tempData;
        tempData = p->data;
        p->data = current->data;
        current->data = tempData;
        if (trailCurrent == nullptr)
            p->lTree = current->lTree;
        else
            trailCurrent->rTree = current->lTree;

        delete current;
    }
}

template <class T>
bool binarySearchTree<T>::search(const T &searchItem, binaryNode<T> *p) const
{
    if (p == nullptr)
        return false;
    else if (*p->data == searchItem)
        return true;
    else if (*p->data > searchItem)
        return search(searchItem, p->lTree);
    else
        return search(searchItem, p->rTree);
}

template <class T>
void binarySearchTree<T>::insert(binaryNode<T> *&insertItem, binaryNode<T> *&p)
{
    if (p == nullptr)
        p = insertItem;
    else if (*p->data == *insertItem->data)
        throw std::invalid_argument("The item to be inserted is already in the tree -- duplicates are not allowed.");
    else if (*p->data > *insertItem->data)
        insert(insertItem, p->lTree);
    else
        insert(insertItem, p->rTree);
}

template <class T>
std::ostringstream binarySearchTree<T>::printItem(T &searchItem, binaryNode<T> *p) const
{
    std::ostringstream out;
    if (p == nullptr)
    {
        out << "The item does not exist in the tree.";
    }
    else if (*p->data == searchItem)
        out << *p->data << std::endl;
    else if (*p->data > searchItem)
        return printItem(searchItem, p->lTree);
    else
        return printItem(searchItem, p->rTree);

    return out;
}
