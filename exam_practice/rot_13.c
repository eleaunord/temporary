#include <unistd.h>

int main(int argc, char *argv[])
{
    char c;

    if (argc == 2)
    {
        while (*argv[1])
        {
            c = *argv[1]++;
            if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
                c += 13;
            else if ((c >= 'N' && c <= 'Z') ||( c >= 'n' && c <= 'z'))
                c -= 13;
            write (1, &c, 1);
        }

    }
    write(1, "\n", 1);
}