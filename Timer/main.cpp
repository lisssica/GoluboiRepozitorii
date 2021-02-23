#include <iostream>
#include <vector>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <vector>
#include <array>
#include "timer.h"

#define RANDOM_MIN_INT 1
#define RANDOM_MAX_INT 100
#define N 100 //number of random elements

const int getRandomInt(int min, int max)
{
    return rand() % max + min;
}

template <typename T>
void fillSetWithRandom(std::set<T> &s, const uint32_t size)
{
    for (auto i = 0; i <= size; i++)
    {
        s.insert(getRandomInt(RANDOM_MIN_INT, RANDOM_MAX_INT));
    }
}

template <typename T>
void fillVectorWithRandom(std::vector<T> &v, const uint32_t size)
{
    for (auto i = 0; i <= size; i++)
    {
        v.push_back(getRandomInt(RANDOM_MIN_INT, RANDOM_MAX_INT));
    }
}

template <typename T, int S_T>
void fillArrayWithRandom(std::array<T, S_T> &a, const uint32_t size)
{
    for (auto i = 0; i <= size; i++)
    {
        a[i] = (getRandomInt(RANDOM_MIN_INT, RANDOM_MAX_INT));
    }
}

int main()
{
    std::set<int> testSet;
    std::vector<int> testVector;
    std::array<int, N> testArray;

    srand(0); // seeding before fill
    fillSetWithRandom(testSet, N);

    srand(0);
    fillVectorWithRandom(testVector, N);
    std::sort(testVector.begin(), testVector.end());

    srand(0);
    fillArrayWithRandom<int, N>(testArray, N);
    std::sort(testArray.begin(), testArray.end());

    return 0;
}
