#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cypher(vector<int> &x, vector<int> &key_stream)
{
    vector<int> y;
    y.resize(x.size());
    for (int i = 0; i < x.size(); ++i)
    {
        y[i] = (x[i] + key_stream[i]) % 2;
    }
    return y;
}

void printVec(vector<int> x)
{
    for (int i = 0; i < x.size(); ++i)
    {
        cout << x[i];
    }
    cout << endl;
}

int main()
{
    vector<int> key_stream = {1, 1, 0, 1, 0};
    vector<int> plaintext = {0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};
    cout << "Encryption" << endl;
    cout << "Plaintext: ";
    printVec(plaintext);

    for (int i = 5; i < plaintext.size(); ++i)
    {
        key_stream.push_back((key_stream[i-5] + key_stream[i-2]) % 2);
    }
    cout << "Key stream: ";
    printVec(key_stream);

    vector<int> cyphered = cypher(plaintext, key_stream);
    cout << "Cyphertext: ";
    printVec(cyphered);

    cout << endl << "Decryption" << endl;
    cout << "Cyphertext: ";
    printVec(cyphered);

    cout << "Key stream: ";
    printVec(key_stream);

    vector<int> decyphered = cypher(cyphered, key_stream);
    cout << "Plaintext: ";
    printVec(decyphered);
}