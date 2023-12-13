#include "blockchain.hpp"

blockChain::blockChain() // int // int  // int
{
    numBlocks = 0;
    // unsigned char hash[SHA256_DIGEST_LENGTH] = {0};
    block genesis(numBlocks++, "Genesis Block", 0);
    chain.enqueue(genesis);
}

void blockChain::insert(std::string message) //
{
    block newBlock(numBlocks++, message, chain.back().getHash());
    chain.enqueue(newBlock); //
}
