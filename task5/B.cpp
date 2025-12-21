#include <cstdio>
#include <cmath>
#include <memory>

int main ()
{
    int n;
    scanf ("%d\n", &n);
    if (n % 2)
    {
        printf(":(\n");
        return 0;
    }
    std::unique_ptr<char []> s_up = std::make_unique<char []> (n+1);
    char *s = s_up.get ();

    scanf ("%s", s);
    int q = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '(')
            b++;
        else if (c == ')')
            b--;
        else
            q++;
    }
    int ql = std::max (-b, 0) + (q - std::abs(b))/2;
    int qr = std::max ( b, 0) + (q - std::abs(b))/2;
    int balance = 0;
    for (int i = 0; i < n; i++)
    {
        char &c = s[i];
        if (c == '(')
            balance++;
        else if (c == ')')
            balance--;
        else
        {
            if (ql > 0)
            {
                c = '(';
                ql--;
                balance++;
            }
            else if (qr > 0)
            {
                c = ')';
                qr--;
                balance--;
            }
        }
        if (balance <= 0 && i < n-1)
        {
            printf(":(\n");
            return 0;
        }
    }
    if (balance != 0)
    {
        printf(":(\n");
        return 0;
    }

    printf ("%s\n", s);

    return 0;
}
