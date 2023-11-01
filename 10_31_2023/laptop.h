#ifndef LAPTOP_H
#define LAPTOP_H
#include <string>
#include <map>
#include <stdexcept>
#include <iostream>

enum OSType
{
    WIN,
    MAC,
    LIN,
    NONE
};
const std::map<OSType, std::string> OSStr = {{WIN, "Windows"}, {MAC, "Mac OS"}, {LIN, "Linux"}, {NONE, "No Operating System"}};
const std::map<std::string, OSType> StrOS = {{"WINDOWS", WIN}, {"MAC OS", MAC}, {"LINUX", LIN}, {"NO OPERATING SYSTEM", NONE}, {"NONE", NONE}};
class laptop
{
public:
    laptop(std::string manufacturer, std::string model, std::string serialNum, int year); //throws out_of_range
    void changeOS(OSType);
    bool operator==(const laptop&);
    bool operator!=(const laptop&);
    friend std::ostream& operator<<(std::ostream&, const laptop&);
private:
    std::string manufacturer;
    std::string model;
    std::string serialNum;
    OSType os;
    int year;
};

#endif