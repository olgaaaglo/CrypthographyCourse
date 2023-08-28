#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> KSA(string key)
{
    vector<int> S;
    for (int i = 0; i < 256; ++i)
    {
        S.push_back(i);
    }
    int j = 0;
    for (int i = 0; i < 256; ++i)
    {
        j = (j + S[i] + key[i % key.size()]) % 256;
        int temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
    return S;
}

vector<int> Stream_Generator(string Plaintext, vector<int> S)
{
    int i = 0;
    int j = 0;
    vector<int> result_cyphered(Plaintext.size());
    for (int k = 0; k < Plaintext.size(); ++k)
    {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        int temp = S[i];
        S[i] = S[j];
        S[j] = temp;

        int byte_key = S[(S[i] + S[j]) % 256];
        cout << std::hex << static_cast<int>(byte_key);

        result_cyphered[k] = Plaintext[k] ^ byte_key;
    }
    cout << endl;
    return result_cyphered;
}

void getCypher(string key, string Plaintext)
{
    vector<int> S = KSA(key);
    cout << "Keystream: ";
    vector<int> result_cyphered = Stream_Generator(Plaintext, S);

    cout << "Plaintext: " << Plaintext << endl;
    cout << "Key: " << key << endl;

    cout << "Ciphertext: ";
    for (int i = 0; i < result_cyphered.size(); ++i)
    {
        cout << std::hex << result_cyphered[i];
    }
    cout << endl;
}

int main()
{
    string key = "Secret";
    string Plaintext = "Attack at dawn";
    getCypher(key, Plaintext);
    cout << endl;

    key = "Key";
    Plaintext = "Plaintext";
    getCypher(key, Plaintext);
    cout << endl;

    key = "Wiki";
    Plaintext = "pedia";
    getCypher(key, Plaintext);
    cout << endl;
}