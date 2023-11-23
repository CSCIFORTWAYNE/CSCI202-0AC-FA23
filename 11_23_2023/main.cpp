#include "map.h"
#include "bimap.h"
#include <iostream>
#include <fstream>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <algorithm>

enum suitType
{
    DEFAULT,
    HEART,
    DIAMOND,
    SPADE,
    CLUB
};

enum TOPPING
{
    PEP,
    SUSGE,
    HAMB,
    SPIN,
    REON,
    GRPEP,
    BNNPEP,
    ANCH,
    TOM,
    OLI,
    PNPL,
    BCN,
    CHKN,
    CHOC
};

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    map<int, std::string> hobbits;
    std::ifstream name("names.txt");
    for (int i = 0; !name.eof(); i++)
    {
        std::string in;
        std::getline(name >> std::ws, in);
        hobbits.insert(i, in);
    }

    std::cout << hobbits[6] << std::endl;
    hobbits[0] = "Tasha Oakbottom";
    std::cout << hobbits[0] << std::endl;
    hobbits[15] = "Brianna Button";
    std::cout << hobbits[15] << std::endl;

    bimap<suitType, std::string> suits;
    suits.insert(HEART, "♥");
    suits.insert(DIAMOND, "♦");
    std::cout << suits.at(DIAMOND) << suits[DIAMOND] << std::endl;
    std::cout << suits["♦"] << std::endl;
    suits.insert(SPADE, "♠");
    suits.insert(CLUB, "♣");
    suits.deleteKey(HEART);
    suits.changeKey("♠", HEART);

    bimap<TOPPING, std::string> toppings;
    try
    {
        toppings.insert(PEP, "pepperoni");
        toppings.insert(SUSGE, "sausage");
        toppings.insert(HAMB, "hamburger");
        toppings.insert(SPIN, "spinach");
        toppings.insert(REON, "red onion");
        toppings.insert(GRPEP, "green pepper");
        toppings.insert(BNNPEP, "banana pepper");
        toppings.insert(ANCH, "anchovy");
        // toppings.insert(TOM, "");
        // toppings.insert(OLI, "");
        // toppings.insert(PNPL, "");
        // toppings.insert(BCN, "");
        // toppings.insert(CHKN, "");
        // toppings.insert(CHOC, "");
    }
    catch (std::invalid_argument e)
    {
        std::cout << e.what() << std::endl;
    }
    AVLTree<TOPPING> toppingSet;
    std::cout << "Enter a topping: ";
    std::string top;
    std::getline(std::cin >> std::ws, top);
    std::transform(top.begin(), top.end(), top.begin(), ::tolower);
    toppingSet.insert(toppings.at(top));

    return 0;
}