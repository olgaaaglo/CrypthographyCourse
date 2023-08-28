#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int m = 26;

string generatePlainText()
{
    int length = 30;
    string plainText = "";
    for (int i = 0; i < length; ++i)
    {
        plainText += 'a' + rand() % m;
    }
    return plainText;
}

string cypher(string text, int key)
{
    string cyphered = text;
    for (int i = 0; i < text.size(); ++i)
    {
        cyphered[i] = (text[i] - 'a' + key) % m + 'a';
    }
    std::transform(cyphered.begin(), cyphered.end(), cyphered.begin(), std::towupper);
    return cyphered;
}

string decypher(string text, int key)
{
    string decyphered = text;
    for (int i = 0; i < text.size(); ++i)
    {
        decyphered[i] = (text[i] - 'A' - key) % m;
        while (decyphered[i] < 0)
        {
            decyphered[i] += m;
        }
        decyphered[i] += 'A';
    }
    std::transform(decyphered.begin(), decyphered.end(), decyphered.begin(), std::towlower);
    return decyphered;
}

int main()
{
    int sum = 0;

    for (int j = 0; j < 1000; ++j)
    {
        string plainText = generatePlainText();
        int key = 0 + rand() % 26;

        string cypherText = cypher(plainText, key);

        for (int i = 0; i < 26; ++i)
        {
            string decypherText = decypher(cypherText, i);
            if (decypherText == plainText)
            {
                sum += i + 1;
                break;
            }
        }
    }
    cout << "Avg: " << sum/1000<< endl;
}