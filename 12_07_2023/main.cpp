#include <iostream>
#include <openssl/sha.h>
#include <string>
#include "blockchain.hpp"

int main()
{
    std::string message = "Space star ordering is based on the twin scientific principles of star-maths and wishy thinking.";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)message.c_str(), message.length(), hash);
    // std::cout << hash << std::endl;
    std::cout << std::hex;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        std::cout << static_cast<int>(hash[i]);
    std::cout << std::endl;

    std::string message2 = "Prepare to put mustard on those words, for you will soon be consuming them along with this slice of humble pie that comes direct from the oven of shame, set at gas mark 'egg on your face'.";
    unsigned char hash2[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)message2.c_str(), message2.length(), hash2);
    // std::cout << hash << std::endl;
    std::cout << std::hex;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        std::cout << static_cast<int>(hash2[i]);
    std::cout << std::endl;

    std::string message3 = "prepare to put mustard on those words, for you will soon be consuming them along with this slice of humble pie that comes direct from the oven of shame, set at gas mark 'egg on your face'.";
    unsigned char hash3[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)message3.c_str(), message3.length(), hash3);
    // std::cout << hash << std::endl;
    std::cout << std::hex;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        std::cout << static_cast<int>(hash3[i]);
    std::cout << std::endl;

    blockChain bc;
    bc.insert(message);
    bc.insert(message2);
    bc.insert(message3);

    return 0;
}