#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#define INF 1000000000000

std::vector<long long int> data;
std::vector<long long int> p;

void push (size_t v, size_t L, size_t R)
{
    data[v] += p[v];
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
    data[v] = std::min (data[2 * v], data[2 * v + 1]);
}

long long int get (size_t v, size_t L, size_t R, size_t l, size_t r)
{
    push (v, L, R);
    if (L >= r || l >= R)
        return INF;
    if (l <= L && R <= r)
    {
        return data[v];
    }
    return std::min (get (2 * v    ,           L, (L + R) / 2, l, r), 
                     get (2 * v + 1, (L + R) / 2,           R, l, r));
}


int main ()
{
    long long int n;
    scanf ("%lld", &n);

    data = std::vector<long long int>(4*n, 0);
    p    = std::vector<long long int>(4*n, 0);

    for (long long int i = 0; i < n; i++)
    {
        long long int cur;
        scanf ("%lld", &cur);
        update (1, 0, n, i, i+1, cur);
    }

    long long int q;
    scanf ("%lld", &q);
    for (long long int tt = 0; tt < q; tt++)
    {
        std::string line;
        std::getline (std::cin, line);
        std::istringstream iss(line);
        long long int l, r, v;
        if (!(iss >> l && iss >> r))
        {
            tt--;
            continue;
        }
        if (iss >> v) //add
        {
            if (l <= r)
            {
                update (1, 0, n, l, r + 1, v);
            }
            else
            {
                update (1, 0, n, l, n, v);
                update (1, 0, n, 0, r + 1, v);
            }
        }
        else
        {
            long long int ans;
            if (l <= r)
            {
                ans = get (1, 0, n, l, r + 1);
            }
            else
            {
                long long int ansl = get (1, 0, n, l, n); 
                long long int ansr = get (1, 0, n, 0, r + 1);
                ans = std::min (ansl, ansr);
            }
            printf ("%lld\n", ans);
        }
    }
    return 0;
}
