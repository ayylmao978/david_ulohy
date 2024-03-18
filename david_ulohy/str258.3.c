#include <stdio.h>


int main()
{
    unsigned char i = 0b10111111;

    i &= ~0xF;

    printf("%d", i);


    return 0;
}