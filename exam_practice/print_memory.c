
// #include <limits.h>
// #include <unistd.h>

// void	ft_putchar(char c)
// {
//     write(1, &c, 1);
// }
// void	ft_putstr(char *s)
// {
//     int i = 0;

//     while (*s)
//     {
//         write(1, &s[i], 1);
//         i++;
//     }
//     s[i] = '\0';
// }

// void	ft_printchars(unsigned char c)
// {
//     if (c >= 32 && c <= 126)
//         ft_putchar('c');
//     else
//         ft_putchar('.');
// }

// void	ft_printhex(int n)
// {
//     char hexa[INT_MAX];
//     int i = 0;
//     int remain = 0;

//     while(n > 0)
//     { 
//         remain = n % 16;
//         if (remain < 10)
//             hexa[i++] = remain + '0';
//         else
//             hexa[i++] = remain - 10 + 'A';
//         n = n / 16;  
//     }
//     hexa[i] = '\0';
// }

// void	print_memory(const void *addr, size_t size)
// {
//     unsigned char *t = (unsigned char *)addr;
//     size_t i = 0;
//     int col;
//     size_t tmp = 0;

//     //iterating within the table
//     while (i < size)
//     {
//         col = 0;
//         // hexa uses 2 c to rpw each byte
//         while (col < 16)
//         {
//             if (i < size)
//             {
//                 if (t[i] < 16)
//                     ft_putchar('0');
//                 ft_printhex(t[i]);
//             }
//             else
//                 ft_putstr(" ");
//             i++;
//             // & 1 checks if i is odd or even
//             // << 6 left shift operation by 6 bits
//             //shift result to the left
//             ft_putchar((i & 1))
//             col++;


//         }
//     }

// }

// int	main(void)
// {
// 	int	tab[10] = {0, 23, 150, 255,
// 	              12, 16,  21, 42};

// 	print_memory(tab, sizeof(tab));
// 	return (0);
// }