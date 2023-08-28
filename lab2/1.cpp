#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int m = 26;

void decypher(string &text, int key)
{
    for (int i = 0; i < text.size(); ++i)
    {
        text[i] = (text[i] - 'A' - key) % m;
        while (text[i] < 0)
        {
            text[i] += m;
        }
        text[i] += 'A';
    }
}

int main()
{
    string cypher_text = "BEEAKFYDJXUQYHYJIQRYHTYJIQFBQDUYJIIKFUHCQD";

    for (int i = 1; i < 26; ++i)
    {
        decypher(cypher_text, i);
        cout << cypher_text << " " << i << endl;
    }
}