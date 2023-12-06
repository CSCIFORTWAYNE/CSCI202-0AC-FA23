#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_set>
#include <string>
#include <cmath>

const int HT_SIZE = 2000000;

int hashFunc(int key);
void setup();
int main()
{
    int ht[HT_SIZE];
    int collisions = 0;
    int count = 0;

    for (int i = 0; i < HT_SIZE; i++)
    {
        ht[i] = -1;
    }
    std::ifstream nums("exp.txt");
    while (!nums.eof() && count < HT_SIZE)
    {
        int randNum;
        nums >> randNum;
        if (ht[hashFunc(randNum)] == -1)
        {
            std::cout << randNum << " inserted at " << hashFunc(randNum) << std::endl;
            ht[hashFunc(randNum)] = randNum;
            count++;
        }
        else if (ht[hashFunc(randNum)] != randNum)
        {
            std::cout << randNum << " collided with " << ht[hashFunc(randNum)] << std::endl;
            collisions++;
        }
    }
    std::cout << "There were " << collisions << " collisions." << std::endl;
    std::cout << "There were " << count << " items inserted." << std::endl;
    return 0;
}

int hashFunc(int key)
{
    long long int keySquared = pow(key, 2);

    if (keySquared < 1000000000000000)
    {
        keySquared = keySquared / 10000;
        key = keySquared % HT_SIZE;
    }
    else
    {
        keySquared = keySquared / 10000;
        key = keySquared % HT_SIZE;
    }

    return key;
}

void setup()
{
    std::ofstream out("exp.txt");
    std::unordered_set<int> randomData;
    while (randomData.size() < 1000000)
    {
        randomData.insert(rand());
    }
    for (int i : randomData)
    {
        out << i << std::endl;
    }
    out.close();
}
