#include <string.h>
#include <stdio.h>

//pointer so *s1 and ++s1

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int j;

    //NB condition if strings are null
    if (!s1 || !s2)
        return NULL;
    while(*s1)
    {
        j = 0;
        while(s2[j])
        {
            if(*s1 == s2[j])
            {
                return ((char *)s1);
            }
            j++;
        }
        ++s1;
    }
    return NULL;
}

int main(void)
{

    // char s = "bonjour";
    // char a = "hey bonjour maman";

    printf("%s", strpbrk("veux tu", "pourauoi tu"));
    printf("%s", ft_strpbrk("veux tu", "pourauoi tu"));

}