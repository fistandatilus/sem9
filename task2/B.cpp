#include <cstdio>
#include <vector>
#include <algorithm>

int main ()
{
    int n;
    scanf ("%d", &n);

    std::vector<std::pair<int, int>> a;
    a.resize (n);
    for (int i = 0; i < n; i++)
    {
        int cur;
        scanf ("%d", &cur);
        a[i] = {i, cur}; 
    }
    std::sort (a.begin (), a.end (), [] (std::pair<int, int> x, std::pair<int, int> y) {return x.second < y.second;});
    int prev = 0;
    for (auto &cur : a)
    {
        int &d = cur.second;
        if (d <= prev)
            d = prev + 1;
        prev = d;
    }
    std::sort (a.begin (), a.end ());
    for (auto cur : a)
    {
        printf ("%d ", cur.second);
    }
    printf ("\n");

    return 0;
}
