#include <cstdio>
#include <vector>
#include <algorithm>

struct minmax_queue
{
    std::vector<std::pair<int, int>> in;
    std::vector<std::pair<int, int>> out;
    std::vector<std::pair<int, int>> inmm;
    std::vector<std::pair<int, int>> outmm;

    void push (int yl, int yt)
    {
        in.push_back ({yl, yt});
        if (inmm.empty ())
        {
            inmm.push_back ({yl, yt});
            return;
        }
        int min = inmm.back ().first;
        int max = inmm.back ().second;
        inmm.push_back ({std::min(yl, min), std::max(yt, max)});
    }

    void pop ()
    {
        if (out.empty ())
            while (!in.empty ())
            {
                inmm.pop_back ();
                int yl = in.back ().first;
                int yt = in.back ().second;
                in.pop_back ();
                out.push_back ({yl, yt});

                if (outmm.empty ())
                {
                    outmm.push_back ({yl, yt});
                }
                else
                {
                    int min = outmm.back ().first;
                    int max = outmm.back ().second;
                    outmm.push_back ({std::min(yl, min), std::max(yt, max)});
                }
            }

        if (!out.empty ())
        {
            out.pop_back ();
            outmm.pop_back ();
            return;
        }
    }
    int time ()
    {
        if (!in.empty () && !out.empty ())
            return std::max (inmm.back ().second, outmm.back ().second) - std::min (inmm.back ().first, outmm.back ().first);
        if (!in.empty ())
            return inmm.back().second - inmm.back().first;
        if (!out.empty ())
            return outmm.back().second - outmm.back().first;
        return -1;
    }
};

int main ()
{
    int n, d;
    scanf ("%d%d", &n, &d);

    std::vector<std::pair<int, std::pair<int, int>>> coords(n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &coords[i].first, &coords[i].second.first);
    std::sort (coords.begin (), coords.end ());

    int offset = 0;
    int prevx = coords[0].first;
    coords[0].second.second = coords[0].second.first;
    for (int i = 1; i < n; i++)
    {
        if (coords[i].first == prevx)
        {
            offset++;

            int cury = coords[i].second.first;
            if (coords[i - offset].second.first > cury)
                coords[i - offset].second.first = cury;
            if (coords[i - offset].second.second < cury)
                coords[i - offset].second.second = cury;
        }
        else
        {
            coords[i].second.second = coords[i].second.first;
            coords[i - offset] = coords[i];
        }
    }

    n -= offset;

    int res = coords[n - 1].first - coords[0].first + 1;

    int left = 0;
    int right = 0;
    minmax_queue q;
    for (; right < n; right++)
    {
        q.push (coords[right].second.first, coords[right].second.second);
        while (left <= right && q.time () >= d)
        {
            int dist = coords[right].first - coords[left].first;
            if (dist < res)
                res = dist;
            q.pop ();
            left++;
        }
        if (res == 0)
            break;
    }
    printf ("%d\n", res < coords[n - 1].first - coords[0].first + 1 ? res : -1);
    return 0;

}
