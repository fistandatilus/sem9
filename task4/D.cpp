#include <cstdio>
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
    for (int i = 0; i < sizeof(T); i++)
    {
        if (k & 1)
            res = (res * prod) % p;
        prod = (prod * prod) % p;
        k = k >> 1;
    }
    return res;
}

int main ()
{
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        long long int a, b, p;
        scanf ("%lld%lld%lld", &a, &b, &p);
        a = a%p;
        if (a == 0)
        {
            if (b%p == 0)
                printf("Any\n");
            else
                printf("-1\n");
            continue;
        }
        long long int res = (pow_mod(a, p - 2, p) * (-b)) % p;
        if (res < 0)
            res += p;
        printf ("%lld\n", res);
    }
    return 0;
}

