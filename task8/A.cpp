#include <cstdio>
#include <vector>

static int n, m;
static int size_count;
static std::vector<std::vector<int>> links;
static std::vector<bool> visited;

bool eval (int i, int prev)
{
    visited[i] = true;
    for (int link: links[i])
    {
        if (link != prev && visited[link])
        {
            return false;
        }
    }
    
    for (int link: links[i])
    {
        if (link != prev)
            if(!eval (link, i))
                return false;
    }
    return true;
}


int main ()
{
    scanf ("%d%d", &n, &m);

    links.resize(n);
    visited.resize(n);
    std::vector<int> roots;
    for (int i = 0; i < m; i++)
    {
        int val1, val2;
        scanf ("%d%d", &val1, &val2);
        val1--;
        val2--;
        links[val1].push_back (val2);
        links[val2].push_back (val1);
    }

    for (int i = 0; i < n; i++)
        visited[i] = false;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

    
        if (eval (i, -1))
        {
            ans++;
        }
    }
    printf("%d\n", ans);
}

