#include <unistd.h>

int main (int argc, char *argv[])
{
    int i = 0;
    char c;

    if (argc == 2)
    {
        while(argv[1][i])
        {
            c = argv[1][i++];
            if (c == 'z')
                c = 'a';
            else if (c == 'Z')
                c = 'A';
            else if ((c >= 'A' && c <= 'Y') || (c >= 'a' && c <= 'y'))
                c += 1;
            write(1, &c, 1);
        }
    }
    write(1, "\n", 1);
}