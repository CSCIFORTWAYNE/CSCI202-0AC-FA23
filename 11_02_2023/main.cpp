#include <iostream>
#include <limits>
#include <cmath>
#include "arrayStack.h"
#include "linkedStack.h"
#include "donut.h"

void resetStream();
void codeGradeLoopFix(std::string errLocation);
long getBinaryNumber();
int main()
{
    /* long x;
    long copyx;
    arrayStack<int> binary;
    bool valid = false;
    int count = 0;
    while (!valid)
    {
        x = getBinaryNumber();
        copyx = x;
        valid = true;
        while (x > 0)
        {
            int digit = x % 10;
            if (digit != 0 && digit != 1)
            {
                std::cout << "Binary Numbers only have 1s and 0s." << std::endl;
                valid = false;
                break;
            }
            binary.push(digit);
            x = x / 10;
            count++;
        }
    }
    arrayStack<int> mathStack;
    while (!binary.isEmptyStack())
    {
        mathStack.push(binary.pop());
    }
    int answer = 0;
    count = 0;
    while (!mathStack.isEmptyStack())
    {
        answer += mathStack.pop() * pow(2, count++);
    }
    std::cout << copyx << " is " << answer << " in decimal." << std::endl;
 */
    try
    {
        donut d("map", "bacon", "none");
    }
    catch (stackTrace e)
    {
        std::cout << e.what() << std::endl;
        std::cout << e.printTrace() << std::endl;
    }

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}

void codeGradeLoopFix(std::string errLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" + errLocation << std::endl;
        throw std::invalid_argument(errLocation); // return or throw an exception here to force the program to end or return from the function.
    }
}

long getBinaryNumber()
{
    long x;
    std::cout << "Enter a number in binary: ";
    std::cin >> x;
    while (!std::cin || x < 0)
    {
        if (!std::cin)
            resetStream();
        std::cout << "Enter a number in binary: ";
        std::cin >> x;
    }
    return x;
}
