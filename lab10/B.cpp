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

int main()
{
    int a = 57, m = 93;
    auto [r, s, t] = rozNWD(a, m);

    cout << "NWD(57, 93) = " << r << endl;
    cout << "57 * " << s << " + 93 * " << t << " = " 
        << (s * 57 + t * 93) << endl;
}