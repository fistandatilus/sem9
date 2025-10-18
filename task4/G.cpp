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
    a = a % p;
    k = k % (p - 1);
    T prod = a;
    T res = 1;
    while (k)
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
    const int           scope  = 1000000;
    const long long int modulo = 1000000007;
    int q;
    scanf ("%d", &q);
    std::vector<int> first_divisors(scope + 1, 0);
    first_divisors[1] = 1;
    for (int i = 2; i <= scope; i++)
        if (!first_divisors[i])
            for (int j = i; j <= scope; j += i)
                if (!first_divisors[j])
                    first_divisors[j] = i;
    int count[20]; // 20 > log_2 (scope)
    for (int i = 0; i < q; i++)
    {
        int x, k, prev;
        scanf ("%d%d", &x, &k);
        prev = first_divisors[x];
        int divs = 0;
        count[0] = 0;
        while (x > 1)
        {
            int cur = first_divisors[x];
            x = x / cur;
            if (prev == cur)
                count[divs]++;
            else
            {
                prev = cur;
                divs++;
                count[divs] = 1;
            }
        }
        divs++;
        long long int top = 1;
        long long int bottom = 1;
        for (int i = 0; i < divs; i++)
        {
            for (long long int j = 1; j <= count[i]; j++)
            {
                top = (top * (k - 1 + j)) % modulo;
                bottom = (bottom * j) % modulo;
            }
        }
        long long int res = (top * pow_mod(bottom, modulo - 2, modulo)) % modulo;
        res = (res * pow_mod(2ll, (long long int)(k - 1), modulo) % modulo);
        printf ("%lld\n", res);

    }
    return 0;
}

