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
    unorderedLinkedList<int> list;
    while (!in.eof())
    {
        int x;
        in >> x;
        list.insert(x);
    }
    int searchTerm = 308;
    linkedListIterator<int> it = seqSearch(list, searchTerm);
    if (it == nullptr)
    {
        std::cout << "The item was not found in the list" << std::endl;
    }
    else
    {
        std::cout << searchTerm << " is in the list at index " << it.index() << std::endl;
    }

    return 0;
}
