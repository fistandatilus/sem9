#include <cstdio>

int main ()
{
    int n, x, y;
    scanf ("%d%d%d", &n, &x, &y);
    if (x > y)
    {
        printf ("%d\n", n);
        return 0;
    }
    int killable = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &cur);
        if (cur <= x)
            killable++;
    }
    printf ("%d\n", killable / 2 + killable % 2);
    return 0;
}
