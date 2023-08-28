#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

int m = 26;
array pi{2, 4, 6, 1, 8, 3, 5, 7};

int indexOf(array<int, 8> arr, int val)
{
    for (int i = 0; i < 8; ++i)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

void cypher(string &text)
{
    while (text.size() % pi.size() != 0)
    {
        text += 'x';
    }
    string cyphered = text;
    for (int i = 0; i < text.size(); ++i)
    {
        int start = i/pi.size() * pi.size();
        cyphered[start + pi[i % pi.size()] - 1] = text[i];
    }
    text = cyphered;

    std::transform(text.begin(), text.end(), text.begin(), std::towupper);
}

void decypher(string &text)
{
    string decyphered = text;
    for (int i = 0; i < text.size(); ++i)
    {
        int start = i/pi.size() * pi.size();
        decyphered[start + indexOf(pi, i % pi.size() + 1)] = text[i];
    }
    text = decyphered;

    std::transform(text.begin(), text.end(), text.begin(), std::towlower);
}

int main()
{
    string text;
    cout << "Decryption" << endl;
    cin >> text;
    string original = text;

    std::transform(text.begin(), text.end(), text.begin(), std::towlower);

    decypher(text);
    string decyphered = text;
    cout << "Plaintext: " << decyphered << endl;
    cout << "Cyphertext: " << original << endl << endl;

    cypher(text);

    cout << "Encryption" << endl;
    cout << "Plaintext: " << decyphered << endl;
    cout << "Cyphertext: " << text << endl;
}