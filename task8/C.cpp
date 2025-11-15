#include <cstdio>
#include <vector>

static int n, m;
static int size_count;
static std::vector<std::vector<int>> links;
static std::vector<int> colors;

bool eval (int i)
{
    int color = -1;
    for (int link: links[i])
    {
        if (colors[link] == 0)
        {
            if (color == 0)
                return false;
            color = 1;
        }
        if (colors[link] == 1)
        {
            if (color == 1)
                return false;
            color = 0;
        }
    }
    colors[i] = color == -1 ? 0 : color;
    
    for (int link: links[i])
    {
        if (colors[link] == -1)
            if(!eval (link))
                return false;
    }
    return true;
}


int main ()
{
    scanf ("%d%d", &n, &m);

    links.resize(n);
    colors.resize(n);
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
        colors[i] = -1;

    for (int i = 0; i < n; i++)
    {
        if (colors[i] >= 0)
            continue;

        roots.push_back (i + 1);
        if (!eval (i))
        {
            printf ("-1\n");
            return 0;
        }
    }
    printf("%lu\n", roots.size ());
    for (int root : roots)
        printf ("%d ", root);
    printf ("\n");
}

