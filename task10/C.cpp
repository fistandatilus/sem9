#include <cstdio>
#include <cstring>
#include <vector>

std::vector<std::pair<int, int>> data;
//first  -- surplus
//second -- deficit
//c = 1 if (

std::pair<int, int> merge(std::pair<int, int> a, std::pair<int, int> b)
{
    int delta = a.first - b.second;
    return {std::max(delta, 0) + b.first, a.second + std::max(-delta, 0)};
}

void add (int v, int l, int r, int i, int c)
{
    if (i < l || r <= i)
        return;
    if (r - l == 1)
    {
        data[v].first = c;
        data[v].second = (1 - c);
        return;
    }
    add (2*v, l, (l + r)/2, i, c);
    add (2*v + 1, (l + r)/2, r, i, c);
    data[v] = merge (data[2*v], data[2*v + 1]);
}

std::pair<int, int> get (int v, int l, int r, int L, int R)
{
    if (r <= L || R <= l)
        return {0, 0};
    if (L <= l && r <= R)
    {
        return data[v];
    }
    return merge(get (2*v, l, (l + r)/2, L, R), get (2*v + 1, (l + r)/2, r, L, R));
}

int main ()
{

    char string[1000001];
    scanf ("%s", string);
    int n = strlen (string);
    data.resize (4 * n);

    for (int i = 0; i < n; i++)
    {
        int c = string[i] == '(' ? 1 : 0;
        add (1, 1, n + 1, i + 1, c);
    }

    int q;
    scanf ("%d", &q);
    for (int tt = 0; tt < q; tt++)
    {
        int l, r;
        scanf ("%d%d", &l, &r);
        auto res = get (1, 1, n + 1, l, r + 1);
        int ans = (r - l + 1) - res.first - res.second;
        printf ("%d\n", ans);
    }
    return 0;
}
