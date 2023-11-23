#ifndef BIMAP_H
#define BIMAP_H
#include "pair.h"
#include "AVLTree.h"

template <class k, class v>
class bimap
{
public:
    void insert(const k &, const v &);
    v at(const k &);
    k at(const v &);
    v operator[](const k &);
    k operator[](const v &);
    void deleteKey(const k &);
    void deleteValue(const v &);
    void changeKey(const v &, const k &);
    void changeValue(const k &, const v &);

protected:
    AVLTree<pair<k, v>> forward;
    AVLTree<pair<v, k>> backward;
};

#endif

template <class k, class v>
inline void bimap<k, v>::insert(const k &key, const v &value)
{
    pair<k, v> p(key, value);
    pair<v, k> p2(value, key);
    forward.insert(p);
    try
    {
        backward.insert(p2);
    }
    catch (std::invalid_argument e)
    {
        forward.deleteNode(p);
        throw e;
    }
}

template <class k, class v>
inline v bimap<k, v>::at(const k &key)
{
    pair<k, v> p(key);
    try
    {
        p = forward.find(p);
    }
    catch (std::out_of_range e)
    {
        throw std::out_of_range("The item is not in the map.");
    }
    return p.getValue();
}

template <class k, class v>
inline k bimap<k, v>::at(const v &value)
{
    pair<v, k> p(value);
    try
    {
        p = backward.find(p);
    }
    catch (std::out_of_range e)
    {
        throw std::out_of_range("The item is not in the map.");
    }
    return p.getValue();
}

template <class k, class v>
inline v bimap<k, v>::operator[](const k &key)
{
    pair<k, v> p(key);
    try
    {
        p = forward.find(p);
    }
    catch (std::out_of_range e)
    {
        throw std::out_of_range("The item is not in the map.");
    }
    return p.getValue();
}

template <class k, class v>
inline k bimap<k, v>::operator[](const v &value)
{
    pair<v, k> p(value);
    try
    {
        p = backward.find(p);
    }
    catch (std::out_of_range e)
    {
        throw std::out_of_range("The item is not in the map.");
    }
    return p.getValue();
}

template <class k, class v>
inline void bimap<k, v>::deleteKey(const k &key)
{
    pair<k, v> p(key);
    p = forward.find(p);
    forward.deleteNode(p);
    pair<v, k> p2(p.getValue(), p.getKey());
    backward.deleteNode(p2);
}

template <class k, class v>
inline void bimap<k, v>::deleteValue(const v &value)
{
    pair<v, k> p(value);
    p = backward.find(p);
    backward.deleteNode(p);
    pair<k, v> p2(p.getValue(), p.getKey());
    forward.deleteNode(p2);
}

template <class k, class v>
inline void bimap<k, v>::changeKey(const v &value, const k &newKey)
{
    pair<v, k> p(value);
    pair<v, k> *foundNode;
    foundNode = &backward.find(p);
    pair<k, v> p2(foundNode->getValue(), foundNode->getKey());
    foundNode->setValue(newKey);
    forward.deleteNode(p2);
    forward.insert(pair<k, v>(foundNode->getValue(), foundNode->getKey()));
}

template <class k, class v>
inline void bimap<k, v>::changeValue(const k &key, const v &newValue)
{
    pair<k, v> p(key);
    pair<k, v> *foundNode;
    foundNode = &forward.find(p);
    pair<v, k> p2(foundNode->getValue(), foundNode->getKey());
    foundNode->setValue(newValue);
    backward.deleteNode(p2);
    backward.insert(pair<v, k>(foundNode->getValue(), foundNode->getKey()));
}
