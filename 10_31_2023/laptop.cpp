#include "laptop.h"

laptop::laptop(std::string manufacturer, std::string model, std::string serialNum, int year)
{
    this->manufacturer = manufacturer;
    this->model = model;
    this->serialNum = serialNum;
    if (year < 1985)
        throw std::out_of_range("The year has to be after 1985");
    else
        this->year = year;
    this->os = NONE;
}

void laptop::changeOS(OSType os)
{
    this->os = os;
}

bool laptop::operator==(const laptop & ol)
{
    return this->serialNum == ol.serialNum;
}

bool laptop::operator!=(const laptop & ol)
{
    return this->serialNum != ol.serialNum;
}

std::ostream &operator<<(std::ostream & o, const laptop & l)
{
    o << "Manufacturer: " << l.manufacturer << std::endl;
    o << "Model: " << l.model << std::endl;
    o << "Operating System: " << OSStr.at(l.os) << std::endl;
    o << "Year: " << l.year << std::endl;
    o << "Serial Number: " << l.serialNum << std::endl;
    return o;
}
