#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <openssl/evp.h>
#include <cstring>
#include <sstream>
#include <string.h>
using namespace std;
//8
vector<int> decToBin(long long dec, int len = 7)
{
    vector<int> bin;
    while (dec > 0)
    {
        bin.push_back(dec % 2);
        dec /= 2;
    }
    while (bin.size() < len)
    {
        bin.push_back(0);
    }
    vector<int> bin_ret;
    for (int i = bin.size() - 1; i >= 0; --i)
    {
        bin_ret.push_back(bin[i]);
    }
    return bin_ret;
}

void printVec(vector<int> x)
{
    int i = 0;
    for (int j = 0; j < x.size(); ++j)
    {
        cout << x[j];
        ++i;
        if (i % 4 == 0)
        {
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> A = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1},
        {0,1,1,1},
        {0,0,1,1},
        {0,0,0,1}
    };

    vector<int> sum(4);
    vector<int> result;
    for (int x = 0; x < 128; ++x)
    {
        vector<int> X = decToBin(x);
        for (int i = 0; i < 4; ++i)
        {
            sum[i] = 0;
            for (int j = 0; j < 7; ++j)
            {
                sum[i] += X[j] * A[j][i];
            }

        }
        if (sum[0] % 2 == 0 and sum[1] % 2 == 1 and sum[2] % 2 == 0 and sum[3] % 2 == 1)
        {
            result.push_back(x);
        }
    } 

    for (int x = 0; x < result.size(); ++x)
    {
        printVec(decToBin(result[x]));
    }
}