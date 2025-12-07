#include <cstdio>

int main ()
{
    long long int ax, bx, cx, ay, by, cy;
    scanf ("%lld%lld%lld%lld%lld%lld", &ax, &ay, &bx, &by, &cx, &cy);
    long long int size1 = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    long long int size2 = (cx - bx) * (cx - bx) + (cy - by) * (cy - by);
    long long int mul = (ax - bx) * (by - cy) - (ay - by) * (bx - cx);
    if (size1 != size2 || mul == 0)
        printf ("nO\n");
    else
        printf ("yEs\n");
    return 0;
}
