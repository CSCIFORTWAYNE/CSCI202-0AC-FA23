#include "donut.h"

/* donut::donut(icingType i, toppingType topping, drizzleType d)
{
    icing = i;
    this->topping = topping;
    drizzle = d;
} */

donut::donut(std::string icing, std::string topping, std::string drizzle)
{

    setIcing(icing);
    setTopping(topping);
    setDrizzle(drizzle);
}

std::map<toppingType, std::string> donut::topToStr = {{RAINBOWSPR, "Rainbow"},
                                                      {CHOCOLATESPR, "Chocolate Sprinkles"},
                                                      {PEANUTS, "Peanuts"},
                                                      {COCONUT, "Coconut"},
                                                      {OREO, "Oreo"},
                                                      {BACON, "Bacon"},
                                                      {GRAHAM, "Graham"},
                                                      {FRUITYPEBBLES, "Fruity Pebbles"},
                                                      {REESESPIECES, "Reeses Pieces"},
                                                      {MMS, "M&Ms"},
                                                      {CANDYBAR, "Candy Bar"},
                                                      {CHOCOLATECHIPS, "Chocolate Chips"},
                                                      {SEASALT, "Sea Salt"},
                                                      {CINSUGAR, "Cinnamon Sugar"},
                                                      {POWDSUGAR, "Powdered Sugar"},
                                                      {NOTOP, "None"}};
std::map<icingType, std::string> donut::iceToStr = {{CHOCOLATEICING, "Chocolate"},
                                                    {CARAMELICING, "Caramel"},
                                                    {MAPLE, "Maple"},
                                                    {VANILLA, "Vanilla"},
                                                    {GLAZE, "Glaze"},
                                                    {SPECIALICE, "Special"},
                                                    {NOICE, "None"}};
std::map<drizzleType, std::string> donut::drizzleToStr = {{CARAMELDRIZZLE, "Caramel"},
                                                          {CHOCOLATEDRIZZLE, "Chocolate"},
                                                          {PEANUTBUTTER, "Peanut Butter"},
                                                          {RASPBERRY, "Raspberry"},
                                                          {SPECIALDRIZZLE, "Special"},
                                                          {NODRIZZLE, "None"}};
std::map<std::string, toppingType> donut::strToTop = {{"rainbow sprinkles", RAINBOWSPR}, {"chocolate sprinkles", CHOCOLATESPR}, {"peanuts", PEANUTS}, {"coconut", COCONUT}, {"oreo", OREO}, {"bacon", BACON}, {"graham cracker", GRAHAM}, {"fruity pebbles", FRUITYPEBBLES}, {"reese's pieces", REESESPIECES}, {"m&ms", MMS}, {"candy bar", CANDYBAR}, {"chocolate chips", CHOCOLATECHIPS}, {"sea salt", SEASALT}, {"cinnamon sugar", CINSUGAR}, {"powdered sugar", POWDSUGAR}, {"none", NOTOP}};
std::map<std::string, icingType> donut::strToIce = {{"chocolate", CHOCOLATEICING},
                                                    {"caramel", CARAMELICING},
                                                    {"maple", MAPLE},
                                                    {"vanilla", VANILLA},
                                                    {"glaze", GLAZE},
                                                    {"special", SPECIALICE},
                                                    {"none", NOICE}};

std::map<std::string, drizzleType> donut::strToDrizzle{{"caramel", CARAMELDRIZZLE},
                                                       {"chocolate", CHOCOLATEDRIZZLE},
                                                       {"peanut butter", PEANUTBUTTER},
                                                       {"raspberry", RASPBERRY},
                                                       {"special", SPECIALDRIZZLE},
                                                       {"none", NODRIZZLE}};
icingType donut::getIcing() const { return icing; }
toppingType donut::getTopping() const { return topping; }
drizzleType donut::getDrizzle() const { return drizzle; }

std::string donut::toString() const
{
    std::string out;
    out = "Icing: " + iceToStr.at(icing) + " Topping: " + topToStr.at(topping) + " Drizzle: " + drizzleToStr.at(drizzle);
    return out;
}

void donut::setIcing(std::string icing)
{
    std::string icingLower = icing;
    std::transform(icingLower.begin(), icingLower.end(), icingLower.begin(), ::tolower);
    if (strToIce.count(icingLower))
    {
        this->icing = strToIce.at(icingLower);
    }
    else
    {
        throw std::invalid_argument(icing + " is not a valid icing type!");
    }
}
void donut::setTopping(std::string topping)
{
    std::string toppingLower = topping;
    std::transform(toppingLower.begin(), toppingLower.end(), toppingLower.begin(), ::tolower);
    if (strToTop.count(toppingLower))
    {
        this->topping = strToTop.at(toppingLower);
    }
    else
    {
        throw std::invalid_argument(toppingLower + " is not a valid topping type!");
    }
}
void donut::setDrizzle(std::string drizzle)
{
    std::string drizzleLower = drizzle;
    std::transform(drizzleLower.begin(), drizzleLower.end(), drizzleLower.begin(), ::tolower);
    if (strToDrizzle.count(drizzleLower))
    {
        this->drizzle = strToDrizzle.at(drizzleLower);
    }
    else
    {
        throw std::invalid_argument(drizzleLower + " is not a valid drizzle type!");
    }
}

std::ostream &operator<<(std::ostream &out, const donut &d)
{
    out << d.toString();
    return out;
}
