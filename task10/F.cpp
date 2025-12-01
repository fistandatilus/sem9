#include <cstdio>
#include <cstring>
#include <vector>

#define STRING_SIZE 100001

struct my_set
{
    unsigned int data = 0u;

    void clear ()
    {
        data = 0u;
    }

    void insert (char c)
    {
        data |= 1u << (c - 'a');
    }
    
    void add (const my_set &other)
    {
        data |= other.data;
    }

    int size () const
    {
        int size = 0;
        for (unsigned int i = 0; i < sizeof (unsigned int) * 8; i++)
            size += (data >> i) & 1u;
        return size;
    }
};

std::vector<my_set> data;

void pos (int v, int l, int r, int i, char c)
{
    if (i < l || r <= i)
        return;
    if (r - l == 1)
    {
        data[v].clear ();
        data[v].insert (c);
        return;
    }
    pos (2*v, l, (l + r)/2, i, c);
    pos (2*v + 1, (l + r)/2, r, i, c);
    data[v].clear ();
    data[v].add (data[2*v]);
    data[v].add (data[2*v + 1]);
}

my_set get (int v, int l, int r, int L, int R)
{
    if (r <= L || R <= l)
        return {};
    if (L <= l && r <= R)
    {
        return data[v];
    }
    my_set ans;
    ans.add (get (2*v, l, (l + r)/2, L, R));
    ans.add (get (2*v + 1, (l + r)/2, r, L, R));
    return ans;
}

int main ()
{
    char str[STRING_SIZE];
    scanf ("%s", str);
    
    int n = strlen (str);
    data.resize (4 * n);
    for (int i = 0; i < n; i++)
    {
        pos (1, 0, n, i, str[i]);
    }
    
    int q;
    scanf ("%d", &q);

    for (int tt = 0; tt < q; tt++)
    {
        int type;
        scanf ("%d", &type);
        if (type == 1)
        { //pos
            int i;
            char c;
            scanf ("%d %c", &i, &c);
            pos (1, 0, n, i - 1, c);
        }
        else
        {
            int l, r;
            scanf ("%d %d", &l, &r);
            my_set ans = get (1, 0, n, l - 1, r);
            printf ("%d\n", ans.size ());
        }
    }
    return 0;
}
