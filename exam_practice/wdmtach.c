
#include <unistd.h>
#include <stdio.h>


void wdmatch(char *first, char *sec)
{
    int i = 0;
    int j = 0;
    int count = 0;
    int len = 0;

    while (first[len])
        len++;
    while (sec[j] && first[i])
    {
        if (sec[j] == first[i])
        {
            count++;
            i++;
        }
        j++;
    }
    if (count == len)
    {
        i = 0;
        while (first[i])
            write(1, &first[i++], 1);
    } 
}

int main(int argc, char *argv[])
{

    if (argc == 3)
    {
        wdmatch(argv[1], argv[2]);
    }
    write(1, "\n", 1);
}