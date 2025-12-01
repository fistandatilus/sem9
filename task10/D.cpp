#include <cstdio>
#include <cstring>
#include <cstdint>
#include <vector>


void add (std::vector<unsigned long> &data, unsigned long limit, unsigned long v, unsigned long l, unsigned long r, unsigned long i, unsigned long c)
{
    if (i < l || r <= i)
        return;
    if (r - l == 1)
    {
        data[v] = std::min (limit, data[v] + c);
        return;
    }
    add (data, limit, 2*v, l, (l + r)/2, i, c);
    add (data, limit, 2*v + 1, (l + r)/2, r, i, c);
    data[v] = data[2*v] + data[2*v + 1];
}

unsigned long get (std::vector<unsigned long> &data, unsigned long v, unsigned long l, unsigned long r, unsigned long L, unsigned long R)
{
    if (r <= L || R <= l)
        return {};
    if (L <= l && r <= R)
    {
        return data[v];
    }
    return get (data, 2*v, l, (l + r)/2, L, R) + get (data, 2*v + 1, (l + r)/2, r, L, R);
}

int main ()
{
    unsigned long n, k, a, b, q;
    scanf ("%lu%lu%lu%lu%lu", &n, &k, &a, &b, &q);

    std::vector<unsigned long> data_a(4 * n, 0);
    std::vector<unsigned long> data_b(4 * n, 0);

    for (unsigned long tt = 0; tt < q; tt++)
    {
        unsigned long type;
        scanf ("%lu", &type);
        if (type == 1)
        {
            unsigned long d, r;
            scanf ("%lu %lu", &d, &r);
            add (data_a, a, 1, 1, n + 1, d, r);
            add (data_b, b, 1, 1, n + 1, d, r);
        }
        else
        {
            unsigned long p;
            scanf ("%lu", &p);
            unsigned long ans = get (data_b, 1, 1, n + 1, 1, p);
            ans += get (data_a, 1, 1, n + 1, p + k, n + 1);
            printf ("%lu\n", ans);
        }
    }
    return 0;
}
