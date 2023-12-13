#include <iostream>
#include <regex>
#include <string>

int main()
{
    // date format year/month/day
    std::regex dateRegex{"(\\d{4})/(0?[1-9]|1[0-2])/([1-2][0-9]|3[0-1]|0?[1-9])\\b"};
    std::string str;
    std::cout << "Enter a date (year/month/day) (q=quit:) ";
    getline(std::cin >> std::ws, str);
    if (str == "q")
        return 0;
    std::smatch parts;
    if (std::regex_match(str, parts, dateRegex))
    {
        std::cout << "You entered a date: " << parts[0] << std::endl;
        std::cout << "In american format: " << parts[2] << "/" << parts[3] << "/" << parts[1] << std::endl;
    }
    else
    {
        std::cout << "You did not enter a date." << std::endl;
    }

    return 0;
}