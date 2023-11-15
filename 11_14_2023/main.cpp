#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "unorderedLinkedList.h"
#include "searchSort.h"

int main()
{
    srand(time(0));

    std::ifstream in("input.txt");
    // unorderedLinkedList<int> list;
    int list[1000000];
    int i = 0;
    while (!in.eof())
    {
        int x;
        in >> x;
        // list.insert(x);
        // i++;
        list[i++] = x;
    }
    /* int searchTerm = 308;
    linkedListIterator<int> it = seqSearch(list, searchTerm);
    if (it == nullptr)
    {
        std::cout << "The item was not found in the list" << std::endl;
    }
    else
    {
        std::cout << searchTerm << " is in the list at index " << it.index() << std::endl;
    } */
    /* selectionSort(list);
    std::cout << "Selection Sort Finished" << std::endl; */

    /* bubbleSortLL(list, 5);
    std::cout << "Bubble Sort Finished" << std::endl; */
    /*  insertionSort(list, 1000000);
     std::cout << "Insertion Sort Finished" << std::endl; */
    mergeSort(list, 0, 1000000);
    std::cout << "Merge Sort Finished" << std::endl;
    return 0;
}
