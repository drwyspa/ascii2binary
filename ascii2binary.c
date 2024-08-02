#include <stdio.h>
#include <unistd.h>

void    print_bits(unsigned char    octet)
{
    int             i;
    unsigned char   bit;

    i = 8;
    bit = 0;
    while (i--)
    {
        bit = (octet >> i & 1) + 48;
        write(1, &bit, 1);
        usleep(50000);
    }
}

int main(int argc, char **argv)
{
    int byte;
    int i;

    i = 0;
    printf("Your phrase in binary:\n");
    while (argv[1][i])
    {
        byte = argv[1][i];
        print_bits(byte);
        i++;
    }
    return (0);
}
