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

int main()
{
    vector<double> P = {0.5, 0.5};
    cout << "Entropia dla P(reszka) = 0.5, P(orzel) = 0.5: " << entropy(P) << endl;

    P = {0.25, 0.75};
    cout << "Entropia dla P(reszka) = 0.25, P(orzel) = 0.75: " << entropy(P) << endl;

    P = {0.01, 0.99};
    cout << "Entropia dla P(reszka) = 0.01, P(orzel) = 0.99: " << entropy(P) << endl;
}