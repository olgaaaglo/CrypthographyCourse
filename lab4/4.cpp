#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

double entropy(double P, double nr)
{
    double H = P * log2(P) * nr;
    H = -H;
    return H;
}

int main()
{
    double n = 128;
    double nr = std::pow(2, n);
    double P = 1.0 / nr;
    cout << "n: " << n << endl;
    cout << "P: " << P << endl;
    cout << "Entropia: " << entropy(P, nr) << endl;
    cout << "Entropia dla n = n" << endl;
}