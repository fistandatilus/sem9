#include <cstdio>
#include <cstring>


bool verify_string(const char *s)
{
    int len = strlen (s);
    len = len / 2;
    char c1 = s[0];

    for (int i = 1; i < len; i++)
        if (s[i] != c1)
            return true;
    return false;
}

int main ()
{
    int amount = 0;
    char buf[100];
    scanf ("%d", &amount);
    for (int i = 0; i < amount; i++)
    {
        scanf ("%s", buf);
        if (verify_string (buf))
            printf("YES\n");
        else
            printf ("NO\n");
    }
    return 0;
}
