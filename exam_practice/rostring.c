// #include <unistd.h>
// #include <stdlib.h>

// void ft_putstr(char **s)
// {
//     int i = 0;
//     int len = 0;

//     while (s[len])
//         len++;
//     while (s[i])
//         write(1, s[i++], len);
// }

// int word_count(char *s)
// {
//     int i = 0;
//     int wc = 0;

//     if (!s)
//         return 0;
//     while (s[i])
//     {
//         while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
//             i++;
//         if (s[i] && (s[i] != ' ' && s[i] != '\n' && s[i] != '\t'))
//             wc++;
//         while (s[i] && (s[i] != ' ' && s[i] != '\n' && s[i] != '\t'))
//             i++;      
//     }
//     return wc;
// }

// char *word_copy(char *s, int index)
// {
//     char *word;
//     int beg = 0;
//     int pos;
//     int k = 0;

//     pos = index;
//     while (s[index] && (s[index] != ' ' && s[index] != '\n' && s[index] != '\t'))
//     {
//         beg++;
//         index--;
//     }
//     word = (char *)malloc(sizeof(char) * ((pos - beg) + 1));
//     if (!word)
//         return (NULL);
//     while (beg <= pos)
//     {
//         while (s[beg] && (s[beg] != ' ' && s[beg] != '\n' && s[beg] != '\t'))
//         {
//             word[k++] = s[beg++];
//         }
//     }
//     word[k] = '\0';
//     return (word);
// }

// char rostring(char *s)
// {
//     char **res;
//     int i;
//     int k = 0;

//     res = (char **)malloc(sizeof(char *) * (word_count(s) + 1));
//     if (!res)
//         return NULL;
//     i = 0;
//     // while (s[i])
//     //     i++;
//     while (s[i])
//     {
//         while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
//             i++;
//         if (s[i] && (s[i] != ' ' && s[i] != '\n' && s[i] != '\t'))
//         {
//             res[k++] = word_copy((char *)s, i);
//             i;
//         }
//         while (s[i] && (s[i] != ' ' && s[i] != '\n' && s[i] != '\t'))
//             i--;    
//     }
//     res[k] = 0; // NB
//     return (res);
// }

// int		main(int ac, char **av)
// {
// 	if (ac > 1 && *av[1])
// 		rostring(av[1]);
// 	write(1, "\n", 1);
// 	return (0);
// }

// // int main(int argc, char *argv[])
// // {

// //     char **bla = rostring(argv[1]);
// //     int		i;
// // 	i = 0;

// //     if (argc >= 2  && argv[1][0])
// //     {
// //         while (bla[i])
// //             write(1, &bla[i++], 1);
// //     }
// //     write(1, "\n", 1);

// // }