#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

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
    int size = 16;

    vector<int> x1 = {0,0,0,0,
                      0,0,0,0,
                      1,1,1,1,
                      1,1,1,1};
    vector<int> x2 = {0,0,0,0,
                      1,1,1,1,
                      0,0,0,0,
                      1,1,1,1};
    vector<int> x3 = {0,0,1,1,
                      0,0,1,1,
                      0,0,1,1,
                      0,0,1,1};
    vector<int> x4 = {0,1,0,1,
                      0,1,0,1,
                      0,1,0,1,
                      0,1,0,1};
    vector<int> y1 = {1,0,1,0,
                      0,1,1,1,
                      0,1,0,1,
                      0,1,0,0};
    vector<int> y2 = {1,1,1,0,
                      0,1,0,0,
                      0,0,1,1,
                      1,0,0,1};
    vector<int> y3 = {1,0,0,0,
                      1,1,1,0,
                      1,1,1,0,
                      0,0,0,1};
    vector<int> y4 = {0,0,1,1,
                      0,1,1,0,
                      1,0,0,0,
                      1,1,0,1};

    vector<int> res1;

    for (int i = 0; i < size; ++i)
    {
        res1.push_back(((x1[i] + x4[i]) % 2 + y2[i]) % 2);
    }

    cout << "X1 + X4 + Y2 = ";
    printVec(res1);

    int sum = accumulate(res1.begin(), res1.end(), 0);
    double P1 = 1 - sum / static_cast<double>(size);
    cout << "Pr[X1 + X4 + Y2 = 0] = " << P1 << endl;  

    double P2 = sum / static_cast<double>(size);
    cout << "Pr[X1 + X4 + Y2 = 1] = " << P2 << endl; 

    cout << "eps[X1 + X4 + Y2 = 0] = " << P1 - 0.5 << endl;
    cout << "eps[X1 + X4 + Y2 = 1] = " << P2 - 0.5 << endl; 

    cout << endl;

    vector<int> res2;

    for (int i = 0; i < size; ++i)
    {
        res2.push_back( ( ( (x3[i] + x4[i]) % 2 + y1[i]) % 2 + y4[i]) % 2);
    }

    cout << "X3 + X4 + Y1 + Y4 = ";
    printVec(res2);

    sum = accumulate(res2.begin(), res2.end(), 0);
    P1 = 1 - sum / static_cast<double>(size);
    cout << "Pr[X3 + X4 + Y1 + Y4 = 0] = " << P1 << endl;  

    P2 = sum / static_cast<double>(size);
    cout << "Pr[XX3 + X4 + Y1 + Y4 = 1] = " << P2 << endl; 

    cout << "eps[X3 + X4 + Y1 + Y4 = 0] = " << P1 - 0.5 << endl;
    cout << "eps[X3 + X4 + Y1 + Y4 = 1] = " << P2 - 0.5 << endl;                                     
}