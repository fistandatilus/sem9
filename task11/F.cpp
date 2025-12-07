#include <cstdio>
#include <vector>
#include <algorithm>

typedef int i32;
typedef unsigned int u32;
typedef long long int i64;
typedef unsigned long long int u64;

struct point
{
    i64 x = 0;
    i64 y = 0;
};

i64 operator* (point x, point y)
{
    return x.x * y.x + x.y * y.y;
}

i64 operator% (point x, point y)
{
    return x.x * y.y - x.y * y.x;
}

point operator+ (point x, point y)
{
    return {x.x + y.x, x.y + y.y};
}

point operator- (point x, point y)
{
    return {x.x - y.x, x.y - y.y};
}

bool operator== (point x, point y)
{
    return x.x == y.x && x.y == y.y;
}

bool cmp_angle (point x, point y)
{
    i64 angle = x%y;
    i64 size = x.x * x.x + x.y * x. y - y.x * y.x - y.y * y.y;
    return angle != 0 ? angle < 0 : size < 0;
}

bool cmp_xy (const point x, const point y)
{
    return x.x != y.x ? x.x < y.x : x.y < y.y;
}

bool cmp_yx (const point x, const point y)
{
    return x.y != y.y ? x.y < y.y : x.x < y.x;
}

typedef std::pair<point, int> point_ind;

bool cmp_xy (const point_ind &x, const point_ind &y)
{
    return cmp_xy (x.first, y.first);
}

bool cmp_yx (const point_ind &x, const point_ind &y)
{
    return cmp_yx (x.first, y.first);
}

bool cmp1(const point_ind &a_arg, const point_ind &b_arg)
{
    auto &a = a_arg.first;
    auto &b = b_arg.first;
    return a.x != b.x ? a.x > b.x : a.y > b.y;
}

bool cmp2(const point_ind &a, const point_ind &b)
{
    return a.second < b.second;
}

int main ()
{
    int n;
    scanf ("%d", &n);

    std::vector<point> data(n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lld %lld", &data[i].x, &data[i].y);
    }

    int m;
    scanf ("%d", &m);
    
    for (int i = 0; i < m; i++)
    {
        point cur;
        scanf ("%lld %lld", &cur.x, &cur.y);

        cur = cur - data[n-1];
        point left_vector = data[0] - data[n-1];
        point right_vector = data[n-2] - data[n-1];
        if (right_vector%cur <= 0 || left_vector%cur >= 0)
        {
            printf ("NO\n");
            return 0;
        }
        int r = n-2;
        int l = 0;
        while (r - l > 1)
        {
            int m = (r + l) / 2;
            point mid_vector = data[m] - data[n-1];
            if (mid_vector%cur > 0)
                r = m;
            else
                l = m;
        }
        point third_side = data[r] - data[r-1];
        point other_cur = cur - data[r-1] + data[n-1];
        if (other_cur%third_side <= 0)
        {
            printf ("NO\n");
            return 0;
        }
    }
    printf ("YES\n");
    return 0;
}
