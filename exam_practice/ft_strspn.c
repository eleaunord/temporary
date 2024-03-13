#include <string.h>
#include <stdio.h>

char	*check_char(const char *s, const char c)
{
    while(*s)
    {
        if(*s == c)
            return ((char *)s);
        ++s;
    }
    return (NULL);
}

// //the index in s starting at which we have the char accept
size_t ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;

    //starts at beg s an check each char
    while(s[i])
    {
        //stops as soon as it encounters a char that is not present in accept
        if (check_char(accept, s[i]) == NULL) //if char not found break and start again
            break ;
        i++; // if char found iteration continues
    }
    //returns number of chr from beg of the string that are present in accept
    return (i);
}


int main(void)
{
    const char *s = "Hello, world!";
    const char *accept = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    printf("String: %s\n", s);
    printf("Accept characters: %s\n", accept);

    // Testing ft_strchr
    char target = 'o';
    char *result = ft_strchr(s, target);
    printf("ft_strchr('%c'): %s\n", target, result != NULL ? result : "Character not found");

    // Testing ft_strspn
    size_t length = ft_strspn(s, accept);
    printf("ft_strspn: %zu\n", length);

    return 0;
}