#include <cstdio>
#include <cstring>
#include <vector>

#define STRING_SIZE 1001

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

    int operator[] (char c)
    {
        return data & (1u << (c - 'a'));
    }
};

int main ()
{
    int t;
    scanf ("%d", &t);

    std::vector<char> ans;
    ans.reserve (27);
    for (int tt = 0; tt < t; tt++)
    {
        int n, k, m;
        char str[STRING_SIZE];
        scanf ("%d%d%d\n%s", &n, &k, &m, str);
        int found = 0;
        my_set cur;
        ans.clear ();
        for (int i = 0; i < m; i++)
        {
            cur.insert (str[i]);
            if (cur.size () >= k)
            {
                found++;
                ans.push_back (str[i]);
                cur.clear ();
                if (found >= n)
                    break;
            }
        }
        if (found < n)
        {
            printf ("NO\n");
            for (char c = 'a'; c < 'a' + k; c++)
            {
                if (!cur[c])
                {
                    found++;
                    ans.push_back (c);
                    break;
                }
            }
            for (; found < n; found++)
                ans.push_back ('a');
            ans.push_back(0);
            printf ("%s\n", ans.data ());
        }
        else 
        {
            printf ("YES\n");
        }
    }
    return 0;
}
