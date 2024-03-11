#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned int n = 1;
    unsigned int a;
    unsigned int b;
    unsigned int pgcd = 1;
    unsigned int max;

    if (argc == 3)
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        if (a > b)
            max = a;
        else
            max = b;
        while (n < max)
        {
            if (a % n == 0 && b % n == 0)
                pgcd = n;
            n++;
        }
        printf("%d", pgcd);
    }
    printf("%s","\n");
}