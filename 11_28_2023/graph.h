#ifndef GRAPH_H
#define GRAPH_H
#include "unorderedLinkedList.h"
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

class graphType
{
public:
    bool isEmpty() const;
    void createGraph(std::string);
    void clearGraph();
    std::string printGraph() const;
    graphType(int size = 0);
    ~graphType();
    const graphType &operator=(const graphType &);
    graphType(const graphType &);

protected:
    int maxSize;
    int gSize;
    unorderedLinkedList<int> *graph;
};

#endif