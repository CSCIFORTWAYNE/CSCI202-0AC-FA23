#include "graph.h"
#include <iostream>
#include <fstream>

int main()
{
    graphType g;
    g.createGraph("graph1.txt");
    std::string output = g.printGraph();
    std::ofstream fout("g.txt");
    fout << output;
    std::cout << output;
    return 0;
}