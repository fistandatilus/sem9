#include <cstdio>
#include <vector>
#include <algorithm>

bool comp (const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.second < b.second;
}

int main ()
{
    int t;
    scanf ("%d", &t);
    std::vector<std::pair<int, int>> values;
    values.resize (1024 * 1024 * 4);
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        scanf ("%d", &n);
        values.resize(n);
        for (int i = 0; i < n; i++)
        {
            values[i].first = i + 1;
            scanf ("%d", &values[i].second);
        }
        std::sort (values.begin (), values.end (), comp);

        int count = 0;
        int prev = values[0].second;
        values[0].second = 0;
        for (int i = 1; i < n; i++)
        {
            int &cur = values[i].second;
            if (cur == prev)
            {
                cur = 0;
                continue;
            }
            if (cur < prev)
            {
                count++;
                cur = prev - cur;
            }
            else
            {
                int cur_t = cur;
                if (cur % prev != 0)
                {
                    count++;
                    cur = prev - cur%prev;
                }
                else
                    cur = 0;
                prev = cur_t + cur;
            }
        }
        printf ("%d\n", count);
        for (int i = 1; i < n; i++)
        {
            if (values[i].second)
                printf ("%d %d\n", values[i].first, values[i].second);

        }
    }
    return 0;
}
