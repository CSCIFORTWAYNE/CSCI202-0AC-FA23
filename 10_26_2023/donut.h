#ifndef DONUT_H
#define DONUT_H
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

enum icingType
{
    CHOCOLATEICING,
    CARAMELICING,
    MAPLE,
    VANILLA,
    GLAZE,
    SPECIALICE,
    NOICE
};
enum toppingType
{
    RAINBOWSPR,
    CHOCOLATESPR,
    PEANUTS,
    COCONUT,
    OREO,
    BACON,
    GRAHAM,
    FRUITYPEBBLES,
    REESESPIECES,
    MMS,
    CANDYBAR,
    CHOCOLATECHIPS,
    SEASALT,
    CINSUGAR,
    POWDSUGAR,
    NOTOP
};
enum drizzleType
{
    CARAMELDRIZZLE,
    CHOCOLATEDRIZZLE,
    PEANUTBUTTER,
    RASPBERRY,
    SPECIALDRIZZLE,
    NODRIZZLE
};

class donut
{
public:
    static std::map<toppingType, std::string> topToStr;
    static std::map<icingType, std::string> iceToStr;
    static std::map<drizzleType, std::string> drizzleToStr;
    static std::map<std::string, toppingType> strToTop;
    static std::map<std::string, icingType> strToIce;
    static std::map<std::string, drizzleType> strToDrizzle;
    donut(icingType = NOICE, toppingType = NOTOP, drizzleType = NODRIZZLE);
    donut(std::string, std::string, std::string);
    icingType getIcing();
    toppingType getTopping();
    drizzleType getDrizzle();
    std::string toString();

private:
    toppingType topping;
    icingType icing;
    drizzleType drizzle;
};

#endif