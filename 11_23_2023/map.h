#ifndef MAP_H
#define MAP_H
#include "pair.h"
#include "AVLTree.h"

template <class k, class v>
class map
{
public:
    void insert(const k &, const v &);
    v at(const k &) const;
    v &operator[](const k &);
    void deleteKey(const k &);

protected:
    AVLTree<pair<k, v>> tree;
};

#endif

template <class k, class v>
inline void map<k, v>::insert(const k &key, const v &value)
{
    pair<k, v> p(key, value);
    tree.insert(p);
}

template <class k, class v>
inline v map<k, v>::at(const k &key) const
{
    pair<k, v> p(key);
    try
    {
        p = tree.find(p);
    }
    catch (std::out_of_range e)
    {
        throw std::out_of_range("The item is not in the map.");
    }
    return p.getValue();
}

template <class k, class v>
inline v &map<k, v>::operator[](const k &key)
{
    pair<k, v> p(key);
    pair<k, v> *p2;
    try
    {
        p2 = &tree.find(p);
    }
    catch (std::out_of_range e)
    {
        v value;
        pair<k, v> p3(key, value);
        tree.insert(p3);
        p2 = &tree.find(p3);
    }
    return p2->getValue();
}

template <class k, class v>
inline void map<k, v>::deleteKey(const k &key)
{
    pair<v, k> p(key);
    tree.deleteNode(p);
}
