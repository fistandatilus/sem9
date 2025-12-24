#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

typedef long long int i64;

int main ()
{
    int t;
    scanf ("%d", &t);
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        scanf ("%d", &n);

        std::vector<int> a (n);

        for (auto &cur : a)
            scanf ("%d", &cur);

        std::vector<int> t;
        std::vector<int> b;

        for (int i = 0; i < n; i++)
        {
            char c;
            scanf ("%c", &c);
            if (c == 'R')
                t.push_back (a[i]);
            else if (c == 'B')
                b.push_back (a[i]);
            else
                i--;
        }
        int fail = false;
        std::sort (t.begin (), t.end ());
        std::sort (b.begin (), b.end ());
        for (int i = 0; i < t.size (); i++)
            if (t[i] > n - (int)t.size () + i + 1)
            {
                fail = true;
                break;
            }
        if (fail)
        {
            printf ("NO\n");
            continue;
        }
        for (int i = 0; i < b.size (); i++)
            if (b[i] < i + 1)
            {
                fail = true;
                break;
            }
        if (fail)
        {
            printf ("NO\n");
            continue;
        }
        printf ("YES\n");
    }
    return 0;
}
