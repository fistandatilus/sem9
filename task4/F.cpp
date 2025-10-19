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
    unsigned long long a, c = 0;
    scanf ("%lld", &a);
    for (int i = 1; i < n; i++)
    {
        unsigned long long cur;
        scanf ("%lld", &cur);
        cur = cur < a ? (a - cur) : (cur - a);
        c = gcd (cur, c);
    }
    for (int i = 0; i < q; i++)
    {
        unsigned long long x;
        scanf ("%lld", &x);
        unsigned long long int res = 0;
            res = gcd(x + a, c);
        printf ("%lld ", res);
    }
    printf ("\n");
    return 0;
}

