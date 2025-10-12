#include <cstdio>
#include <vector>
#include <algorithm>

int main ()
{
    int t;
    scanf ("%d", &t);
    for (int tt = 0; tt < t; tt++)
    {
        int n, k;
        scanf ("%d%d", &n, &k);
        std::vector<int> a(n);
        for (int &c: a)
            scanf ("%d", &c);
        std::sort (a.begin (), a.end ());
        int l = -1, r = n, i;
        for (i = 0; i < n - 1; i++)
        {
            int l = i; r = n;
            while (r - l > 1)
            {
                int m = (r + l) / 2;
                if (a[m] - a[i] > k)
                    r = m;
                else
                    l = m;
            }
            if (a[l] - a[i] == k)
                break;
        }
        if (i == n - 1)
            printf ("NO\n");
        else
            printf ("YES\n");
    }
    return 0;
}
