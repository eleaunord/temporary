#include <unistd.h>
#include <limits.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int ft_strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return i;
}
void hidenp(char *s1, char *s2)
{
    char tmp[ft_strlen(s1) + 1];
    int i = 0;
    int j = 0;

    while (s2[i])
    {
        if (s2[i] == s1[j])
        {
            tmp[j] = s1[j];
            j++;
        }
        i++;
    }
    tmp[j] = '\0';
    if ((ft_strcmp(tmp, s1) == 0))
    {
        ft_putchar('1');
    }
    else
        ft_putchar('0');
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        hidenp(argv[1], argv[2]);
    }
    ft_putchar('\n');
    return 0;
}