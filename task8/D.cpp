#include <cstdio>
#include <vector>

static int n;
static int leaf_count;
static std::vector<std::vector<int>> children;
static std::vector<bool> is_max;

int eval (int i)
{
    if (children[i].empty ())
    {
        leaf_count++;
        return 1;
    }
    int ans;
    if (is_max[i])
    {
        ans = n + 1;
        for (int child : children[i])
        {
            int child_ans = eval (child);
            ans = std::min(ans, child_ans);
        }
    }
    else
    {
        ans = 0;
        for (int child : children[i])
            ans += eval(child);
    }
    return ans;
}


int main ()
{
    scanf ("%u", &n);

    children.resize(n);
    is_max.resize(n);
    leaf_count = 0;
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf ("%d", &val);
        is_max[i] = (val == 1);
    }

    for (int i = 1; i < n; i++)
    {
        int val;
        scanf ("%d", &val);
        children[val - 1].push_back (i);
    }
    int ans = eval (0);
    printf ("%d\n", leaf_count - ans + 1);
}

