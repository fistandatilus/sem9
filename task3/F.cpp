#include <cstdio>
#include <cmath>
#include <vector>

int main ()
{
    int t;
    scanf ("%d", &t);
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        scanf ("%d", &n);
        std::vector<int> x(n), t(n);
        for (int &c : x)
            scanf ("%d", &c);
        for (int &c : t)
            scanf ("%d", &c);
        double mx = x[0];
        double mt = t[0];
        for (int i = 1; i < n; i++)
        {
            if (mt - t[i] > fabs(mx - x[i]))
                continue;
            if (t[i] - mt > fabs(mx - x[i]))
            {
                mx = x[i];
                mt = t[i];
                continue;
            }
            if (mx < x[i])
            {
                mx = (mx + x[i] + t[i] - mt) / 2;
                mt = t[i] + x[i] - mx;
            }
            else
            {
                mx = (mx + x[i] + mt - t[i]) / 2;
                mt = t[i] + mx - x[i];
            }
        }
        printf ("%lf\n", mx);
    }
    return 0;
}
