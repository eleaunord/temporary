
char    *ft_strrev(char *str)
{
    char temp;
    int i = 0;
    int len = 0;

    while (str[len])
        len++;
    while (i < len / 2)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
        i++;
    }
    return (str);

}

#include <stdio.h>


int main(void)
{
    char original[] = "Hello, World!";

    printf("Original string: %s\n", original);

    printf("Reversed string: %s\n", ft_strrev(original));

    return 0;
}
