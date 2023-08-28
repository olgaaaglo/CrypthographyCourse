#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;
//-1 1 -1

int power2(int m)
{
    int count = 0;
    while (m > 1)
    {
        if (m % 2 == 0)
        {
            ++count;
            m /= 2;
        }
        else
        {
            break;
        }
    }

    return count;
}

void fun4(int& m, int& n, int& sign)
{
    int temp = m;
    m = n;
    n = temp;

    if (m % 4 == 3 and n % 4 == 3)
    {
        sign *= -1;
    }
}

void fun1(int& m, int& n)
{
    if (n > 0 and n % 2 == 1)
    {
        m = m % n;
    }
}

void fun3(int& m, int& n, int& t, int& k)
{
    if (n > 0 and n % 2 == 1)
    {
        k = power2(m);
        t = m / pow(2, k);
    }
}

void fun2(int& m, int& n, int& sign, int& t, int& k)
{
    if (t % 2 == 1 and n > 0 and n % 2 == 1)
    {
        if (n % 8 == 1 or n % 8 == 7)
        {
            m = t;
        }
        else if (n % 8 == 3 or n % 8 == 5)
        {
            m = t;
            sign *= pow(-1, k);
        }
    }
}

void Jacobi(int m, int n)
{
    int sign = 1;
    while(m != 1 and m != -1)
    {
        fun4(m, n, sign);
        fun1(m, n);

        int t = 0, k = 0;
        fun3(m, n, t, k);
        fun2(m, n, sign, t, k);
    }

    cout << sign * m << endl;
}

int main()
{
    Jacobi(610, 987);
    Jacobi(20964, 1987);
    Jacobi(1234567, 11111111);
}