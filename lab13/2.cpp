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

bool sortbysec(const pair<long long,long long> &a,
              const pair<long long,long long> &b)
{
    return (a.second < b.second);
}

long long binary_search_find_index(std::vector<long long> v, long long data) {
    auto it = std::lower_bound(v.begin(), v.end(), data);
    if (it == v.end() || *it != data) {
        return -1;
    } else {
        std::size_t index = std::distance(v.begin(), it);
        return index;
    }   
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

long long odwrotnosc(long long a, long long m)
{
    auto [d, x, y] = rozNWD(a, m);

    while (x % m < 0)
    {
        x += m;
    }
    return x;
}

long long shanks(long long n, long long alfa, long long beta, long long p)
{
    long long m  = sqrt(n) + 1;
    vector<pair<long long, long long>> L1(m);
    for (long long j = 0; j < m; ++j)
    {
        vector<long long> b = decToBin(m * j);
        L1[j] = {j, potega(alfa, b, p)};
    }
    sort(L1.begin(), L1.end(), sortbysec);

    vector<pair<long long, long long>> L2(m);
    for (long long i = 0; i < m; ++i)
    {
        vector<long long> b = decToBin(i);
        L2[i] = {i, (beta * odwrotnosc(potega(alfa, b, p), p)) % p};
    }
    sort(L2.begin(), L2.end(), sortbysec);

    vector<long long> L2second;
    for (long long i = 0; i < m; ++i)
    {
        L2second.push_back(L2[i].second);
    }
    for (long long j = 0; j < m; ++j)
    {
        
        long long i = binary_search_find_index(L2second, L1[j].second);
        if(i != -1)
        {
            cout << "m = " << m << ", j = " << L1[j].first 
                << ", i = " << L2[i].first << endl;
            cout << "log = " << (m * L1[j].first + L2[i].first) % n << endl;
            return (m * L1[j].first + L2[i].first) % n;
        }
    }
    return -1;
}

int main()
{
    long long alfa = 106;
    long long beta = 12375;
    long long p = 24691;
    shanks(p, alfa, beta, p);

    alfa = 6;
    beta = 248388;
    p = 458009;
    shanks(p, alfa, beta, p);
}