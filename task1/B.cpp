#include <algorithm>
#include <vector>
#include <cstdio>

int main ()
{
    int amount = 0;
    scanf ("%d", &amount);

    std::vector<int> values (amount); 

    scanf ("%d", &values[0]);
    for (int i = 1; i < amount; i++)
    {
        int cur;
        scanf ("%d", &cur);
        values[i] = values[i - 1] + cur;
    }
    int needed = values[amount - 1] / 2 + values[amount - 1] % 2;
    printf("%ld\n", std::distance (values.begin (), std::lower_bound (values.begin (), values.end (), needed)) + 1);
    return 0;
}
