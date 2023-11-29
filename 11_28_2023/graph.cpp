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

// note: if you use the original output with the python graph render, you will need to remove extra newlines from the end of the file.
// the digraph output for graphViz doesn't break with extra newlines.
std::string graphType::printGraph() const
{
    std::ostringstream out;
    out << "digraph {"; // comment this line and the nested for loop for the python output
    for (int i = 0; i < gSize; i++)
    {
        /* original print code works with the python program.
        out << i << " ";
        graph[i].print(out);
        out << std::endl; */
        for (linkedListIterator<int> graphIt = graph[i].begin(); graphIt != graph[i].end(); ++graphIt)
            out << i << "->" << *graphIt << ";" << std::endl;
    }
    out << std::endl;
    out << "}"; // comment this line for the python output.
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

const graphType &graphType::operator=(const graphType &othGraph)
{
    if (this != &othGraph)
    {
        copyGraph(othGraph);
    }
    return *this;
}

graphType::graphType(const graphType &othGraph)
{
    maxSize = 0;
    gSize = 0;
    graph = nullptr;
    copyGraph(othGraph);
}

std::string graphType::depthFirstTraversal()
{
    bool *visited;
    visited = new bool[gSize];
    std::string out = "";
    for (int i = 0; i < gSize; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < gSize; i++)
    {
        if (!visited[i])
            dft(i, visited, out);
    }
    delete[] visited;
    return out;
}

std::string graphType::dftAtVertex(int vertex)
{
    bool *visited;
    visited = new bool[gSize];
    std::string out = "";
    for (int i = 0; i < gSize; i++)
    {
        visited[i] = false;
    }
    dft(vertex, visited, out);
    delete[] visited;
    return out;
}

std::string graphType::breadthFirstTraversal()
{
    linkedQueue<int> queue;
    bool *visited;
    visited = new bool[gSize];
    std::string out = "";
    for (int i = 0; i < gSize; i++)
    {
        visited[i] = false;
    }
    linkedListIterator<int> graphIt;
    for (int i = 0; i < gSize; i++)
    {
        if (!visited[i])
        {
            queue.enqueue(i);
            visited[i] = true;
            out = out + " " + std::to_string(i) + " ";
            while (!queue.isEmptyQueue())
            {
                int u = queue.dequeue();
                for (graphIt = graph[u].begin(); graphIt != graph[u].end(); ++graphIt)
                {
                    int w = *graphIt;
                    if (!visited[w])
                    {
                        queue.enqueue(w);
                        visited[w] = true;
                        out = out + " " + std::to_string(w) + " ";
                    }
                }
            }
        }
    }
    delete[] visited;
    return out;
}

void graphType::copyGraph(const graphType &othGraph)
{
    if (!this->isEmpty())
    {
        this->clearGraph();
    }
    delete[] this->graph;
    this->maxSize = othGraph.maxSize;
    this->gSize = othGraph.gSize;
    this->graph = new unorderedLinkedList<int>[this->maxSize];
    for (int i = 0; i < this->gSize; i++)
    {
        this->graph[i] = othGraph.graph[i];
    }
}

void graphType::dft(int v, bool visited[], std::string &output)
{
    visited[v] = true;
    output = output + " " + std::to_string(v) + " ";
    linkedListIterator<int> graphIt;
    for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
    {
        int w = *graphIt;
        if (!visited[w])
            dft(w, visited, output);
    }
}
