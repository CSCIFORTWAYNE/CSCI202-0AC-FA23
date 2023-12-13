#include <iostream>
#include <regex>
#include <string>
// add a loop to the main so that you can enter more than 1 date.
int main()
{
    // date format year/month/day
    // iso 8601 yyyy-mm-dd
    std::regex dateRegex{"(\\d{4})(/|-)(0?[1-9]|1[0-2])\\2([1-2][0-9]|3[0-1]|0?[1-9])\\b"};
    std::string str;
    std::cout << "Enter a date (year/month/day) (q=quit:) ";
    getline(std::cin >> std::ws, str);
    if (str == "q")
        return 0;
    std::smatch parts;
    if (std::regex_match(str, parts, dateRegex))
    {
        int year = std::stoi(parts[1]);
        int month = std::stoi(parts[3]);
        int day = std::stoi(parts[4]);
        bool leap = false;
        bool valid = true;
        if (month == 2)
        {
            if (day <= 28)
            {
                valid = true;
            }
            else if (year % 4 == 0)
            {
                // step 2
                if (year % 100 == 0)
                {
                    // step 3
                    if (year % 400 == 0)
                    {
                        leap = true;
                    }
                    else
                    {
                        leap = false;
                    }
                }
                else // step 4
                {
                    leap = true;
                }
                if (day == 29)
                {
                    valid = true;
                }
                else
                {
                    valid = false;
                }
            }
            else // step 5
            {
                leap = false;
            }
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        {
            valid = false;
        }
        if (valid)
        {
            std::cout << "You entered a date: " << parts[0] << std::endl;
            std::cout << "In american format: " << parts[3] << "/" << parts[4] << "/" << parts[1] << std::endl;
        }
        else
        {
            std::cout << "You did not enter a valid date" << std::endl;
        }
    }
    else
    {
        std::cout << "You did not enter a date." << std::endl;
    }

    return 0;
}