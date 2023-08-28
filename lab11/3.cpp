#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;

int power2(int m)
{
    int count = 0;
    while (m > 1)
    {
        if (m % 2 == 0)
        {
            ++count;
            m /= 2;
        }
        else
        {
            break;
        }
    }

    return count;
}

vector<int> decToBin(long long dec)
{
    vector<int> bin;
    while (dec > 0)
    {
        bin.push_back(dec % 2);
        dec /= 2;
    }
    return bin;
}

int potega(int x, vector<int> c, int n)
{
    int z = 1;
    for (int i = c.size() - 1; i >= 0; --i)
    {
        z = (z * z) % n;
        if (c[i] == 1)
        {
            z = (z * x) % n;
        }
    }
    return z;
}

bool Witness(int a, int n)
{
    int t = power2(n - 1);
    int u = (n - 1) / pow(2, t);

    vector<int> u_bin = decToBin(u);
    int x0 = potega(a, u_bin, n), x1;

    for (int i = 1; i <= t; ++i)
    {
        x1 = static_cast<int>(pow(x0, 2)) % n;
        if (x1 == -1 and x0 != 1 and x0 != (n - 1))
        {
            return true;
        }
        x0 = x1;
    }

    return x1 != 1;
}

bool Miller_Rabin(int n, int s=5)
{
    for (int j = 1; j <= s; ++j)
    {
        int a = rand() % (n - 1) + 1;
        if (Witness(a, n))
        {
            return false;
        }
    }
    return true;
}

void isPrime(int x)
{
    cout << x << " jest " << (Miller_Rabin(x) ? "pierwsza" : "zlozona") << endl;
}

int main()
{
    srand(time(0));

    array<int, 7> numbers = {561, 1729, 6601, 881, 9677, 17321, 37579};

    for (auto n : numbers)
    {
        isPrime(n);
    }
}