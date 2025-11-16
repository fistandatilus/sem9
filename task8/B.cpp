#include <cstdio>
#include <vector>

static int n;
static int size_count;
static std::vector<std::vector<int>> links;
static std::vector<int> colors;
static std::vector<int> potential;
static std::vector<int> potential_pair;

bool verify (int i, int d)
{
    if (i == d)
        return true;
    int color = colors[i];
    for (int link : links[i])
        if (colors[link] != color && link != d)
            return false;
    return true;
}

int main ()
{
    scanf ("%d", &n);

    links.resize(n);
    colors.resize(n);
    std::vector<int> roots;
    for (int i = 0; i < n - 1; i++)
    {
        int val1, val2;
        scanf ("%d%d", &val1, &val2);
        val1--;
        val2--;
        links[val1].push_back (val2);
        links[val2].push_back (val1);
    }

    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &colors[i]);
    }

    potential.clear ();
    potential_pair.clear ();
    int many_colors = -1;
    for (int i = 0; i < n; i++)
    {
        int color = colors[i];
        bool is_bad = false;
        for (int link : links[i])
        {
            if (color != colors[link])
            {
                if (!is_bad)
                {
                    potential.push_back (i);
                    potential_pair.push_back (link);
                    is_bad = true;
                }
                else
                {
                    if (many_colors >= 0)
                    {
                        printf ("NO\n");
                        return 0;
                    }
                    else
                    {
                        many_colors = i;
                        break;
                    }
                }
            }
        }
    }

    if (potential.empty())
    {
        printf("YES\n1\n");
        return 0;
    }

    if (many_colors >= 0)
    {
        for (int i = 0; i < potential.size (); i++)
        {
            if (potential_pair[i] != many_colors && potential[i] != many_colors)
            {
                printf ("NO\n");
                return 0;
            }
        }
        printf ("YES\n%d\n", many_colors + 1);
        return 0;
    }
    for (int d : potential)
    {
        bool ans = true;
        for (int i = 0; i < potential.size (); i++)
        {
            if (potential_pair[i] != d && potential[i] != d)
            {
                ans = false;
                break;
            }
        }
        if (ans)
        {
            printf ("YES\n%d\n", d + 1);
            return 0;
        }
    }
    printf ("NO\n");
    return 0;

}

