#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "AVLTree.h"

int compareNumbers(const int &first, const int &second);

int main()
{
    AVLTree<int> tree(compareNumbers);
    for (int i = 0; i < 20; i++)
    {
        int x;
        x = rand() % 50 + 1;
        try
        {
            tree.insert(x);
        }
        catch (...)
        {
        }
        // std::cout << tree << std::endl;
        // std::cout << std::setw(50) << std::setfill('*') << "*" << std::endl;
    }
    return 0;
}

int compareNumbers(const int &first, const int &second)
{
    if (first < second)
        return -1;
    else if (first == second)
        return 0;
    else
        return 1;
}