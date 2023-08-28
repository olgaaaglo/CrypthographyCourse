#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <openssl/evp.h>
#include <cstring>
#include <sstream>
#include <string.h>
using namespace std;

int main()
{
    double M = 365;
    for (int Q = 15; Q <= 30; ++Q)
    {
        double epsilon = 1;
        for (int Q1 = 0; Q1 <= Q; ++Q1)
        {
            epsilon *= (M - (Q1 + 1)) / M;
        }
        epsilon = 1 - epsilon;
        cout << "Q = " << Q << endl;
        cout << "Epsilon dokladny " << epsilon << endl;

        cout << "Epsilon szacunkowy " << 1 - exp(-Q * (Q - 1) / (2 * M)) << endl;
        cout << endl;
    }
}