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
    int p = 227, alfa = 2;
    vector<int> b = {32, 40, 59, 156};
    vector<int> baza = {2, 3, 5, 7, 11};
    vector<vector<int>> czynniki(b.size(), vector<int>(baza.size(), 0));

    for (int i = 0; i < b.size(); ++i)
    {
        vector<long long> b_bin = decToBin(b[i]);
        long long c = potega(alfa, b_bin, p);
        cout << alfa << "^" << b[i] << " = " << c << " = ";
 
        int czynnik = 0;
        while(c > 1)
        {
            if (c % baza[czynnik] == 0)
            {
                ++czynniki[i][czynnik];
                c /= baza[czynnik];
            }
            else
            {
                ++czynnik;
            }
        }
        for (int j = 0; j < baza.size(); ++j)
        {
            if (czynniki[i][j] > 0)
            {
                if (j == 0)
                    cout << baza[j] << "^" << czynniki[i][j];
                else
                    cout << " * " << baza[j] << "^" << czynniki[i][j];
            }
        }
        cout << endl << endl;
    }

    int log2 = 1, log3, log5, log7, log11; //46,11,154,28

    // 4 * log2 + log11 = 32 % (p - 1);
    log11 = 32 % (p - 1) - 4 * log2;
    cout << "log11 = " << log11 << endl;

    // 2 * log2 + log7 = 156 % (p - 1);
    log7 = 156 % (p - 1) - 2 * log2;
    cout << "log7 = " << log7 << endl;

    // log2 + log5 + log11 = 40  % (p - 1)
    log5 = 40  % (p - 1) - log2 - log11;
    cout << "log5 = " << log5 << endl;

    // 2 * log2 + log3 + log5 = 59  % (p - 1)
    log3 = 59  % (p - 1) - 2 * log2 - log5;
    cout << "log3 = " << log3 << endl;

    //log173=26
    int y = 177, b2 = 173;
    vector<long long> y_bin = decToBin(y);

    int x = b2 * potega(2, y_bin, p) % p;
    cout << b2 << " * " << "2^" << y << " = " << x << " = ";

    int czynnik = 0;
    vector<int> czynniki2(b.size(), 0);
    while(x > 1)
    {
        if (x % baza[czynnik] == 0)
        {
            ++czynniki2[czynnik];
            x /= baza[czynnik];
        }
        else
        {
            ++czynnik;
        }
    }
    for (int j = 0; j < baza.size(); ++j)
    {
        if (czynniki2[j] > 0)
        {
            if (j == 0)
                cout << baza[j] << "^" << czynniki2[j];
            else
                cout << " * " << baza[j] << "^" << czynniki2[j];
        }
    }
    cout << endl << endl;

    int log173 = 3 * log2 + log3 + log7 - y % (p - 1);
    cout << "log173 = " << log173 << endl;

}//do srody do 10:00