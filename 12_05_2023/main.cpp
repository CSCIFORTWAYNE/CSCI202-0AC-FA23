#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_set>
#include <string>
#include <cmath>
#include <vector>

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
    while (!nums.eof() && count < HT_SIZE / 2)
    {
        int randNum;
        nums >> randNum;
        int hashValue = hashFunc(randNum);
        if (ht[hashValue] == -1)
        {
            std::cout << randNum << " inserted at " << hashValue << std::endl;
            ht[hashValue] = randNum;
            count++;
        }
        else if (ht[hashValue] != randNum)
        {
            std::cout << randNum << " collided with " << ht[hashValue] << std::endl;
            collisions++;
            while (ht[++hashValue] != -1)
            {
                std::cout << randNum << " collided with " << ht[hashValue] << std::endl;
                collisions++;
            }

            std::cout << randNum << " inserted at " << hashValue << std::endl;
            ht[hashValue] = randNum;
            count++;
        }
    }
    std::cout << "There were " << collisions << " collisions." << std::endl;
    std::cout << "There were " << count << " items inserted." << std::endl;
    return 0;
}

int hashFunc(int key)
{
    /* long long int keySquared = pow(key, 2);
    int location = keySquared & 0x00ffff00 >> 8; */
    int location = key; // = key;
    /* std::vector<int> segments;
    int seg;
    while (key > 0)
    {
        seg = key % 10000;
        key = key / 10000;
        segments.push_back(seg);
    }
    for (int i = 0; i < segments.size(); i++)
    {
        location += segments[i];
    } */
    return location % HT_SIZE;
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
