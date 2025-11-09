#include <cstdio>
#include <cstdint>
#include <memory>
#include <cstring>


int main ()
{
    const uint64_t mod = 1000000007;
    int n, k;
    scanf ("%d%d", &n, &k);
    std::unique_ptr<uint64_t []> vals = std::make_unique<uint64_t []>(n * k);

    memset(vals.get (), 0, n * k * sizeof(uint64_t));

    for (int i = 0; i < n; i++)
    {
        vals[i] = 1;
    }

    for (int i = 1; i < k; i++)
    {
        uint64_t *cur_vals = vals.get () + i * n;
        uint64_t *prev_vals = vals.get () + (i - 1) * n;

        for (int j = 1; j <= n; j++)
        {
            for (int l = j; l <= n; l += j)
            {
                cur_vals[l-1] = (cur_vals[l-1] + prev_vals[j-1]) % mod;
            }
        }

    }
    uint64_t *cur_vals = vals.get () + (k-1) * n;
    uint64_t sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = (sum + cur_vals[i]) % mod;
    }
    printf ("%ld\n", sum);

    return 0;
}
