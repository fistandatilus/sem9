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

bool check_side (point a, point b, point c, point d)
{
    return ((a - b)%(a - c)) * ((a - b)%(a - d)) < 0;
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

    i64 max = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            point p1 = data[j] - data[i];
            i64 lmax = 0, rmax = 0;
            for (int k = 0; k < n; k++)
            {
                point p2 = data[k] - data[i];
                i64 a = p1%p2;
                if (a > lmax)
                    lmax = a;
                if (a < rmax)
                    rmax = a;
            }
            if (lmax - rmax > max && lmax * rmax)
                max = lmax - rmax;
        }

    printf ("%lld", max/2);
    if (max%2)
        printf (".5");
    printf ("\n");

    return 0;
}
