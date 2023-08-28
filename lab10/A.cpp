#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <openssl/evp.h>
#include <cstring>
using namespace std;

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

int odwrotnosc(int a, int m)
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
    cout << "Odwrotnosc 17 mod 101 = " << odwrotnosc(17, 101) << endl;
    cout << "Odwrotnosc 357 mod 1234 = " << odwrotnosc(357, 1234) << endl;
    cout << "Odwrotnosc 3125 mod 9987 = " << odwrotnosc(3125, 9987) << endl;
}