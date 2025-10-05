#include <cstdio>
#include <vector>
#include <algorithm>

int main ()
{
    int n;
    scanf ("%d", &n);
    std::vector<int> h(n);
    for (int &c : h)
        scanf ("%d", &c);
    std::sort (h.begin (), h.end ());
    int best = n;
    for (int i = 0; i < n; i++)
    {
        int cur = h[i] + n - i - 1;
        if (cur < best)
            best = cur;
    }
    printf ("%d\n", best);
    return 0;
}
