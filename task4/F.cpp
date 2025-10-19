#include <cstdio>
#include <vector>
#include <algorithm>

template <typename T>
T gcd(T a, T b)
{
    while (b != 0)
    {
        T c = a%b;
        a = b;
        b = c;
    }
    return a;
}

template <typename T>
T first_divisor(T a)
{
    for (T i = 2; i * i <= a; i++)
    {
        if (a%i == 0)
            return i;
    }
    return a;
}

template <typename T>
T pow_mod(T a, T k, T p)
{
    T prod = a;
    T res = 1;
    while (k)
    {
        if (k & 1)
            res = (res * prod) % p;
        k = k >> 1;
        prod = (prod * prod) % p;
    }
    return res;
}

int main ()
{
    int n, q;
    scanf ("%d%d", &n, &q);
    std::vector<unsigned long long> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lld", &a[i]);
    }
    std::sort (a.begin(), a.end());
    for (int i = 0; i < q; i++)
    {
        unsigned long long x;
        scanf ("%lld", &x);
        unsigned long long int c = 0;
        for (int j = 0; j < n; j++)
        {
            c = gcd(x + a[j], c);
        }
        printf ("%lld ", c);
    }
    printf ("\n");
    return 0;
}

