#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <tuple>
using namespace std;

long long f(long long x)
{
    return x*x + 1;
}

std::tuple<long long, long long, long long> rozNWD(long long j, long long k)
{
    long long r, x, y;
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

long long rhoPollard(long long n, long long x1)
{
    long long x = x1;
    long long x_prim = f(x) % n;
    auto [c, a, b] = rozNWD(abs(x - x_prim), n);
    long long p = c;

    long long count = 0;
    while(p == 1)
    {
        ++count;
        x = f(x) % n;
        x_prim = f(x_prim) % n;
        x_prim = f(x_prim) % n;
        auto [c, a, b] = rozNWD(abs(x - x_prim), n);
        p = c;
    }

    cout << "Liczba iteracji: " << count << endl;

    if (p == n)
    {
        return -1;
    }
    else
    {
        return p;
    }
}

int main()
{
    long long n = 262063, x1 = 2;
    long long c = rhoPollard(n, x1);
    cout << n << " = " << c
        << " * " << (n / c) << endl;

    n = 9420457;
    c = rhoPollard(n, x1);
    cout << n << " = " << c
        << " * " << (n / c) << endl;

    n = 181937053;
    c = rhoPollard(n, x1);
    cout << n << " = " << c
        << " * " << (n / c) << endl;
}