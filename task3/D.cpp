#include <cstdio>
#include <vector>

int main ()
{
    int n, k;
    scanf ("%d%d", &n, &k);
    std::vector<int> a(n);
    std::vector<int> b(k);
    for (int &c : a)
        scanf ("%d", &c);
    for (int &c : b)
        scanf ("%d", &c);
    for (int i = 0; i < k; i++)
    {
        int l = -1, r = n;
        while (r - l > 1)
        {
            int m = (r + l) / 2;
            if (a[m] <= b[i])
                l = m;
            else 
                r = m;
        }
        if (l == -1)
            printf ("%d\n", a[0]);
        else if (l == n - 1 || b[i] - a[l] <= a[l + 1] - b[i])
            printf ("%d\n", a[l]);
        else
            printf ("%d\n", a[l + 1]);
    }
    return 0;
}
