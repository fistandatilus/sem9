#include <cstdio>
#include <vector>

int main ()
{
    int n, m;
    scanf ("%d%d", &n, &m);
    std::vector<bool> vals (m);
    std::vector<bool> prev_vals (m);
    for (int i = 0; i < m; i++)
    {
        vals[i] = false;
        prev_vals[i] = false;
    }

    for (int tt = 0; tt < n; tt++)
    {
        int cur;
        scanf ("%d", &cur);
        cur = cur%m;
        for (int i = 0; i < m; i++)
        {
            if (prev_vals[i])
            {
                vals[(i + cur)%m] = true;
            }
        }
        vals[cur] = true;
        if (vals[0])
        {
            printf ("YES\n");
            return 0;
        }
        for (int i = 0; i < m; i++)
            prev_vals[i] = vals[i];
    }
    printf ("NO\n");

    return 0;
}
