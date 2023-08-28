//g++ -std=c++17 E.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <openssl/evp.h>
#include <cstring>
#include <tuple>
using namespace std;
//ibecame

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

vector<int> decToZ26(long long dec, int len=3)
{
    vector<int> Z26;
    while (dec > 0)
    {
        Z26.push_back(dec % 26);
        dec /= 26;
    }
    while (Z26.size() < len)
    {
        Z26.push_back(0);
    }
    vector<int> Z26_ret;
    for (int i = Z26.size() - 1; i >= 0; --i)
    {
        Z26_ret.push_back(Z26[i]);
    }
    return Z26_ret;
}

void printVecLetter(vector<int> x)
{
    for (int j = 0; j < x.size(); ++j)
    {
        cout << static_cast<char>(x[j] + 65);
    }
}

int main()
{
    int n = 18923;
    int b = 1261;
    int i = 3, p = 0, q = 0;

    while (n > 1)
    {
        if (n % i == 0)
        {
            if (p == 0)
            {
                p = i;
                ++i;
            }
            else
            {
                q = i;
                break;
            }
        }
        else
        {
            ++i;
        }
    }
    cout << "p = " << p << ", q = " << q << endl;
    cout << "p * q = " << p * q << endl;

    int fi = (p - 1) * (q - 1);
    cout << "fi = " << fi << endl;

    int a = odwrotnosc(b, fi);
    cout << "a = " << a << endl;

    vector<int> y = {
        12423, 11524, 7243, 7459, 14303, 6127, 10964, 16399, 
        9792, 13629, 14407, 18817, 18830, 13556, 3159, 16647, 
        5300, 13951, 81, 8986, 8007, 13167, 10022, 17213, 
        2264, 961, 17459, 4101, 2999, 14569, 17183, 15827, 
        12693, 9553, 18194, 3830, 2664, 13998, 12501, 18873, 
        12161, 13071, 16900, 7233, 8270, 17086, 9792, 14266, 
        13236, 5300, 13951, 8850, 12129, 6091, 18110, 3332, 
        15061, 12347, 7817, 7946, 11675, 13924, 13892, 18031, 
        2620, 6276, 8500, 201, 8850, 11178, 16477, 10161, 
        3533, 13842, 7537, 12259, 18110, 44, 2364, 15570, 
        3460, 9886, 8687, 4481, 11231, 7547, 11383, 17910, 
        12867, 13203, 5102, 4742, 5053, 15407, 2976, 9330, 
        12192, 56, 2471, 15334, 841, 13995, 17592, 13297, 
        2430, 9741, 11675, 424, 6686, 738, 13874, 8168, 
        7913, 6246, 14301, 1144, 9056, 15967, 7328, 13203, 
        796, 195, 9872, 16979, 15404, 14130, 9105, 2001, 
        9792, 14251, 1498, 11296, 1105, 4502, 16979, 1105, 
        56, 4118, 11302, 5988, 3363, 15827, 6928, 4191, 
        4277, 10617, 874, 13211, 11821, 3090, 18110, 44, 
        2364, 15570, 3460, 9886, 9988, 3798, 1158, 9872, 
        16979, 15404, 6127, 9872, 3652, 14838, 7437, 2540, 
        1367, 2512, 14407, 5053, 1521, 297, 10935, 17137, 
        2186, 9433, 13293, 7555, 13618, 13000, 6490, 5310, 
        18676, 4782, 11374, 446, 4165, 11634, 3846, 14611, 
        2364, 6789, 11634, 4493, 4063, 4576, 17955, 7965, 
        11748, 14616, 11453, 17666, 925, 56, 4118, 18031, 
        9522, 14838, 7437, 3880, 11476, 8305, 5102, 2999, 
        18628, 14326, 9175, 9061, 650, 18110, 8720, 15404, 
        2951, 722, 15334, 841, 15610, 2443, 11056, 2186
    };

    vector<int> c = decToBin(a);

    for (int i = 0; i < y.size(); ++i)
    {
        int x = potega(y[i], c, n);

        vector<int> xx = decToZ26(x);
        printVecLetter(xx);
    }
    cout << endl;
}