#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <climits>
#include "orderedLinkedList.h"
#include "donut.h"

void resetStream();
template <class t>
t getNum(std::string, bool (*validFunc)(t, t, t), t = 0, t = 0);
template <class t>
bool numInRange(t, t, t);
template <class t>
bool numGT0(t, t = 0, t = 0);
bool validString(std::string, std::string, std::string);
int compareDonuts(donut, donut);
int factorial(int);
bool isEven(int);
bool isOdd(int);
long fibNum(long f[], long n);

int main()
{
    long fibNum1, fibNum2;
    long nthFibonacci;
    fibNum1 = getNum("Enter the first Fibonacci number: ", numGT0, 0l);
    fibNum2 = getNum("Enter the second Fibonacci number: ", numInRange, fibNum1, LONG_MAX);
    nthFibonacci = getNum("Enter the position of the desired Fibonacci number: ", numGT0, 0);
    long *fibseq = new long[nthFibonacci];
    for (int i = 0; i < nthFibonacci; i++)
    {
        fibseq[i] = -1;
    }
    fibseq[0] = fibNum1;
    fibseq[1] = fibNum2;
    std::cout << "The " << nthFibonacci << "th Fibonacci number is "
              << fibNum(fibseq, nthFibonacci) << std::endl;
    /*  int x;
     double y;
     long z;
     long long r;
     std::string s;
     std::string check1 = "Hello";
     std::string check2 = "Goodbye";
     x = getNum("Enter a number between 1 and 10: ", numInRange, 0, 11);
     y = getNum("Enter the bill amount: ", numGT0, 0.0);
     z = getNum("Enter a big number: ", numGT0, 0L);
     r = getNum("Enter a very big number: ", numInRange, -50ll, 70893838373ll);
     s = getNum("Enter a word: ", validString, check1, check2);

     std::cout << "size of a long " << sizeof(long) << std::endl;
     std::cout << "size of a long long " << sizeof(long long) << std::endl;

     orderedLinkedList<donut> donuts(compareDonuts);
     donuts.insert(donut(CHOCOLATEICING, CHOCOLATESPR, CHOCOLATEDRIZZLE));
     donuts.insert(donut());
     donuts.insert(donut(VANILLA, FRUITYPEBBLES, RASPBERRY));
     donuts.insert(donut(CARAMELICING, CANDYBAR, NODRIZZLE));
     donuts.print(std::cout);
     factorial(5);
     isEven(99999); */

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}

template <class t>
t getNum(std::string prompt, bool (*validFunc)(t, t, t), t low, t high)
{
    t input;
    std::cout << prompt;
    std::cin >> input;
    if (std::cin && validFunc(input, low, high))
    {
        return input;
    }
    if (!std::cin)
        resetStream();
    else
        std::cout << "You entered an invalid value" << std::endl;

    return getNum(prompt, validFunc, low, high);
}

template <class t>
bool numInRange(t num, t low, t high)
{
    return num > low && num < high;
}

template <class t>
bool numGT0(t num, t, t)
{
    return num > 0;
}

bool validString(std::string i, std::string check1, std::string check2)
{
    std::transform(i.begin(), i.end(), i.begin(), ::tolower);
    std::transform(check1.begin(), check1.end(), check1.begin(), ::tolower);
    std::transform(check2.begin(), check2.end(), check2.begin(), ::tolower);

    return i == check1 || i == check2;
}

int compareDonuts(donut d1, donut d2)
{
    if (d1.getIcing() > d2.getIcing())
        return 1;
    if (d1.getIcing() == d2.getIcing())
        return 0;
    if (d1.getIcing() < d2.getIcing())
        return -1;
    return 0;
}

int factorial(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

bool isEven(int x)
{
    if (x == 2)
        return true;
    if (x == 1)
        return false;
    if (x < 0)
        x = abs(x);
    return isOdd(x - 1);
}

bool isOdd(int x)
{
    if (x == 1)
        return true;
    if (x == 2)
        return false;
    if (x < 0)
        x = abs(x);
    return isEven(x - 1);
}

long fibNum(long f[], long n)
{
    if (f[n - 1] != -1)
        return f[n - 1];
    f[n - 1] = fibNum(f, n - 1) + fibNum(f, n - 2);
    return f[n - 1];
}

int fibNum(int a, int b, int n)
{
    if (n < 0)
        n = abs(n);
    if (n == 0)
        return 0;
    else if (n == 1)
        return a;
    else if (n == 2)
        return b;
    else
        return fibNum(a, b, n - 1) + fibNum(a, b, n - 2);
}
