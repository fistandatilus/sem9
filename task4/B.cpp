#include <cstdio>
#include <vector>

int main ()
{
    long long int n, k;
    scanf ("%lld%lld", &n, &k);
    std::vector<long long int> divs;
    int amount = 0;
    long long int i;
    for (i = 1; i*i <= n; i++)
    {
        if (n%i == 0)
        {
            amount++;
            divs.push_back (i);
        }
        if (amount == k)
        {
            printf ("%lld\n", i);
            return 0;
        }
    }
    i--;
    if (i*i == n)
    {
        if (k > 2 * amount - 1)
            printf ("-1\n");
        else
            printf ("%lld\n", n / divs[2 * amount - k - 1]);
    }
    else
    {
        if (k > 2 * amount)
            printf ("-1\n");
        else
            printf ("%lld\n", n / divs[2 * amount - k]);
    }
    return 0;
}
