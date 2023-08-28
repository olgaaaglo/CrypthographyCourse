#include <iostream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

constexpr int m = 26;

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
    string cypherText = "BEEAKFYDJXUQYHYJIQRYHTYJIQFBQDUYJIIKFUHCQD";
    string englishFrequency = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    vector<int> frequency;
    frequency.resize(m);

    for (int i = 0; i < cypherText.size(); ++i)
    {
        ++frequency[cypherText[i] - 'A'];
    }

    int dist = distance(frequency.begin(), std::max_element(frequency.begin(), frequency.end()));
    char c = 'A' + dist;

    for (int i = 0; i < 5; ++i)
    {
        int key = c - englishFrequency[i];

        while (key < 0)
        {
            key += m;
        }

        string decyphered = decypher(cypherText, key);
        cout << i + 1 << ". Plaintext: " << decyphered << " Key: " << key << endl;
    }
}