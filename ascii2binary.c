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

int main(void)
{
    int     byte;
    int     i;
    char    str[1000];

    i = 0;
    printf("\nPlease type your phrase:\n");
    fgets(str, sizeof(str), stdin);
    printf("Your phrase in binary:\n");
    while (str[i] != '\0' && str[i] != '\n')
    {
        if (str[i] != 32)
        {
            byte = str[i];
            print_bits(byte);
        }
        else
        {
            write(1, " ", 1);
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
