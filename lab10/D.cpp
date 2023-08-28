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
    int a1 = 13, r1 = 4, m1 = 99;
    int a1_1 = odwrotnosc(a1, m1);
    int a2 = 15, r2 = 56, m2 = 101;
    int a2_1 = odwrotnosc(a2, m2);

    cout << "13x = 4 mod 99" << endl;
    cout << "x = 4 * " << a1_1 << " mod 99" << endl;
    int b1 = r1 * a1_1 % m1;
    cout << "x = " << b1 << " mod 99" << endl << endl;

    cout << "15x = 56 mod 101" << endl;
    cout << "x = 56 * " << a2_1 << " mod 101" << endl;
    int b2 = r2 * a2_1 % m2;
    cout << "x = " << b2 << " mod 101" << endl << endl;



    int M = m1 * m2;
    cout << "M = " << M << endl;

    int M1 = m2;
    int M2 = m1;
    cout << "M1 = " << M1 << ", M2 = " << M2 << endl;

    int y1 = odwrotnosc(M1, m1);
    int y2 = odwrotnosc(M2, m2);
    cout << "y1 = " << y1 << ", y2 = " << y2 << endl;

    cout << "X^(-1)(a1, a2) = " << "(" << y1 * M1 
        << "a1 + " << y2 * M2 << "a2) + mod " << M << endl;

    int X_1 = (y1 * M1 * b1 + y2 * M2 * b2) % M;
    cout << "X^(-1)(" << b1 << ", " << b2 << ") = " 
        << X_1 << endl;
}