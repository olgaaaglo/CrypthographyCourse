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

int main()
{
    int p = 97;
    int alfa;

    for (alfa = 2; alfa < p - 1; ++alfa)
    {
        bool end = true;
        for (int q = 2; q < sqrt(p - 1); ++q)
        {
            if ((p - 1) % q == 0)
            {
                vector<long long> b = decToBin((p - 1) / q);
                if (potega(alfa, b, p) == 1)
                {
                    end = false;
                    break;
                }
            }
        }
        if (end)
        {
            cout << alfa << endl;
            break;
        }
    }
}