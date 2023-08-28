//kompilacja: g++ -std=c++17 5.cpp

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <cmath>
using namespace std;

int m = 26;
std::array<std::array<int,2>,2> K{ 11, 8,
                                    3, 7 };

std::array<std::array<int,2>,2> K_inv{ 0, 0, 
                                        0, 0 };

int det()
{
    int det = (K[0][0] * K[1][1] - K[0][1] * K[1][0]) % m;
    while (det < 0)
    {
        det += m;
    }
    return det;
}

void calc_K_inv()
{
    K_inv = { K[1][1], -K[0][1] + m, - K[1][0] + m, K[0][0] };
}

void cypher(string &text)
{
    if (text.size() % 2 == 1)
    {
        text += 'x';
    }
    string cyphered = text;
    for (int i = 0; i < text.size(); i += 2)
    {
        cyphered[i] = ((text[i] - 'a') * K[0][0] + (text[i+1] - 'a') * K[1][0]) % m + 'a';
        cyphered[i+1] = ((text[i] - 'a') * K[0][1] + (text[i+1] - 'a') * K[1][1]) % m + 'a';
    }
    text = cyphered;

    std::transform(text.begin(), text.end(), text.begin(), std::towupper);
}

void decypher(string &text)
{
    string decyphered = text;
    for (int i = 0; i < text.size(); i += 2)
    {
        decyphered[i] = ((text[i] - 'A') * K_inv[0][0] + (text[i+1] - 'A') * K_inv[1][0]) % m + 'A';
        decyphered[i+1] = ((text[i] - 'A') * K_inv[0][1] + (text[i+1] - 'A') * K_inv[1][1]) % m + 'A';
    }
    text = decyphered;

    std::transform(text.begin(), text.end(), text.begin(), std::towlower);
}

int main()
{
    calc_K_inv();
    cout << "det = " << det() << endl;
    cout << "det_inv = " << 1.0/det() << endl << endl;

    cout << "K: " << endl;
    cout << K[0][0] << " " << K[0][1] << endl;
    cout << K[1][0] << " " << K[1][1] << endl << endl;

    cout << "K_inv: " << endl;
    cout << K_inv[0][0] << " " << K_inv[0][1] << endl;
    cout << K_inv[1][0] << " " << K_inv[1][1] << endl << endl;

    string text;
    cout << "Encryption" << endl;
    cout << "Plaintext: ";
    cin >> text;

    std::transform(text.begin(), text.end(), text.begin(), std::towlower);

    cypher(text);
    string cyphered = text;
    cout << "Cyphertext: " << text << endl << endl;

    decypher(text);

    cout << "Decryption" << endl;
    cout << "Plaintext: " << text << endl;
    cout << "Cyphertext: " << cyphered << endl;
}