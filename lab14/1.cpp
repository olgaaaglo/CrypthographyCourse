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

long long odwrotnosc(long long a, long long m)
{
    auto [d, x, y] = rozNWD(a, m);

    while (x % m < 0)
    {
        x += m;
    }
    return x;
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
    long long p = 31847, alfa = 5, a = 7899, beta = 18074;

    // long long y1 = 3781;
    // long long y2 = 14409;

    // vector<long long> a_bin = decToBin(a);
    // long long res = y2 * odwrotnosc(potega(y1, a_bin, p), p) % p;
    // cout << "res " << res << endl;//she


    // // for (int i = 0; i < y.size(); ++i)
    // {
    //     vector<int> xx = decToZ26(res);
    //     printVecLetter(xx);
    // }
    // cout << endl;

    vector<vector<int>> y1 = {
            {3781, 14409},  
            {5400, 31486},
            {31590, 26470},
            {16160, 3129},
            {30555, 24611},
            {1616, 14170},
            {14130, 22010},
            {26004, 25056},
            {29538, 5408},
            {1777, 8737},
            {23258, 3468},
            {8836, 25898},
            {10422, 5552},
            {25115, 10840},
            {23418, 22058},
            {19886, 22344},
            {21563, 7891},
            {24271, 8480},
            {30499, 14423},
            {24875, 17641},
            {3576, 4630},
            {3149, 7400},
            {21541, 19004},
            {17561, 11884},
            {26521, 5803},
            {28327, 19237}
    };

    vector<vector<int>> y2 = {
        { 31552, 3930},
        { 19936, 721 },
        { 3781, 14409},
        { 301, 17252 },
        { 20501, 2922},
        { 4294, 2307 },
        { 25910, 19663},
        { 5400, 31486},
        { 3149, 7400 },
        { 26117, 14251},
        { 26052, 20545},
        { 8794, 17358},
        { 1777, 8737 },
        { 14130, 22010},
        { 24139, 9580},
        { 21600, 25505},
        { 28250, 21321},
        { 26592, 25457},
        { 5839, 24179},
        { 1777, 8737 },
        { 26664, 27572},
        { 8951, 29435},
        { 5865, 29526},
        { 2209, 6107 },
        { 14884, 14280},
        { 15313, 28649}
    };

    vector<vector<int>> y3 = {
        {27214, 15442},
        {27765, 29284},
        {15898, 30844},
        {24689, 7776 },
        {13659, 5015 },
        {2320, 29174 },
        {19557, 10145},
        {9526, 3019},
        {9396, 3058},
        {7129, 18195 },
        {21958, 5713 },
        {1777, 8737},
        {3780, 16360 },
        {16081, 16414},
        {173, 17075},
        {27119, 19921},
        {28327, 19237},
        {9660, 7939},
        {12846, 6598 },
        {18825, 19671},
        {27011, 29164},
        {2059, 3977},
        {10536, 6941 },
        {10422, 5552 },
        {4328, 8635}
    };

    vector<vector<int>> y4 = {
        {5809, 30274},
        {29820, 7710},
        {19048, 12914 },
        {28856, 15720 },
        {5740, 31233},
        {3036, 20132},
        {18899, 27609 },
        {12962, 15189 },
        {27149, 20535 },
        {25302, 10248 },
        {346, 31194},
        {25038, 12483 },
        {11685, 133},
        {28580, 20845 },
        {2016, 18131},
        {23312, 16906 },
        {15313, 28649 },
        {10267, 20623 },
        {9284, 27858},
        {31306, 11929 },
        {22763, 8992},
        {16258, 30341 },
        {1777, 8737},
        {19371, 21005 },
        {28250, 21321 }
    };
    
    vector<long long> a_bin = decToBin(a);

    for (int i = 0; i < y1.size(); ++i)
    {
        long long res = y1[i][1] * odwrotnosc(potega(y1[i][0], a_bin, p), p) % p;
        vector<int> xx = decToZ26(res);
        printVecLetter(xx);

        res = y2[i][1] * odwrotnosc(potega(y2[i][0], a_bin, p), p) % p;
        xx = decToZ26(res);
        printVecLetter(xx);

        if (i < y3.size())
        {
            res = y3[i][1] * odwrotnosc(potega(y3[i][0], a_bin, p), p) % p;
            xx = decToZ26(res);
            printVecLetter(xx);

            res = y4[i][1] * odwrotnosc(potega(y4[i][0], a_bin, p), p) % p;
            xx = decToZ26(res);
            printVecLetter(xx);
        }
    }
    cout << endl;
    
}