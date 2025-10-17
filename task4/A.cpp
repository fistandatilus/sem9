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

int main ()
{
    unsigned long long int n;
    scanf ("%llu", &n);
    unsigned long long int c = 0;
    unsigned long long int pa, pb;
    for (int i = 0; i < n; i++)
    {
        unsigned long long int a, b;
        scanf ("%llu%llu", &a, &b);
        c = gcd (a * b, c);
        pa = a;
        pb = b;
        if (c == 1)
        {
            printf ("-1\n");
            return 0;
        }
    }
    unsigned long long int ca = gcd(pa, c);
    unsigned long long int cb = gcd(pb, c);
    if (ca == 1)
        c = cb;
    else if (cb == 1)
        c = ca;
    else
        c = std::min(ca, cb);

    printf ("%llu\n", first_divisor(c));
    return 0;
}

