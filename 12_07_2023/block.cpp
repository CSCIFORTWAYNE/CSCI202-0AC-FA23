#include "block.hpp"

std::string block::getData()
{
    return data;
}

size_t block::getHash()
{
    calculateHash();
    return currentHash;
}

block::block(int blockNum, std::string data, size_t prevHash)
{
    this->blockNum = blockNum;
    this->nonce = time(NULL);
    this->data = data;
    this->prevHash = prevHash;
    calculateHash();
}

void block::calculateHash()
{
    std::hash<std::string> str_hash;
    std::string hashString = std::to_string(blockNum) + std::to_string(nonce) + data + std::to_string(prevHash);
    currentHash = str_hash(hashString);
    /*    std::string phash(prevHash, prevHash + sizeof(prevHash) / sizeof(prevHash[0]));
       std::string hashString = std::to_string(blockNum) + std::to_string(nonce) + data + phash;
       SHA256((unsigned char *)hashString.c_str(), hashString.length(), currentHash); */
}

/* block::block(int blockNum, std::string message, const unsigned char *prevHash)
{
    this->blockNum = blockNum;
    this->data = message;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        this->prevHash[i] = prevHash[i];
    }
} */

/* const unsigned char *block::getHash()
{
    calculateHash();
    return currentHash;
} */
