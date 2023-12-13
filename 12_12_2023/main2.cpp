#include <iostream>
#include <regex>
#include <string>
#include <fstream>

int main()
{
    int count = 1;
    std::regex rex{"\\/\\/"};
    std::ifstream input("blockchain.cpp");
    while (!input.eof())
    {
        std::string line;
        getline(input, line);
        if (std::regex_search(line, rex))
        {
            std::cout << "Comment found on line " << count << std::endl;
        }
        count++;
    }

    return 0;
}