#include <iostream>
#include <regex>
#include <string>
#include <fstream>

int main()
{
    int count = 1;
    std::regex rex{"//[[:blank:]]*(.*)\\b"};
    std::regex intRegex{"\\bint\\b"};
    std::ifstream input("blockchain.cpp");
    while (!input.eof())
    {
        std::string line;
        getline(input, line);
        /* if (std::regex_search(line, rex))
        {
            std::cout << "Comment found on line " << count << std::endl;
        } */
        const std::sregex_iterator end;
        for (std::sregex_iterator iter{std::cbegin(line), std::cend(line), intRegex}; iter != end; ++iter)
        {
            std::cout << " Found Comment " << iter->str() << std::endl;
        }
        count++;
    }

    return 0;
}