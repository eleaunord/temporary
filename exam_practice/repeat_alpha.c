#include <unistd.h>

int repeat(char c)
{
    int rep = 1;

    if (c >= 'A' && c <= 'Z')
    {
        rep = c - 'A' + 1;   
    }
    if (c >= 'a' && c <= 'z')
    {
        rep = c - 'a' + 1;
    }
    return (rep);
}

int main(int argc, char *argv[])
{
    int i = 0;
    int count = 0;

    if (argc == 2)
    {
        while(argv[1][i])
        {
            count = repeat(argv[1][i]);
            while (count--)
            {
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}