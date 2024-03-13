#include <unistd.h>
#include <stdio.h>

//NB ADD INDEX FOR CHECK DOUBLE
int check_double(char *s, char c, int index)
{
    int i;

    i = 0;
    while (i < index)
    {
        if (s[i] == c)
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int i, j;

    if (argc == 3)
    {   
        i = 0;
        while (argv[1][i])
        {
            if (check_double(argv[1], argv[1][i], i) != 0) //check if no double in first w
            {
                j = 0;
                while (argv[2][j])
                {
                    if(argv[2][j] == argv[1][i])
                    {
                        write(1, &argv[1][i], 1);
                        break ; //break from looking into argv[2]
                    }
                    j++;
                }
            }  
            i++;

        }
    }
}