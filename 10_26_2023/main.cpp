#include "donut.h"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

std::string getIcing();
std::string getTopping(std::string);
std::string getDrizzle();
void resetStream();

int main()
{
    donut **d;
    std::string ice;
    std::string top;
    std::string driz;
    int numDonuts = 0;
    d = new donut *[numDonuts];
    int num = 0;
    while (true)
    {
        ice = getIcing();
        top = getTopping(ice);
        driz = getDrizzle();
        std::cout << "How many donuts would you like with that icing/topping/drizzle combination? ";
        std::cin >> num;
        while (!std::cin || num < 0)
        {
            if (!std::cin)
            {
                resetStream();
            }
            else
            {
                std::cout << "You need to enter a positive number." << std::endl;
            }

            std::cin >> num;
        }
        donut **dCpy;
        dCpy = new donut *[numDonuts];
        for (int i = 0; i < numDonuts; i++)
        {
            dCpy[i] = new donut(*d[i]);
            delete d[i];
        }
        numDonuts += num;
        delete[] d;
        d = new donut *[numDonuts];
        for (int i = 0; i < numDonuts - num; i++)
        {
            d[i] = new donut(*dCpy[i]);
            delete dCpy[i];
        }
        delete[] dCpy;
        for (int i = numDonuts - num; i < numDonuts; i++)
        {
            d[i] = new donut(ice, top, driz);
        }
        char again = 'Y';
        std::cout << "Would you like to order more donuts? ";
        std::cin >> again;
        again = toupper(again);
        if (again == 'N')
            break;
    }

    for (int i = 0; i < numDonuts; i++)
    {
        std::cout << d[i]->toString() << std::endl;
    }
    for (int i = 0; i < numDonuts; i++)
    {
        delete d[i];
    }
    delete[] d;
    return 0;
}

std::string getIcing()
{
    std::string ice;
    std::cout << "Choose your icing from the choices below: " << std::endl;
    std::cout << "Chocolate" << std::endl;
    std::cout << "Caramel" << std::endl;
    std::cout << "Maple" << std::endl;
    std::cout << "Vanilla" << std::endl;
    std::cout << "Glaze" << std::endl;
    std::cout << "Special" << std::endl;
    std::cout << "None" << std::endl;
    std::getline(std::cin >> std::ws, ice);
    return ice;
}

std::string getTopping(std::string ice)
{
    std::string top;
    std::cout << "Choose your topping from the choices below:" << std::endl;
    std::string iceCpy = ice;
    std::transform(iceCpy.begin(), iceCpy.end(), iceCpy.begin(), ::tolower);
    if (iceCpy == "none")
    {
        std::cout << "Cinnamon Sugar" << std::endl;
        std::cout << "Powdered Sugar" << std::endl;
    }
    else
    {
        std::cout << "Rainbow Sprinkles" << std::endl;
        std::cout << "Chocolate Sprinkles" << std::endl;
        std::cout << "Peanuts" << std::endl;
        std::cout << "Coconut" << std::endl;
        std::cout << "Oreo" << std::endl;
        std::cout << "Bacon" << std::endl;
        std::cout << "Graham Cracker" << std::endl;
        std::cout << "Fruity Pebbles" << std::endl;
        std::cout << "Reese's Pieces" << std::endl;
        std::cout << "M&Ms" << std::endl;
        std::cout << "Candy Bar" << std::endl;
        std::cout << "Chocolate Chips" << std::endl;
        std::cout << "Sea Salt" << std::endl;
        std::cout << "Cinnamon Sugar" << std::endl;
        std::cout << "Powdered Sugar" << std::endl;
        std::cout << "None" << std::endl;
    }
    std::getline(std::cin >> std::ws, top);

    return top;
}

std::string getDrizzle()
{
    std::string driz;
    std::cout << "Choose your drizzle from the options below:" << std::endl;
    std::cout << "Caramel" << std::endl;
    std::cout << "Chocolate" << std::endl;
    std::cout << "Peanut Butter" << std::endl;
    std::cout << "Raspberry" << std::endl;
    std::cout << "Special" << std::endl;
    std::cout << "None" << std::endl;
    std::cin >> std::ws;
    std::getline(std::cin >> std::ws, driz);
    return driz;
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
