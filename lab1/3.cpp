//kompilacja: g++ -std=c++17 3.cpp

#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

int a = 17;
int b = 20;
int m = 26;

std::tuple<int, int, int> rozNWD(int j, int k)
{
    int r, x, y;
    if (j == 0)
    {
        return std::make_tuple(k, 0, 1);
    }
    r = k % j;
    auto [d, xp, yp] = rozNWD(r, j);
    x = yp - k/j * xp;
    y = xp;
    return std::make_tuple(d, x, y);
}

int odwrotnoscB(int a)
{
    auto [d, x, y] = rozNWD(a, m);

    while (x % m < 0)
    {
        x += m;
    }
    return x;
}

int a_inv = odwrotnoscB(a);

void cypher(string &text)
{
    for (int i = 0; i < text.size(); ++i)
    {
        text[i] = (a*(text[i] - 'a') + b) % m + 'a';
    }
    std::transform(text.begin(), text.end(), text.begin(), std::towupper);
}

void decypher(string &text)
{
    for (int i = 0; i < text.size(); ++i)
    {
        text[i] = (a_inv*(text[i] - 'A' - b)) % m;
        while (text[i] < 0)
        {
            text[i] += m;
        }
        text[i] += 'A';
    }
    std::transform(text.begin(), text.end(), text.begin(), std::towlower);
}

int main()
{
    cout << "a = " << a << ", a_inv = " << a_inv << endl << endl;
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