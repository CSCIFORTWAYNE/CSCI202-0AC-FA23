#ifndef BLOCK_H
#define BLOCK_H
#include <string>
#include <ctime>
#include <functional>
#include <openssl/sha.h>

class block
{
public:
    std::string getData();
    virtual size_t getHash();
    block(int, std::string, size_t = 0);
    // block(int, std::string, const unsigned char *);
    // const unsigned char *getHash();

protected:
    std::string data;
    time_t nonce;
    size_t prevHash;
    size_t currentHash;
    // unsigned char prevHash[SHA256_DIGEST_LENGTH];
    // unsigned char currentHash[SHA256_DIGEST_LENGTH];
    int blockNum;

private:
    void calculateHash();
};

/* class secureBlock : block
{
public:
    secureBlock(int, std::string, const unsigned char[]);
    const unsigned char* getHash(int);

private:
    unsigned char prevHash[SHA256_DIGEST_LENGTH];
    unsigned char currentHash[SHA256_DIGEST_LENGTH];
    void calculateHash();
}; */
#endif