//kompilacja:  g++ -std=c++17

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

double Ic(std::vector<char> &x)
{
    std::vector<int> f;
    f.resize(26);
    for (int i = 0; i < x.size(); ++i)
    {
        ++f[x[i] - 'A'];
    }

    double Icx = 0;
    for (int i = 1; i < 26; ++i)
    {
        Icx += f[i] * (f[i] - 1);
    }

    Icx /= (x.size() * (x.size() - 1));
    return Icx;
}

void decypher(string &text, string key)
{
    for (int i = 0; i < text.size(); ++i)
    {
        text[i] = (text[i] - 'A' - key[i % key.size()] - 'A') % 26;
        while (text[i] < 0)
        {
            text[i] += 26;
        }
        text[i] += 'A';
    }
    std::transform(text.begin(), text.end(), text.begin(), std::towlower);
}

int main()
{
    string cypherText = "KCCPKBGUFDPHQTYAVINRRTMVGRKDNBVFDETDGILTXRGUD"
                         "DKOTFMBPVGEGLTGCKQRACQCWDNAWCRXIZAKFTLEWRPTYC"
                         "QKYVXCHKFTPONCQQRHJVAJUWETMCMSPKQDYHJVDAHCTRL"
                        "SVSKCGCZQQDZXGSFRLSWCWSJTBHAFSIASPRJAHKJRJUMV"
                         "GKMITZHFPDISPZLVLGWTFPLKKEBDPGCEBSHCTJRWXBAFS"
                         "PEZQNRWXCVYCGAONWDDKACKAWBBIKFTIOVKCGGHJVLNHI"
                         "FFSQESVYCLACNVRWBBIREPBBVFEXOSCDYGZWPFDTKFQIY"
                         "CWHJVLNHIQIBTKHJVNPIST";

    std::cout << "Length = " << cypherText.size() << std::endl << std::endl; 

// Aby określić tekst jawny najpierw potrzebne było znalezienie 3-literowych takich samych słów w tekście:
    for (int i = 0; i < cypherText.size() - 2; ++i)
    {
        for (int j = i + 1; j < cypherText.size() - 2; ++j)
        {
            if (cypherText[i] == cypherText[j] and cypherText[i + 1] == cypherText[j + 1] and cypherText[i + 2] == cypherText[j + 2])
            {
                //std::cout << cypherText[i] << cypherText[i + 1] << cypherText[i + 2] << std::endl; 
            }
        }
    }
// Znaleziono ciąg HJV.

// Następnie obliczono odległości ciągu HJV od początku szyfrogramu:
    std::vector<int> dist_from_start;
    dist_from_start.resize(5);
    int k = -1;
    for (int i = 0; i < cypherText.size() - 2; ++i)
    {
        if (cypherText[i] == 'H' and cypherText[i + 1] == 'J' and cypherText[i + 2] == 'V')
        {
            ++k;
            dist_from_start[k] = i;
            std::cout << "dist_from_start: " << dist_from_start[k] << std::endl; 
        }
    }
    std::cout << std::endl; 

// oraz odległości pomiędzy kolejnymi wystąpieniami ciągu i ich NWD:
    std::vector<int> dist;
    dist.resize(4);
    for (int i = 0; i < dist.size(); ++i)
    {
        dist[i] = dist_from_start[i + 1] - dist_from_start[i] ;
        std::cout << "dist: " << dist[i] << std::endl;
        if (i > 0)
        {
           std::cout << "gcd: " << std::gcd(dist[i], dist[i - 1]) << std::endl; 
        }
    }
    std::cout << std::endl;

// Dla każdych dwóch kolejnych odległości NWD wyniosło 6, dlatego długość klucza została założona jako 6. Potwierdzono ją przy pomocy analizy indeksu koincydencji:
    std::vector< std::vector<char> > matrix;
    for(int m = 1; m <= 6; ++m)
    {
        matrix.resize(m);
        for (int i = 0; i < m; ++i)
        {
            int size = cypherText.size() / m;
            matrix[i].resize(size);
            for (int j = 0; j < size; ++j)
            {
                matrix[i][j] = cypherText[j*m + i];
                //std::cout << matrix[i][j];
            }
            //std::cout << std::endl;
            std::cout << "i: " << i + 1 << ", Ic(yi): " << Ic(matrix[i]) << std::endl;
        }
        std::cout << std::endl;
    }
    //m=6

// Na koniec należało znaleźć klucz sprawdzając dla jakich liter przesunięty rozkład prawdopodobieństwa będzie bliski prawdopodobieństwu liter w języku angielskim:
    std::vector<double> p = {0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015, 
        0.0077, 0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.06, 0.063, 0.091, 0.028, 0.0098, 0.024, 0.0015, 0.02, 0.00074};
    int m = 6;
    int nprim = cypherText.size() / m;
    std::string key = "";
    std::cout << "Mg" << std::endl;
    for (int i = 0; i < m; ++i)
    {
        double Mg = 0;
        std::vector<int> f;
        f.resize(26);
        for (int k = 0; k < matrix[i].size(); ++k)
        {
            ++f[matrix[i][k] - 'A'];
        }
        double maxMg = 0;
        int maxIdx = 0;
        for (int g = 0; g < 26; ++g)
        {
            Mg = 0;
            for (int j = 0; j < 26; ++j)
            {
                Mg += (p[j] * f[(j + g) % 26]) / nprim;
            }
            std::cout << Mg << " ";
            if (Mg > maxMg)
            {
                maxMg = Mg;
                maxIdx = g;
            }
        }
        key += 'A' + maxIdx;
        std::cout << std::endl << std::endl;
    }
    
    std::cout << "key: " << key << std::endl;
    decypher(cypherText, key);
    string plaintext = cypherText;
    std::cout << "plaintext: " << plaintext << std::endl;
}