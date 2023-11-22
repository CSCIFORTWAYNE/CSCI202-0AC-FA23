#ifndef AVLtREE_H
#define AVLtREE_H

#include "binarySearchTree.h"
#include <sstream>

template <class t>
class AVLTree : public binarySearchTree<t>
{
public:
    void insert(const t &insertItem);
    void deleteNode(const t &deleteItem); // complete for bonus points (5pts)
    AVLTree(int (*comp)(const t &, const t &));

private:
    void rotateToLeft(binaryNode<t> *&root);
    void rotateToRight(binaryNode<t> *&root);
    void balanceFromLeft(binaryNode<t> *&root);
    void balanceFromRight(binaryNode<t> *&root);
    void insertIntoAVL(binaryNode<t> *&root, binaryNode<t> *newNode, bool &isTaller);
};

template <class t>
inline void AVLTree<t>::insert(const t &insertItem)
{
    bool isTaller = false;
    binaryNode<t> *newNode;
    newNode = new binaryNode<t>;
    newNode->data = new t(insertItem);
    newNode->bfactor = 0;
    newNode->height = 1;
    newNode->left = nullptr;
    newNode->right = nullptr;
    insertIntoAVL(this->getRoot(), newNode, isTaller);
}

template <class t>
inline AVLTree<t>::AVLTree(int (*comp)(const t &, const t &)) : binarySearchTree<t>(comp)
{
}

template <class t>
inline void AVLTree<t>::rotateToLeft(binaryNode<t> *&root)
{
    binaryNode<t> *p;
    if (root == nullptr)
    {
        throw std::out_of_range("Cannot rotate empty node.");
    }
    else if (root->right == nullptr)
    {
        throw std::out_of_range("Cannot rotate empty node.");
    }
    else
    {
        p = root->right;
        root->right = p->left;
        p->left = root;
        root = p;
    }
}

template <class t>
inline void AVLTree<t>::rotateToRight(binaryNode<t> *&root)
{
    binaryNode<t> *p;
    if (root == nullptr)
    {
        throw std::out_of_range("Cannot rotate empty node.");
    }
    else if (root->left == nullptr)
    {
        throw std::out_of_range("Cannot rotate empty node.");
    }
    else
    {
        p = root->left;
        root->left = p->right;
        p->right = root;
        root = p;
    }
}

template <class t>
inline void AVLTree<t>::balanceFromLeft(binaryNode<t> *&root)
{
    binaryNode<t> *p;
    binaryNode<t> *w;
    p = root->left;
    switch (p->bfactor)
    {
    case -1: // left high
        root->bfactor = 1;
        p->bfactor = 0;
        rotateToRight(root);
        break;
    case 0: // even high
        throw std::runtime_error("Left subtree is balanced.");
    case 1: // right high
        w = p->right;
        switch (w->bfactor)
        {
        case -1:
            root->bfactor = 0;
            p->bfactor = 0;
            break;
        case 0:
            root->bfactor = 0;
            p->bfactor = 0;
        case 1:
            root->bfactor = 0;
            p->bfactor = -1;
        }
        w->bfactor = 0;
        rotateToLeft(p);
        root->left = p;
        rotateToRight(root);
    }
}

template <class t>
inline void AVLTree<t>::balanceFromRight(binaryNode<t> *&root)
{
    binaryNode<t> *p;
    binaryNode<t> *w;
    p = root->right;
    switch (p->bfactor)
    {
    case 1: // right high
        root->bfactor = 0;
        p->bfactor = 0;
        rotateToLeft(root);
        break;
    case 0: // even high
        throw std::runtime_error("Right subtree is balanced.");
    case -1: // left high
        w = p->left;
        switch (w->bfactor)
        {
        case -1:
            root->bfactor = 0;
            p->bfactor = 1;
            break;
        case 0:
            root->bfactor = 0;
            p->bfactor = 0;
        case 1:
            root->bfactor = -1;
            p->bfactor = 0;
        }
        w->bfactor = 0;
        rotateToRight(p);
        root->right = p;
        rotateToLeft(root);
    }
}

template <class t>
inline void AVLTree<t>::insertIntoAVL(binaryNode<t> *&root, binaryNode<t> *newNode, bool &isTaller)
{
    if (root == nullptr)
    {
        root = newNode;
        isTaller = true;
    }
    else if (*(root->data) == *(newNode->data))
    {
        throw std::invalid_argument("No duplicates allowed.");
    }
    else if (*(root->data) > *(newNode->data))
    {
        insertIntoAVL(root->left, newNode, isTaller);
        // root->height = 1 + max(this->height(root->left), this->height(root->right));
        if (isTaller)
        {
            switch (root->bfactor)
            {
            case -1:
                balanceFromLeft(root);
                isTaller = false;
                break;
            case 0:
                root->bfactor = -1;
                isTaller = true;
                break;
            case 1:
                root->bfactor = 0;
                isTaller = false;
            }
        }
    }
    else
    {
        insertIntoAVL(root->right, newNode, isTaller);
        // root->height = 1 + max(this->height(root->left), this->height(root->right));
        if (isTaller)
        {
            switch (root->bfactor)
            {
            case -1:
                root->bfactor = 0;
                isTaller = false;
                break;
            case 0:
                root->bfactor = 1;
                isTaller = true;
                break;
            case 1:
                balanceFromRight(root);
                isTaller = false;
            }
        }
    }
}

#endif
