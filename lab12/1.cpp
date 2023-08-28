//g++ -std=c++17 1.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <tuple>
using namespace std;

vector<long long> decToBin(long long dec)
{
    vector<long long> bin;
    while (dec > 0)
    {
        bin.push_back(dec % 2);
        dec /= 2;
    }
    return bin;
}

long long potega(long long x, vector<long long> c, long long n)
{
    long long z = 1;
    for (long long i = c.size() - 1; i >= 0; --i)
    {
        z = (z * z) % n;
        if (c[i] == 1)
        {
            z = (z * x) % n;
        }
    }
    return z;
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

long long pollard_p_1(long long n, long long B)
{
    long long a = 2;
    for (long long j = 2; j <= B; ++j)
    {
        vector<long long> j_bin = decToBin(j);
        a = potega(a, j_bin, n);
        auto [d, x, y] = rozNWD(a - 1, n);
        if (1 < d and d < n)
        {
            cout << "B = " << j << endl;
            return d;
        }
    }
    return -1;
}

int main()
{
    long long n = 262063;
    int p = pollard_p_1(n, 20);
    cout << n << " = " << p << " * " << (n / p) << endl;

    n = 9420457;
    p = pollard_p_1(n, 50);
    cout << n << " = " << p << " * " << (n / p) << endl;
}