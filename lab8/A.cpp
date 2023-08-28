// g++ A.cpp -lcrypto -lssl
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <openssl/evp.h>
#include <cstring>
using namespace std;

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
    const char* s1 = "The quick brown fox jumps over the lazy dog";
    const char* s2 = "The quick brown fox jumps over the lazy cog";
    const char* s3 = "";

    //md4 dziala tylko na taurusie
    printf("Funkcja skrotu MD4\n");
    getDigest("MD4", s1);
    getDigest("MD4", s2);
    getDigest("MD4", s3);
    printf("\n");

    printf("Funkcja skrotu MD5\n");
    getDigest("MD5", s1);
    getDigest("MD5", s2);
    getDigest("MD5", s3);
    printf("\n");

    printf("Funkcja skrotu SHA-1\n");
    getDigest("SHA1", s1);
    getDigest("SHA1", s2);
    getDigest("SHA1", s3);
    printf("\n");

    printf("Funkcja skrotu SHA224\n");
    getDigest("SHA224", s1);
    getDigest("SHA224", s2);
    getDigest("SHA224", s3);
    printf("\n");

    printf("Funkcje skrotu SHA256, SHA384, SHA512\n");
    getDigest("SHA256", s3);
    getDigest("SHA384", s3);
    getDigest("SHA512", s3);
    printf("\n");
}