#include <unistd.h>

//function to check if a char is not resent in the string u to the given index
int check(char c, char *str, int index)
{
    int i = 0;

    while(i < index)
    {
        if(c == str[i])
            return 1;
        i++;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    if (argc == 3)
    {
        while(argv[1][i])
        {
            i++;
        }
        //concatenate the second string to the first string
        while(argv[2][i])
        {
            argv[1][i] = argv[2][j];
            i++;
            j++;
        }
        //decrement i to point to the last character of the concatenated string
        i--;
        // loop to iterate through the concatenated string and print unique chars
        while (k <= i)
        {
            if (check(argv[1][k], argv[1], k) == 0)
                write(1, &argv[1][k], 1);
            k++;
        }
    }
    write(1, "\n", 1);
    return 0;
}