#include <iostream>
#include <limits>
#include <algorithm>
#include "unorderedLinkedList.h"
#include "donut.h"

std::string getIcing();
std::string getTopping(std::string);
std::string getDrizzle();
void resetStream();
void codeGradeLoopFix(std::string errLocation);

int main()
{
    unorderedLinkedList<donut> donuts;
    std::string ice;
    std::string top;
    std::string driz;
    for (int i = 0; i < 3; i++)
    {
        ice = getIcing();
        top = getTopping(ice);
        driz = getDrizzle();
        donut d(ice, top, driz);
        donuts.insert(d);
    }
    donuts.print(std::cout, "\n");
    std::cout << std::endl;

    for (linkedListIterator<donut> it = donuts.begin(); it != donuts.end(); ++it)
    {
        std::cout << *it << std::endl;
        if ((*it).getIcing() == VANILLA)
        {
            std::cout << "Found the vanilla donut" << std::endl;
        }
    }

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
    std::transform(ice.begin(), ice.end(), ice.begin(), ::tolower);
    while (!donut::strToIce.count(ice))
    {
        codeGradeLoopFix("line 45");
        std::cout << "That is not a valid icing choice!" << std::endl;
        std::getline(std::cin >> std::ws, ice);
        std::transform(ice.begin(), ice.end(), ice.begin(), ::tolower);
    }
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