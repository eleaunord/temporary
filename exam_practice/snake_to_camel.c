#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int i = 0;

        while(argv[1][i])
        {
            if (argv[1][i - 1] != '_' && argv[1][i] != '_')
                 write(1, &argv[1][i], 1);
            if (argv[1][i] == '_')
            {
                argv[1][i + 1] -= 32;
                write(1, &argv[1][i + 1], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}