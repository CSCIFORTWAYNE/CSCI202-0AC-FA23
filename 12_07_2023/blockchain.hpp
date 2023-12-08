#ifndef BLOCKC_H
#define BLOCKC_H
#include "block.hpp"
#include "linkedQueue.h"

class blockChain
{
public:
    blockChain();
    void insert(std::string);

private:
    linkedQueue<block> chain;
    int numBlocks;
};

#endif