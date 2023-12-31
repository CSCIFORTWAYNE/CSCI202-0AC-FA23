#include "graph.h"
#include <iostream>
#include <fstream>

int main()
{
    graphType g;
    g.createGraph("graph3.txt");
    std::string output = g.printGraph();
    std::ofstream fout("g.txt");
    fout << output;
    std::cout << output;
    graphType h;
    h = g;
    std::cout << h.printGraph();
    std::cout << g.depthFirstTraversal() << std::endl;
    std::cout << g.breadthFirstTraversal() << std::endl;
    h.addEdge(3, 5);
    std::cout << h.printGraph();
    std::cout << g.printGraph();
    return 0;
}