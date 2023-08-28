#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> PIs = {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7};
vector<int> PIp = {1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16};

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

int binToDec(vector<int> bin)
{
    int dec = 0;
    int j = 0;
    for (int i = bin.size() - 1; i >= 0; --i)
    {
        dec += bin[i] * std::pow(2, j++);
    }

    return dec;
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

void setUrOrY(
    vector<int> &ur, 
    vector<int> &w,
    vector<int> &K,
    int r)
{
    //cout << "K" << (r + 1) << ": ";
    for (int j = 0; j < ur.size(); ++j)
    {
        ur[j] = (w[j] + K[r*4 + j]) % 2;
        // cout << K[r*4 + j];
        // if ((j + 1) % 4 == 0)
        //     cout << " ";
    }
    //cout << endl;
}

void setVr(
    vector<int> &ur,
    vector<int> &vr,
    int m)
{
    for (int i = 1; i <= m; ++i)
    {
        vector<int> bin(4);
        for (int j = 0; j < 4; ++j)
        {
            bin[j] = ur[(i-1)*4 + j];
        }

        bin = decToBin(PIs[binToDec(bin)]);
        for (int j = 0; j < 4; ++j)
        {
            vr[(i-1)*4 + j] = bin[j];
        }
    }
}

vector<int> SPN(vector<int> &x, int N, vector<int> &K, int m)
{
    vector<vector<int>> w(N, vector<int>(x.size()));
    vector<int> ur(x.size());
    vector<int> vr(x.size());

    w[0] = x;
    // cout << "w0: ";
    // printVec(w[0]);
    // cout << endl;

    for (int r = 1; r <= N; ++r)
    {
        setUrOrY(ur, w[r - 1], K, r - 1);
        // cout << "u" << r << ": ";
        // printVec(ur);

        setVr(ur, vr, m);
        // cout << "v" << r << ": ";
        // printVec(vr);

        if (r < N)
        {
            for (int j = 0; j < w[r].size(); ++j)
            {
                w[r][PIp[j] - 1] = vr[j];
            }
            // cout << "w" << r << ": ";
            // printVec(w[r]);
        }
        // cout << endl;
    }

    vector<int> y(x.size());
    setUrOrY(y, vr, K, N);
    // cout << endl << "y" << ": ";
    // printVec(y);

    return y;
}