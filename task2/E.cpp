#include <cstdio>
#include <vector>
#include <algorithm>

int main ()
{
    int t;
    scanf ("%d", &t);
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        scanf ("%d", &n);
        std::vector<int> x(n);
        std::vector<int> y(n);
        for (int i = 0; i < n; i++)
            scanf ("%d%d", &x[i], &y[i]);
        if (n%2 == 1)
        {
            printf ("1\n");
            continue;
        }
        std::sort (x.begin (), x.end ());
        std::sort (y.begin (), y.end ());
        int middle = n/2;
        long long int retx = (x[middle] == x[middle - 1]) ? 1 : (x[middle] - x[middle - 1] + 1);
        long long int rety = (y[middle] == y[middle - 1]) ? 1 : (y[middle] - y[middle - 1] + 1);
        printf ("%lld\n", retx * rety);


    }
    return 0;
}
