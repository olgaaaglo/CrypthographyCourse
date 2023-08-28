//kompilacja:  g++ -std=c++17 4.cpp

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string key = "CIPHER";
int m = 26;

void cypher(string &text)
{
    for (int i = 0; i < text.size(); ++i)
    {
        text[i] = (text[i] - 'a' + key[i % key.size()] - 'A') % m + 'a';
    }
    std::transform(text.begin(), text.end(), text.begin(), std::towupper);
}

void decypher(string &text)
{
    for (int i = 0; i < text.size(); ++i)
    {
        text[i] = (text[i] - 'A' - key[i % key.size()] - 'A') % m;
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
    string text;
    cout << "Encryption" << endl;
    cout << "Plaintext: ";
    cin >> text;

    std::transform(text.begin(), text.end(), text.begin(), std::towlower);

    cypher(text);
    string cyphered = text;
    cout << "Cyphertext: " << text << endl;

    decypher(text);

    cout << "Decryption" << endl;
    cout << "Plaintext: " << text << endl;
    cout << "Cyphertext: " << cyphered << endl;
}