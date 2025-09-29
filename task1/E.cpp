#include <cstdio>

int main ()
{
    int n, r1, r2, l1, l2;
    scanf ("%d%d%d%d%d", &n, &r1, &r2, &l1, &l2);
    int result = 2 * (l1 - l2) + n * (r1 - r2);
    if (result < 0)
        printf ("First\n");
    else if (result == 0)
        printf ("Friendship\n");
    else
        printf ("Second\n");
    return 0;
}
