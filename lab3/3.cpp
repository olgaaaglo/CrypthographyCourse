#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int max_length = 3000;

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
    return bin;
}

int parity(int y)
{
    vector<int> bin = decToBin(y);
    int count = 0;
    for (int i = 0; i < bin.size(); ++i)
    {
        if (bin[i])
        {
            ++count;
        }
    }

    return count % 2;
}

vector<int> blum_blum_shub(int p, int q, int s)
{
    int n = p*q;
    int y = (s * s) % n;
    vector<int> z;

    for (int i = 0; i < max_length; ++i)
    {
        y = (y * y) % n;
        z.push_back(parity(y));
    }

    return z;
}

void printVec(vector<int> x)
{
    for (int i = 0; i < 100; ++i)
    {
        cout << x[i];
    }
    cout << endl;
}

int findPeriod(vector<int> &vec)
{
    int p = 1;
    bool p_found = false;
    while (not p_found)
    {
        p_found = true;
        for (int j = 0; j < max_length - p; ++j)
        {
            if (vec[j] != vec[j+p])
            {
                p_found = false;
                ++p;
                break;
            }
        }
    }

    return p;
}

int main()
{
    //a
    vector<int> vec = blum_blum_shub(7, 19, 100);
    printVec(vec);
    cout << "Period: " << findPeriod(vec) << endl;

    //b
    vec = blum_blum_shub(67, 71, 100);
    printVec(vec);
    cout << "Period: " << findPeriod(vec) << endl;

    //c
    vec = blum_blum_shub(163, 167, 100);
    printVec(vec);
    cout << "Period: " << findPeriod(vec) << endl;
}