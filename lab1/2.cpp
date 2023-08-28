//kompilacja:  g++ -std=c++17 2_poprawa.cpp

#include <iostream>
#include <array>
#include <algorithm>
#include <tuple>
using namespace std;

int m = 26;

int odwrotnoscA(int x)
{
    for (int i = 0; i < m; ++i)
    {
        if (x*i % m == 1)
        {
            return i;
        }
    }
    return -1;
}

// d = 1, x = -15, y = 7
std::tuple<int, int, int> rozNWD(int j, int k)
{
    int r, x, y;
    if (j == 0)
    {
        return std::make_tuple(k, 0, 1);
    }
    r = k % j;
    auto [d, xp, yp] = rozNWD(r, j);
    x = yp - k/j * xp;
    y = xp;
    return std::make_tuple(d, x, y);
}

int odwrotnoscB(int a)
{
    auto [d, x, y] = rozNWD(a, m);

    while (x % m < 0)
    {
        x += m;
    }
    return x;
}

int main()
{
    array tab{1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};

    for (const auto& x : tab)
    {
        cout << "inv of " << x << " is " << odwrotnoscA(x) << endl;
    }

    for (const auto& x : tab)
    {
        cout << "GCD_ext: inv of " << x << " is " << odwrotnoscB(x) << endl;
    }
}