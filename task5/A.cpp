#include <cstdio>
#include <vector>
#include <algorithm>

int main ()
{
    int n;
    scanf ("%d\n", &n);
    char buf[150002];

    std::vector<std::pair<char, int>> s1 (n), s2 (n);
    scanf ("%s", buf);
    for (int i = 1; i <= n; i++)
    {
        s1[i-1].first = buf[i-1];
        s1[i-1].second = i;
    }
    scanf ("%s", buf);
    for (int i = 1; i <= n; i++)
    {
        s2[i-1].first = buf[i-1];
        s2[i-1].second = i;
    }

    std::sort (s1.begin (), s1.end ());
    std::sort (s2.begin (), s2.end ());

    std::vector<std::pair<int, int>> pairs;
    int i = 0, j = 0;
    for (; i < n && s1[i].first == '?'; i++);
    int q1 = i;
    for (; j < n && s2[j].first == '?'; j++);
    int q2 = j;
    for (; i < n && j < n; i++)
    {
        auto [c1, i1] = s1[i];
        auto [c2, i2] = s2[j];
        if (c1 == c2)
        {
            pairs.push_back ({i1, i2});
            j++;
        }
        else if (c1 < c2)
        {
            if (q2 > 0)
            {
                q2--;
                pairs.push_back ({i1, s2[q2].second});
            }
        }
        else
        {
            if (q1 > 0)
            {
                q1--;
                pairs.push_back ({s1[q1].second, i2});
            }
            i--;
            j++;
        }
    }
    for (; j < n && q1 > 0; j++)
    {
        q1--;
        pairs.push_back ({s1[q1].second, s2[j].second});
    }
    for (; i < n && q2 > 0; i++)
    {
        q2--;
        pairs.push_back ({s1[i].second, s2[q2].second});
    }
    while (q1 > 0 && q2 > 0)
    {
        q1--;
        q2--;
        pairs.push_back ({s1[q1].second, s2[q2].second});
    }

    printf ("%ld\n", pairs.size ());
    for (auto [i1, i2] : pairs)
    {
        printf ("%d %d\n", i1, i2);
    }

    return 0;
}
