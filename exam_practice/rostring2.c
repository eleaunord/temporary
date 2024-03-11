#include <unistd.h>
// #include <stdlib.h>

void rostring(char *s)
{
    int i = 0;
    int len_first = 0;

    while (s[i])
    {
        while ((s[i] == ' ' || s[i] == '\t'))
            i++;
        if (s[i] && (s[i] != ' ' && s[i] != '\t'))
        {
            if (len_first == 0)
            {
                while (s[i] && (s[i] != ' ' && s[i] != '\t'))
                {
                    len_first++;
                    i++;
                }
            }
            else
            {
                while (s[i] && (s[i] != ' ' && s[i] != '\t'))
                {
                    write(1, &s[i++], 1);
                }
                write(1, " ", 1);
            }
        }
        i++;
    }
    //first word
    int k = 0;
    while (s[k] && (s[k] == ' ' || s[k] == '\t'))
        k++;
    while (len_first--)
        write(1, &s[k++], 1);
}

int		main(int argc, char **argv)
{
	if (argc > 1 && *argv[1])
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}