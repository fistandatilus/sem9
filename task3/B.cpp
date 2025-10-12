#include <cstdio>
#include <vector>
#include <algorithm>

int main ()
{
    int n;
    scanf ("%d", &n);

    std::vector<int> a(n);
    for (int &c: a)
        scanf ("%d", &c);
    std::sort (a.begin (), a.end ());
    int m;
    scanf ("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int xl, xr;
        scanf ("%d%d", &xl, &xr);
        if (xl >= xr)
        {
            printf("0\n");
            continue;
        }

        int l = -1, r = n;
        while (r - l > 1)
        {
            int m = (r + l) / 2;

            if (a[m] < xl)
                l = m;
            else
                r = m;
        }
        if (r == n || a[r] > xr)
        {
            printf("0\n");
            continue;
        }
        int left = r;

        l = 0, r = n;
        while (r - l > 1)
        {
            int m = (r + l) / 2;

            if (a[m] > xr)
                r = m;
            else
                l = m;
        }
        printf("%lld\n", static_cast<long long int>(a[l]) - a[left]);
    }
    return 0;
}
