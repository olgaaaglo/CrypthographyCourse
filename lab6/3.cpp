#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include "spn.hpp"
using namespace std;

vector<int> PIs_1 = {14,3,4,8,1,12,10,15,7,13,9,6,11,2,0,5};
int sizeT = 10000;
int size = 16;

std::vector<int> K = {0, 0, 1, 1, 
                        1, 0, 1, 0, 
                        1, 0, 0, 1, 
                        0, 1, 0, 0,
                        1, 1, 0, 1,
                        0, 1, 1, 0,
                        0, 0, 1, 1,
                        1, 1, 1, 1};

int calcXor(vector<int> a)
{
    int res = 0;
    for (int j = 0; j < a.size(); ++j)
    {
        res = (res + a[j]) % 2;
    }
    return res;
}

void setT(vector<vector<vector<int>>> &T)
{
    for (int i = 0; i < sizeT; ++i)
    {
        vector<int> x(size);
        for (int j = 0; j < size; ++j)
        {
            x[j] = rand() % 2;
        }

        int m = 4;
        int N = 4;
        vector<int> y = SPN(x, N, K, m);
        
        T[i][0] = x; 
        T[i][1] = y;
    }
}

vector<int> findMax(vector<vector<int>> &count)
{
    int max = -1;
    vector<int> maxkey(2);
    for (int L1 = 0; L1 < size; ++L1)
    {
        for (int L2 = 0; L2 < size; ++L2)
        {
            count[L1][L2] -= sizeT / 2;
            if (count[L1][L2] > max)
            {
                max = count[L1][L2];
                maxkey[0] = L1;
                maxkey[1] = L2;
            }
        }
    }
    return maxkey;
}

int main()
{
    vector<vector<vector<int>>> T(sizeT, vector<vector<int>>(2, vector<int>(size)));
    setT(T);

    vector<vector<int>> count(size, vector<int>(size, 0));

    for (int i = 0; i < sizeT; ++i)
    {
        for (int L1 = 0; L1 < size; ++L1)
        {
            for (int L2 = 0; L2 < size; ++L2)
            {
                vector<int> V42(4);
                vector<int> V44(4);
                vector<int> L1_bin = decToBin(L1);
                vector<int> L2_bin = decToBin(L2);
                for (int j = 0; j < 4; ++j)
                {
                    V42[j] = (L1_bin[j] + T[i][1][1 * 4 + j]) % 2;
                    V44[j] = (L2_bin[j] + T[i][1][3 * 4 + j]) % 2;
                }

                vector<int> U42 = decToBin(PIs_1[binToDec(V42)]);
                vector<int> U44 = decToBin(PIs_1[binToDec(V44)]);

                vector<int> toSum = { T[i][0][4], T[i][0][6], T[i][0][7], U42[1], U42[3], U44[1], U44[3] };
                int z = calcXor(toSum);

                if (z == 0)
                {
                    ++count[L1][L2];
                }
            }
        }
    }

    vector<int> maxkey = findMax(count);

    cout << "L1 = ";
    printVec(decToBin(maxkey[0]));

    cout << "L2 = ";
    printVec(decToBin(maxkey[1]));

}