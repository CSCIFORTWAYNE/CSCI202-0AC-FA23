#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
#include "unorderedLinkedList.h"

template <class t>
linkedListIterator<t> seqSearch(unorderedLinkedList<t> &list, const t &item)
{
    bool found = false;
    linkedListIterator<t> itRet;
    for (linkedListIterator<t> it = list.begin(); it != list.end() && !found; ++it)
    {
        if (*it == item)
        {
            found = true;
            itRet = it;
        }
    }
    if (found)
    {
        return itRet;
    }
    else
    {
        return list.end();
    }
}
#endif