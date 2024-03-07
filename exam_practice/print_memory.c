#include <stdio.h>
#include <limits.h>
#include <unistd.h>

void print_memory(const void *addr, size_t size)
{
    char *hexa_alpha = "0123456789abcdef";
    unsigned char *new_addr = (unsigned char *) addr;
    size_t i = 0;
    size_t j;
    
    // iterate over memory block
    while (i < size)
    {
        // iterates over memory block in chunk of 16 bytes
        j = 0;
        while (j < 16 && i + j < size)
        {
            //print hexadecimal rpz of the byte
            write(1, &hexa_alpha[((*(new_addr + i + j))/ 16) % 16], 1);
            write(1, &hexa_alpha[(*(new_addr + i + j)) % 16], 1);
            if (j % 2)
                write(1, " ", 1);
            j++;
        }
        // add a space for alignment if less than 16 bytes are printed
        while (j < 16)
        {
            write(1, "  ", 2);
            if (j % 2)
                write(1, " ", 1);
            j++;
        }
        j = 0;
        while (j < 16 && i + j < size)
        {
            //print ascii rpz of the byte (printable characters or dot)
            if (*(new_addr + i + j) >= 32 && *(new_addr + i + j) <= 126)
                write(1, new_addr + i + j, 1);
            else
                write(1, ".", 1);
            j++;
        }
        write(1, "\n", 1);
        i+=16;
    }
}


int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

    print_memory(tab, sizeof(tab));
	return (0);
}