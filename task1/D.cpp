#include <cstdio>

int main ()
{
    int amount_to_count, amount_of_types;
    int boxes[20];
    int matches[20];
    scanf ("%d%d", &amount_to_count, &amount_of_types);
    for (int i = 0; i < amount_of_types; i++)
    {
        scanf ("%d%d", boxes + i, matches + i);
    }
    int sum = 0;
    for (int u = 0; u < amount_of_types; u++)
    {
        int i_max = 0;
        for (int i = 0; i < amount_of_types; i++)
            if (matches[i] > matches[i_max])
                i_max = i;
        if (amount_to_count > boxes[i_max])
        {
         sum += matches[i_max] * boxes[i_max];
            matches[i_max] = 0;
            amount_to_count -= boxes[i_max];
        }
        else
        {
            sum += matches[i_max] * amount_to_count;
            break;
        }
    }
    printf("%d\n", sum);
    
    return 0;
}
