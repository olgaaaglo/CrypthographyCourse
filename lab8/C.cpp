#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <bitset>
#include <openssl/evp.h>
using namespace std;

vector<int> decToBin(long long dec, int len = 8)
{
    vector<int> bin;
    while (dec > 0)
    {
        bin.push_back(dec % 2);
        dec /= 2;
    }
    while (bin.size() < len)
    {
        bin.push_back(0);
    }
    vector<int> bin_ret;
    for (int i = bin.size() - 1; i >= 0; --i)
    {
        bin_ret.push_back(bin[i]);
    }
    return bin_ret;
}

void printVec(vector<int> x)
{
    int i = 0;
    for (int j = 0; j < x.size(); ++j)
    {
        cout << x[j];
        ++i;
        if (i % 4 == 0)
        {
            cout << " ";
        }
    }
    cout << endl;
}

vector<int> xorVec(vector<int> a, vector<int> b)
{
    std::transform(a.begin(), a.end(), b.begin(), a.begin(), std::bit_xor<uint8_t>());
    return a;
}

long long binToDec(vector<int> bin)
{
    long long dec = 0;
    int j = 0;
    for (int i = bin.size() - 1; i >= 0; --i)
    {
        dec += bin[i] * std::pow(2, j++);
    }

    return dec;
}

string SHA1(string m1)
{
    int l1 = m1.size();
    
    long long h0 = 0x67452301;
    long long h1 = 0xEFCDAB89;
    long long h2 = 0x98BADCFE;
    long long h3 = 0x10325476;
    long long h4 = 0xC3D2E1F0;
    
    long long x32 = 4294967296;

    vector<int> bin;
    for (int i = 0; i < m1.size(); ++i)
    {
        vector<int> bin_i = decToBin(m1[i]);
        bin.insert(bin.end(), bin_i.begin(), bin_i.end());
    }

    bin.push_back(1);

    int nr_zeros = 448 - bin.size();
    while (nr_zeros < 0)
    {
        nr_zeros += 512;
    }

    for (int i = 0; i < nr_zeros; ++i)
    {
        bin.push_back(0);
    }

    vector<int> bin_length = decToBin(l1);

    while (bin_length.size() < 64)
    {
        bin_length.insert(bin_length.begin(), 0);
    }
    
    bin.insert(bin.end(), bin_length.begin(), bin_length.end());

    for (int i = 0; i < bin.size(); i += 512)
    {
        vector<vector<int>> w;
        for (int j = i; j < i + 512; j += 32)
        {
            vector<int> w1;
            for (int k = j; k < j + 32; ++k)
            {
                w1.push_back(bin[k]);
            }
            w.push_back(w1);
        }

        for (int n = 16; n < 80; ++n)
        {
            vector<int> word = xorVec(xorVec(xorVec(w[n-3], w[n-8]), w[n-14]), w[n-16]);
            int bits = 1;
            word = decToBin((binToDec(word) << bits) % x32 | (binToDec(word) >> 32-bits), 32);
            w.push_back(word);
        }

        long long a = h0;
        long long b = h1;
        long long c = h2;
        long long d = h3;
        long long e = h4;
        long long f, k;

        for (int n = 0; n < 80; ++n)
        {
            if (0 <= n and n <= 19)
            {
                f = (b & c) | ((!b) & d);
                k = 0x5A827999;
            }
            else if (20 <= n and n <= 39)
            {
                f = b ^ c ^ d;
                k = 0x6ED9EBA1;
            }
            else if (40 <= n and n <= 59)
            {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            }
            else if (60 <= n and n <= 79)
            {
                f = b ^ c ^ d;
                k = 0xCA62C1D6;
            }
        
            long long temp = ((((((a << 5) % x32 | (a >> 32-5)) + f) % x32 + e) % x32 + k) % x32 + binToDec(w[n])) % x32;
            e = d;
            d = c;
            c = (b << 30) % x32 | (b >> 32-30);
            b = a;
            a = temp;
        }

        h0 =(h0 + a) % x32;
        h1 = (h1 + b) % x32;
        h2 = (h2 + c) % x32;
        h3 = (h3 + d) % x32;
        h4 = (h4 + e) % x32;
    }
    string result = "";
    vector<long long> h = {h0, h1, h2, h3, h4};

    std::stringstream ss;
    for (int i = 0; i < h.size(); ++i)
    {
        ss << hex << h[i];
    }
    result = ss.str();

    return result;
}

void getDigest(const char* func, const char* s)
{
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len, i;

    md = EVP_get_digestbyname(func);
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, s, strlen(s));
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_free(mdctx);

    printf("Digest is: ");
    for (i = 0; i < md_len; i++)
        printf("%02x", md_value[i]);
    printf("\n");
}

int main()
{
    string m1 = "abc";
    cout << "Result for 'abc' " << SHA1(m1) << endl;

    string m2 = "a";
    cout << "Result for 'a' " << SHA1(m2) << endl;

    string m3 = "";
    cout << "Result for '' " << SHA1(m3) << endl;

    getDigest("MD4", m3.c_str());
}