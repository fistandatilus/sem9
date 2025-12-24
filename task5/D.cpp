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
        int n, m;
        scanf ("%d%d", &n, &m);
         std::vector<std::pair<i64, i64>> values(m);
        for (int i = 0; i < m; i++)
        {
            scanf ("%lld %lld", &values[i].first, &values[i].second);
        }
        std::sort(values.begin (), values.end (), [] (std::pair<i64, i64> x, std::pair<i64, i64> y) {return x.first == y.first ? x.second > y.second : x.first > y.first;});
        
        std::vector<i64> asums (m);
        i64 tot = 0;
        for (int i = 0; i < m; i++)
        {
            tot += values[i].first;
            asums[i] = tot;
        }

        i64 max = 0;
        for (int i = 0; i < m; i++)
        {
            auto [cura, curb] = values[i];
            const auto &res_it = std::lower_bound (values.begin (), values.end (), curb, [] (std::pair<i64, i64> x, i64 y) {return x.first > y;});
            
            i64 end = std::abs (std::distance (values.begin (), res_it)) - 1;
            i64 res = 0;
            if (end >= n)
            {
                res = asums[n-1];
            }
            else
            {
                if (end < i)
                {
                    res = (end >= 0 ? asums[end] : 0) + cura + (n - end - 2) * curb;
                }
                else
                {
                    res = asums[end] + (n - end - 1) * curb;
                }
            }

            if (res > max)
                max = res;
        }
        printf ("%lld\n", max);
    }
    return 0;
}
