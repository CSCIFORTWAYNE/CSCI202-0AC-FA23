#include "graph.h"

bool graphType::isEmpty() const
{
    return gSize == 0;
}

void graphType::createGraph(std::string filename)
{
    std::ifstream fin(filename);
    int index;
    int vertex;
    int adjcentVertex;
    if (gSize != 0)
    {
        clearGraph();
    }
    if (!fin.is_open())
    {
        throw std::runtime_error("Cannot open input file.");
    }
    fin >> gSize;
    if (gSize > maxSize)
    {
        delete[] graph;
        maxSize = gSize;
        graph = new unorderedLinkedList<int>[maxSize];
    }
    for (index = 0; index < gSize; index++)
    {
        fin >> vertex;
        fin >> adjcentVertex;
        while (adjcentVertex != -999)
        {
            graph[vertex].insert(adjcentVertex);
            fin >> adjcentVertex;
        }
    }
    fin.close();
}

void graphType::clearGraph()
{
    for (int i = 0; i < gSize; i++)
    {
        graph[i].destroyList();
    }
    gSize = 0;
}

std::string graphType::printGraph() const
{
    std::ostringstream out;
    for (int i = 0; i < gSize; i++)
    {
        out << i << " ";
        graph[i].print(out, " ");
        out << std::endl;
    }
    out << std::endl;
    return out.str();
}

graphType::graphType(int size)
{
    maxSize = size;
    gSize = 0;
    graph = new unorderedLinkedList<int>[maxSize];
}

graphType::~graphType()
{
    clearGraph();
    delete[] graph;
}
