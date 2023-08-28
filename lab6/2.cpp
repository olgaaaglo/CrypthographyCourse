#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

vector<int> decToBin(int dec)
{
    vector<int> bin;
    while (dec > 0)
    {
        bin.push_back(dec % 2);
        dec /= 2;
    }
    while (bin.size() < 4)
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

double calc_0(vector<vector<int>> a, int size)
{
    vector<int> res1;
    for (int i = 0; i < size; ++i)
    {
        res1.push_back(0);
        for (int j = 0; j < a.size(); ++j)
        {
            res1[i] = (res1[i] + a[j][i]) % 2;
        }
    }

    int sum = accumulate(res1.begin(), res1.end(), 0);

    return size - sum;
}

int main()
{
    int size = 16;

    vector<vector<int>> x = { {0,0,0,0,
        0,0,0,0,
        1,1,1,1,
        1,1,1,1},
        {0,0,0,0,
        1,1,1,1,
        0,0,0,0,
        1,1,1,1},
        {0,0,1,1,
        0,0,1,1,
        0,0,1,1,
        0,0,1,1},
        {0,1,0,1,
        0,1,0,1,
        0,1,0,1,
        0,1,0,1} };
    vector<vector<int>> y = { {1,0,1,0,
        0,1,1,1,
        0,1,0,1,
        0,1,0,0},
        {1,1,1,0,
        0,1,0,0,
        0,0,1,1,
        1,0,0,1},
        {1,0,0,0,
        1,1,1,0,
        1,1,1,0,
        0,0,0,1},
        {0,0,1,1,
        0,1,1,0,
        1,0,0,0,
        1,1,0,1} };

    vector<vector<int>> ab(size, vector<int>(size));
    vector<vector<double>> eps(size, vector<double>(size));

    for (int a = 0; a < size; ++a)
    {
        for (int b = 0; b < size; ++b)
        {
            vector<int> a_bin = decToBin(a);
            vector<int> b_bin = decToBin(b);

            vector<vector<int>> xy;
            for (int i = 0; i < a_bin.size(); ++i)
            {
                if (a_bin[i])
                {
                    xy.push_back(x[i]);
                }
                if (b_bin[i])
                {
                    xy.push_back(y[i]);
                }
            }

            ab[a][b] = calc_0(xy, size);
            printf("%2d ", ab[a][b]);

            eps[a][b] = ab[a][b] / static_cast<double>(size) - 0.5;
        }
        cout << endl;
    }
    cout << endl;

    for (int a = 0; a < size; ++a)
    {
        for (int b = 0; b < size; ++b)
        {
            printf("%6.3f ", eps[a][b]);
        }
        cout << endl;
    }
}