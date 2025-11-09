#include <cstdio>
#include <cstdint>
#include <memory>



int main ()
{
    const uint64_t mod = 1000000007;
    int n;
    scanf ("%d", &n);
    std::unique_ptr<uint64_t []> vals = std::make_unique<uint64_t []>(n * n);

    for (int i = 0; i < n; i++)
    {
        vals[i] = 0;
    }
    vals[0] = 1;

    for (int i = 1; i < n; i++)
    {
        uint64_t *cur_vals = vals.get () + i * n;
        uint64_t *prev_vals = vals.get () + (i - 1) * n;

        char cur;
        scanf ("%c", &cur);
        if (cur == 'f')
        {
            for (int j = 0; j < i; j++)
                cur_vals[j + 1] = prev_vals[j];
        }
        else if (cur == 's')
        {
            uint64_t sum = 0;
            for (int j = i; j >= 0; j--)
            {
                sum = (sum + prev_vals[j]) % mod;
                cur_vals[j] = sum;
            }
        }
        else
            i--;
    }
    uint64_t *cur_vals = vals.get () + (n-1) * n;
    uint64_t sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = (sum + cur_vals[i]) % mod;
    }
    printf ("%ld\n", sum);

    return 0;
}
