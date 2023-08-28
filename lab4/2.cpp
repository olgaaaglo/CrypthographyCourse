#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

double entropy(vector<double> P)
{
    double H = 0;
    for (int i = 0; i < P.size(); ++i)
    {
        H += P[i] * log2(P[i]);
    }
    H = -H;
    return H;
}

int getIndexOf(vector< vector<int> > &matrix, int j, int val)
{
    for (int i = 0; i < 3; ++i)
    {
        if (matrix[i][j] == val)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<double> Prabc = {0.5, 1/3.0, 1/6.0};
    vector<double> PrK = {1/3.0, 1/3.0, 1/3.0};

    vector< vector<int> > matrix =  { {1, 2, 3},
                                        {2, 3, 4},
                                        {3, 4, 1}};

    double HP = entropy(Prabc);
    cout << "H(P) = " << HP << endl;

    double HK = entropy(PrK);
    cout << "H(K) = " << HK << endl;

    vector<double> PrC(4, 0);

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            PrC[matrix[i][j] - 1] += PrK[i] * Prabc[j];
        }
    }

    double HC = entropy(PrC);
    cout << "H(C) = " << HC << endl;

    cout << "H(K|C) = " << HK + HP - HC << endl;

    vector< vector<double> > PrPC(4, vector<double>(3));
    double HPC = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int idx = getIndexOf(matrix, j, i + 1);
            if (idx == -1)
            {
                PrPC[i][j] = 0;
            }
            else
            {
                PrPC[i][j] = Prabc[j] * PrK[idx] / PrC[i];
                HPC += PrC[i] * PrPC[i][j] * log2(PrPC[i][j]); 
            }
        }
    }
    HPC = -HPC;

    cout << "H(P|C) = " << HPC << endl;
}