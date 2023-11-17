#include "binarySearchTree.h"
#include <iostream>

int compareNumbers(const int &first, const int &second);

int main()
{
    binarySearchTree<int> tree(compareNumbers);
    for (int i = 0; i < 10; i++)
    {
        int x = 0;
        std::cin >> x;
        try
        {

            tree.insert(x);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << tree.inorderTraversal() << std::endl;
    std::cout << tree.preorderTraversal() << std::endl;
    std::cout << tree.postOrderTraversal() << std::endl;

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
