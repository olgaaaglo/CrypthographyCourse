#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    std::set<int> set1;
    for (int i = 1; i < 13; ++i)
    {
        set1.insert(i * i % 13);
    }

    for (auto i : set1)
    {
        cout << i << " ";
    }
    cout << endl;

    std::set<int> set2;
    for (int i = 1; i < 13; ++i)
    {
        int a = static_cast<int>(pow(i, (13 - 1) / 2)) % 13;
        if (a == 1)
            set2.insert(i);
    }

    for (auto i : set2)
    {
        cout << i << " ";
    }
    cout << endl;
}