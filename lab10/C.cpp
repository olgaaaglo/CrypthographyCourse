#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <openssl/evp.h>
#include <cstring>
using namespace std;
//17
//cout M, M1, M2, M3, y1, y2, y3, X-1, 

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
    int m1 = 3, m2 = 5, m3 = 7;
    int a1 = 2, a2 = 2, a3 = 3;
    int M = m1 * m2 * m3;
    cout << "M = " << M << endl;

    int M1 = m2 * m3;
    int M2 = m1 * m3;
    int M3 = m2 * m1;
    cout << "M1 = " << M1 << ", M2 = " << M2 
        << ", M3 = " << M3 << endl;

    int y1 = odwrotnosc(M1, m1);
    int y2 = odwrotnosc(M2, m2);
    int y3 = odwrotnosc(M3, m3);
    cout << "y1 = " << y1 << ", y2 = " << y2 
        << ", y3 = " << y3 << endl;

    cout << "X^(-1)(a1, a2, a3) = " << "(" << y1 * M1 
        << "a1 + " << y2 * M2 << "a2 + " << y3 * M3
        << "a3) mod " << M << endl;

    int X_1 = (y1 * M1 * a1 + y2 * M2 * a2 + y3 * M3 * a3) % M;
    cout << "X^(-1)(2, 2, 3) = " << X_1 << endl;
}