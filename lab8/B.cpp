#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <openssl/evp.h>
#include <cstring>
#include <sstream>
#include <string.h>
using namespace std;

string getDigest(const char* func, const char* s)
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

    string ret = "";
    for (int j = 0; j < md_len; ++j)
    {
        ret += md_value[j];
    }
    
    return ret;
}

string getString(string m)
{
    string out = "";
    for (int i = 0; i < m.size(); i += 2)
    {
        string hex = "";
        hex += m[i];
        hex += m[i+1];
        
        int dec;
        std::stringstream stream;
        stream << hex;
        stream >> std::hex >> dec;

        out += dec;
    }

    return out;
}

void checkCollision(string m1, string m2)
{
    string out1 = getDigest("MD4", getString(m1).c_str());
    string out2 = getDigest("MD4", getString(m2).c_str());
    if (out1.compare(out2) == 0)
        cout << "Kolizja!" << endl;
    else 
        cout << "Brak kolizji!" << endl;
    printf("\n");
}

int main()
{
    string m1 = "839c7a4d7a92cb5678a5d5b9eea5a7573c8a74deb366c3dc20a083b69f5d2a3bb3719dc69891e9f95e809fd7e8b23ba6318edd45e51fe39708bf9427e9c3e8b9";

    string m2 = "839c7a4d7a92cbd678a5d529eea5a7573c8a74deb366c3dc20a083b69f5d2a3bb3719dc69891e9f95e809fd7e8b23ba6318edc45e51fe39708bf9427e9c3e8b9";

    string m3 = "a6af943ce36f0cf4adcb12bef7f0dc1f526dd914bd3da3cafde14467ab129e640b4c41819915cb43db752155ae4b895fc71b9b0d384d06ef3118bbc643ae6384";

    string m4 = "a6af943ce36f0c74adcb122ef7f0dc1f526dd914bd3da3cafde14467ab129e640b4c41819915cb43db752155ae4b895fc71b9a0d384d06ef3118bbc643ae6384";

    string m5 = "76931fac9dab2b36c248b87d6ae33f9a62d7183a5d5789e4b2d6b441e2411dc709e111c7e1e7acb6f8cac0bb2fc4c8bc2ae3baaab9165cc458e199cb89f51b13";

    string m6 = "76931fac9dab2b36d248b87d6af33f9a62d7183a5d5789e4b2d6b441e2411dc709e111c7e1e7acb6f8cac0bb2fc4c8bc2ae3baaab9265cc458e199cb89f51b13";

    checkCollision(m1, m2);
    checkCollision(m3, m4);
    checkCollision(m5, m6);
}