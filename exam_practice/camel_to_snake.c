
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 2)
    {
        while(argv[1][i])
        {
            if (argv[1][i + 1] >= 'A' && argv[1][i + 1] <= 'Z')
            {
                argv[1][i + 1] = argv[1][i + 1] + 32;
                
                write(1, "_", 1);
                
            }
            write(1, &argv[1][i], 1); 
                      
            i++;
        }
    }
    write(1, "\n", 1);
}