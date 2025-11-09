#include <cstdio>
#include <vector>

int main ()
{
    int n, c;
    scanf ("%d%d", &n, &c);
    std::vector<int> a (n);
    std::vector<int> b (n);
    for (int i = 1; i < n; i++)
        scanf ("%d", &a[i]);
    for (int i = 1; i < n; i++)
        scanf ("%d", &b[i]);

    std::vector<int> walk_times(n);
    std::vector<int> car_times(n);
    car_times[0] = c;
    walk_times[0] = 0;
    printf ("0 ");
    for (int i = 1; i < n; i++)
    {
        walk_times[i] = std::min(car_times[i-1], walk_times[i-1]) + a[i];
        car_times [i] = std::min(car_times[i-1], walk_times[i-1] + c) + b[i];

        printf ("%d ", std::min(car_times[i], walk_times[i]));
    }
    printf("\n");

    return 0;
}
