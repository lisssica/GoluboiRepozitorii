#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1, 2, 3};
    int arr[31];
    arr[0] = v.capacity();

    for (int i = 0; i < 30; i++)
    {
        v.push_back(i);
        arr[i + 1] = v.capacity();
    }

    //При добавлении элемента в вектор память резервируется только в том случае,
    //когда ее не хватает, и резервируется столько же сколько было элементов в вектое

    std::vector<int> v1 = {1, 2, 3};
    v1.reserve(15);
    int arr1[31];
    arr1[0] = v1.capacity();

    for (int i = 0; i < 30; i++)
    {
        v1.push_back(i);
        arr1[i + 1] = v1.capacity();
    }

    //Reserve - резеревирует память, поэтому при добавлении элемента, емкость не увеличивается
    //вплоть до того, как заканчивается резерв.память, потом как обычно

    std::vector<int> v2(1694967295);

    v2.push_back(0);
    // В предельном случае добавление элемента не происходит
    return 0;
}
