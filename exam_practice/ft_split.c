
#include <stdlib.h>
#include <stdio.h>


// NNB jsut type out the spaces ow i have a core dump erroor

static int word_count(char *str)
{
    int i = 0;
    int wc = 0;
    
    if (!str)
        return (0);
    while (str[i])
    {
        //skip spaces at the beg
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        //count word with IF (just need the beg of word)
        if (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            wc++;
        //skip the other c of the word bc we don't care
        while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
    }
    return (wc);
}

char *wordcopy(char *s, int i)
{
    int end = 0;
    char *word;
    int j = 0;

    if (!s)
        return (NULL);
    while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
    {
        end++;
        i++;
    }
    word = (char *) malloc(sizeof(char) * (end + 1));
    if (!word)
        return (NULL);
    // reset i to the starting pos of the word
    i = i - end;
    end = 0;
    while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
        word[j++] = s[i++];
    word[j] = '\0';
    return(word);
}


char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    // int start = 0;
    // int end = 0;
    // int end_string = 0;
    char **res;

    res = (char **)malloc(sizeof(char *) * (word_count((char *)str) + 1));
    if (!res || !str)
        return (NULL);
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        //start copying from beg word using worcopy
        if (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            res[j++] = wordcopy((char *) str, i);
        //continue advancing in the word
        while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
    }
    res[j] = 0;
    return (res);
}

// int	main(int ac, char **av)
// {
// 	char	**tab = ft_split(av[1]);
// 	int		i;
// 	i = 0;

// 	if (ac == 2)
// 	{
// 		while (tab[i])
// 		{
// 			printf("%s ", tab[i]);
// 			i++;
// 		}
// 	}
// 	else
// 		printf("need 1 arg separated by spaces");
// 	free(tab);
// }
// int is_space(char c)
// {
//     if (c == ' ' || c == '\n' || c == '\t')
//         return 0;
//     return 1;
// }

// int word_count(char *s)
// {
//     int i = 0;
//     int wc = 0;
//     int len = 0;

//     if (!s)
//         return 0;
//     //length word
//     while (s[len])
//         len++;
//     while(i < len - 1)
//     {
//         //getting rid off first spaces
//         while (s[i] && is_space(s[i]) == 0)
//             i++;
//         if ( s[i] && is_space(s[i]) != 0)
//             wc++;
//         while (s[i] && is_space(s[i]) != 0)
//             i++;
//     }
//     return wc;
// }

// char *word_copy(char *s, int index)
// {
//     int end, start;
//     int k = 0;
//     char *cpy;

//     start = index;
//     end = 0;
//     if (!s)
//         return NULL;
//     while (s[index] && is_space(s[index])!= 0)
//     {
//         end++;
//         index++;
//     }
//     cpy = (char *)malloc(sizeof(char *) * (end + 1));
//     if (!cpy)
//         return (NULL);
//     while (s[start] && is_space(s[start]) != 0)
//         cpy[k++] = s[start++];
//     cpy[k] = '\0';
//     return (cpy);
// }

// char    **ft_split(char *str)
// {
//     char **res;
//     // int len = 0;
//     int i = 0;
//     int j = 0;

//     res = (char **)malloc(sizeof(char *) * (word_count((char *)str) + 1));
//     if (!res || !str)
//         return (NULL);
//     // while (str[len])
//     //     len++;
//     while (str[i])
//     {
//         while (str[i] && is_space(str[i]) == 0)
//             i++;
//         if (str[i] && is_space(str[i]) != 0)
//         {
//             res[j] = word_copy((char *)str, i);
//             i++;
//         } 
//     }
//     res[j] = 0;
//     return (res);
// }

int	main(int ac, char **av)
{
	char	**tab = ft_split(av[1]);
	int		i;
	i = 0;

	if (ac == 2)
	{
		while (tab[i])
		{
			printf("%s ", tab[i]);
			i++;
		}
	}
	else
		printf("need 1 arg separated by spaces");
	free(tab);
}