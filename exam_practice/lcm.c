
#include <limits.h>
#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int lcm = 0;
    // int i = 0;
    
    if (a == 0 || b == 0)
        return (0);
    // initialize lcm with the larger of a and b bc lcm of 2 numbers always >= to a or b
    if (a > b)
        lcm = a;
    else
        lcm = b;
    while (lcm < INT_MAX)
    {
        if (lcm % a == 0 && lcm % b == 0)
            return (lcm);
        lcm++;
    }
    return (lcm);
}

// int main(void)
// {
//     int a = 2;
//     int b = 3;

//     printf("%d", lcm(a, b));
// }