#include <iostream>
#include <vector>
#include <algorithm>
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
    return bin;
}

void findPeriod(vector< vector<int> > &vec)
{
    for (int i = 0; i < 16; ++i)
    {
        int p = 1;
        bool p_found = false;
        while (not p_found)
        {
            p_found = true;
            for (int j = 0; j < 100 - p; ++j)
            {
                if (vec[i][j] != vec[i][j+p])
                {
                    p_found = false;
                    ++p;
                    break;
                }
            }
        }

        cout << "P(";
        for (int j = 0; j < 4; ++j)
        {
            cout << vec[i][j];
        }
        cout << ")=" << p << endl;
    }
}

int main()
{
    vector< vector<int> > vec;
    vec.resize(16);
    for (int i = 0; i < 16; ++i)
    {
        vec[i].resize(100);
        vector<int> bin = decToBin(i);
        int k = 0;
        for (int j = 3; j >= 0; --j)
        {
            vec[i][j] = bin[k];
            ++k;
        }
    }

//a
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 4; j < 100; ++j)
        {
            vec[i][j] = (vec[i][j-4] + vec[i][j-3] + vec[i][j-2] + vec[i][j-1]) % 2;
        }
    }

    cout << "wektor:0100" << endl;
    cout << "strumien klucza:";
    for (int j = 0; j < 30; ++j)
    {
        cout << vec[4][j];
    }
    cout << endl << endl;

    findPeriod(vec);
    cout << endl;

//b    
    for (int i = 0; i < 16; ++i)
    {
        std::fill(vec[i].begin() + 4, vec[i].end(), 0);
        for (int j = 4; j < 100; ++j)
        {
            vec[i][j] = (vec[i][j-4] + vec[i][j-1]) % 2;
        }
    }

    cout << "wektor:1000" << endl;
    cout << "strumien klucza:";
    for (int j = 0; j < 30; ++j)
    {
        cout << vec[8][j];
    }
    cout << endl << endl;

    findPeriod(vec);

}