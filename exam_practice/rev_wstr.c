
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

void rev_wstr(char *s)
{
    int end;
    int start;
    int i = ft_strlen(s);
    int beg_checker;

    while (i >= 0)
    {
        while (s[i] == ' ' || s[i] == '\t' || s[i] == '\0')
            i--;
        end = i;
        while (s[i] && (s[i] != ' ' && s[i] != '\t'))
            i--;
        start = i + 1;
        beg_checker = start;
        while (start <= end)
            write(1, &s[start++], 1);
        if (beg_checker != 0)
            write(1, " ", 1);
    }
}

int main (int argc, char *argv[])
{

    if (argc == 2)
    {
        rev_wstr(argv[1]);
    }
    write(1, "\n", 1);
}