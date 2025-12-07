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

static point origin;

i64 inv_mul (const point &a, const point &b)
{
    return b.x * a.y * (a.x - origin.x) * (b.y - origin.y) - a.x * b.y * (a.y - origin.y) * (b.x - origin.x);
}

bool cmp1(const point_ind &a_arg, const point_ind &b_arg)
{
    auto &a = a_arg.first;
    auto &b = b_arg.first;
    i64 mul = inv_mul (a, b);
    return mul != 0 ? mul > 0 : a.x < b.x ;
}


bool cmp2(const point_ind &a, const point_ind &b)
{
    return a.second < b.second;
}

int main ()
{
    int n;
    scanf ("%d", &n);
 
    std::vector<point_ind> data(n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%lld %lld", &data[i].first.x, &data[i].first.y);
        data[i].second = i+1;
    }
    point_ind x_max = data[0];
    point_ind y_max = data[0];
    for (int i = 1; i < n; i++)
    {
        if (cmp_xy (x_max, data[i]))
            x_max = data[i];
        if (cmp_yx (y_max, data[i]))
            y_max = data[i];
    }
 
    origin = {y_max.first.x, x_max.first.y};
 
    std::vector<point_ind> worthy;
    for (auto cur : data)
    {
        if (((cur.first.x > y_max.first.x) && (cur.first.y > x_max.first.y)) || cur.first == x_max.first || cur.first == y_max.first)
            worthy.push_back (cur);
    }

    std::sort (worthy.begin (), worthy.end (), cmp1);
 
    std::vector<point_ind> final;
    std::vector<point_ind> answer;
    for (int i = 0; i < worthy.size (); i++)
    {
        if (final.size () > 1)
        {
            auto cur = worthy[i].first;
            auto prev = (*(final.end () - 1)).first;
            auto preprev = (*(final.end () - 2)).first;
 
            origin = prev;
            i64 mul = inv_mul(cur, preprev);
            while (mul < 0 && final.size () > 1)
            {
                final.pop_back ();
                while (answer.back ().first == prev)
                    answer.pop_back ();
                prev = (*(final.end () - 1)).first;
                preprev = (*(final.end () - 2)).first;
 
                origin = prev;
                mul = inv_mul(cur, preprev);
            }
        }
        if (final.empty () || !(final.back ().first == worthy[i].first))
            final.push_back (worthy[i]);
        answer.push_back (worthy[i]);
    }
 
    std::sort (answer.begin (), answer.end (), cmp2);
    for (auto cur : answer)
        printf ("%d ", cur.second);
    printf ("\n");
}
