#include <iostream>
#include <vector>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <vector>
#include <array>
#include "../Timer/timer.h"

#define RANDOM_MIN_INT 1
#define RANDOM_MAX_INT 100
#define N 100000000

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
void fillArrayWithRandom(std::array<T, S_T> *a, const uint32_t size)
{
    for (auto i = 0; i <= size; i++)
    {
        (*a)[i] = (getRandomInt(RANDOM_MIN_INT, RANDOM_MAX_INT));
    }
}

int main()
{
    //Timing Set
    Timer *timer = new Timer();
    srand(0); // seeding before fill
    std::set<int> testSet;
    fillSetWithRandom(testSet, N);

    //Timing Vector
    timer->Lap();
    srand(0);
    std::vector<int> testVector;
    fillVectorWithRandom(testVector, N);
    std::sort(testVector.begin(), testVector.end());

    //Timing Array
    timer->Lap();
    srand(0);
    std::array<int, N> *testArray = new std::array<int, N>;
    fillArrayWithRandom<int, N>(testArray, N);
    std::sort(testArray->begin(), testArray->end());

    delete timer;
    delete testArray;

    return 0;
}
