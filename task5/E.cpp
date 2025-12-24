#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

typedef long long int i64;

int main ()
{
    int n;
    scanf ("%d", &n);

    std::vector<int> a (n);

    for (auto &cur : a)
        scanf ("%d", &cur);

    std::sort (a.begin (), a.end ());

    int prev = a[0] - 1;
    int max = 0;
    int count = 0;
    for (auto cur : a)
    {
        if (cur == prev)
        {
            count++;
            if (count > max)
                max = count;
        }
        else
        {
            count = 0;
        }
        prev = cur;
    }

    printf ("%d\n", n - max - 1);

    return 0;
}
