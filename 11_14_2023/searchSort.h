#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
#include "unorderedLinkedList.h"
/**************Search Algorithms***********/
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

template <class elemType>
int binarySearch(const elemType list[], int length, const elemType &item, int &comp, int first, int last)
{
    if (last < first)
        return -1;
    int mid;
    // bool found = false;
    // comp = 0;
    mid = (first + last) / 2;
    if (list[mid] == item)
    {
        comp++;
        return mid;
    }
    else if (list[mid] > item)
    {
        comp++;
        return binarySearch(list, length, item, comp, first, mid - 1);
    }
    else if (list[mid] < item)
    {
        comp++;
        return binarySearch(list, length, item, comp, mid + 1, last);
    }
    return -1;
}

/***********************Sort Algorithms***********************/
template <class t>
void bubbleSort(t list[], int length)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration; index++)
        {
            if (list[index] > list[index + 1])
            {
                t temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
}

template <class t>
void bubbleSortLL(unorderedLinkedList<t> &list, int length)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration; index++)
        {
            if (*list[index] > *list[index + 1])
            {
                t temp = *list[index];
                *list[index] = *list[index + 1];
                *list[index + 1] = temp;
            }
        }
    }
}

// selection sort function 1
template <class t>
linkedListIterator<t> findSmallest(unorderedLinkedList<t> &list, linkedListIterator<t> &begin)
{
    t smallest = *begin;
    linkedListIterator<t> ret;
    for (linkedListIterator<t> it = begin; it != list.end(); ++it)
    {
        if (*it < smallest)
        {
            smallest = *it;
            ret = it;
        }
    }
    return ret;
}
// selection sort function 2
template <class t>
void swap(linkedListIterator<t> &first, linkedListIterator<t> &second)
{
    t temp = *first;
    *first = *second;
    *second = temp;
}

// selection sort main function
template <class t>
void selectionSort(unorderedLinkedList<t> &list)
{
    linkedListIterator<t> unsort = list.begin();
    for (unsort; unsort != list.end(); ++unsort)
    {
        linkedListIterator<t> smallest = findSmallest(list, unsort);
        swap(unsort, smallest);
    }
}

template <class t>
void insertionSort(t list[], int length)
{

    for (int firstOutOfOrder = 0; firstOutOfOrder < length; ++firstOutOfOrder)
    {
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            t temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;
            do
            {
                list[location] = list[location - 1];
                location--;
            } while (location > 0 && list[location - 1] > temp);
            list[location] = temp;
        }
    }
}

// merge sort function 1
template <class t>
void merge(t array[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    t *leftArray = new t[leftSize];
    t *rightArray = new t[rightSize];
    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        rightArray[i] = array[mid + 1 + i];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = left;
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            array[mergeIndex] = leftArray[leftIndex];
            leftIndex++;
        }
        else
        {
            array[mergeIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }
    while (leftIndex < leftSize)
    {
        array[mergeIndex++] = leftArray[leftIndex++];
    }
    while (rightIndex < rightSize)
    {
        array[mergeIndex++] = rightArray[rightIndex++];
    }

    delete[] leftArray;
    delete[] rightArray;
}

// mergeSort main function
template <class t>
void mergeSort(t array[], int begin, int end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

/* template <class t>
void divideList(linkedListIterator<t> &first1, linkedListIterator<t> *&first2)
{
    linkedListIterator<t> middle(first1);
    linkedListIterator<t> current(middle);
    ++current;
    linkedListIterator<t> temp(first1);
    linkedListIterator<t> nullItr;

    if (first1 == nullItr)
        first2 = nullItr;
    else if (++temp == nullItr)
        first2 = nullItr;
    else
    {
        if (current != nullItr)
            ++current;
        while(current != nullItr)
        {
            ++middle;
            ++current;
            if(current != nullItr)
            {
                ++current;
            }
        }
        temp = middle;
        first2 = ++temp;
    }
} */

#endif