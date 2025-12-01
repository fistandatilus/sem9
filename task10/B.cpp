#include <cstdio>
#include <vector>

#define INF 1000000000000

std::vector<long long int> data;
std::vector<long long int> p;

void push (size_t v, size_t L, size_t R)
{
    data[v] += p[v] * (R - L);
    if (R - L > 1)
    {
        p[2*v] += p[v];
        p[2*v + 1] += p[v];
    }
    p[v] = 0;
}

void update (size_t v, size_t L, size_t R, size_t l, size_t r, long long int d)
{
    push (v, L, R);
    if (L >= r || l >= R)
        return;
    if (l <= L && R <= r)
    {
        p[v] += d;
        push (v, L, R);
        return;
    }
    update (2 * v    ,           L, (R + L) / 2, l, r, d);
    update (2 * v + 1, (R + L) / 2,           R, l, r, d);
    data[v] = data[2 * v] + data[2 * v + 1];
}

long long int get (size_t v, size_t L, size_t R, size_t l, size_t r)
{
    push (v, L, R);
    if (L >= r || l >= R)
        return 0;
    if (l <= L && R <= r)
    {
        return data[v];
    }
    return get   (2 * v    ,           L, (L + R) / 2, l, r)
           + get (2 * v + 1, (L + R) / 2,           R, l, r);
}


int main ()
{
    long long int n;
    scanf ("%lld", &n);

    data = std::vector<long long int>(4*n, 0);
    p    = std::vector<long long int>(4*n, 0);

    std::vector<long long int> sums(n);

    for (auto &cur : sums)
    {
        scanf ("%lld", &cur);
    }

    for (long long int i = 1; i < n; i++)
    {
        update (1, 1, n + 1, i + 1, n + 1, i);
    }

    for (long long int i = n; i > 0; i--)
    {
        int cur = sums[i - 1];

        long long int l = 1, r = n + 1;
        while (r - l > 1)
        {
            long long int m = (r + l)/2;
            long long int vm = get (1, 1, n + 1, m, m + 1);
            if (vm <= cur)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        sums[i - 1] = l;
        update (1, 1, n + 1, l + 1, n + 1, -l);
    }

    for (auto cur : sums)
        printf ("%lld ", cur);
    printf ("\n");
    return 0;
}
