unsigned char reverse_bits(unsigned char octet)
{
    //initialization of the counter for the loop and res to store the reversed bits
    unsigned int i = 8;
    unsigned char res;

    while (i--)
    {
        res = res * 2 + (octet % 2);
        octet = octet / 2;
    }
    return res;
    //bit reversal logic
        // shift current bits of res to the left by one pos 
        // add least significant bit of octet to res
        // right shit octet by on pos to prepare for next iteratiion

}