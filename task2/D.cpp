#include <cstdio>
#include <vector>

int main ()
{
    std::vector<std::pair<char, int>> input;
    std::vector<int> output;

    for (int i = 0; i < 100000; i++)
    {
        char cur;
        if (scanf ("%c", &cur) != 1)
            break;
        if (cur == 0 || cur == '\n')
            break;
        if (cur == '(' || cur == '[' || cur == '{')
        {
            input.push_back ({cur, i});
            output.push_back (-1);
            continue;
        }
        char counter = '(';
        if (cur == '}')
            counter = '{';
        if (cur == ']')
            counter = '[';
        if (input.empty () || input.back ().first != counter)
        {
            printf("-1\n");
            return 0;
        }
        output[input.back ().second] = i;
        output.push_back (input.back ().second);
        input.pop_back ();
    }
    if (!input.empty ())
    {
        printf ("-1\n");
        return 0;
    }
    for (int cur : output)
        printf ("%d ", cur);
    printf ("\n");

    return 0;
}
