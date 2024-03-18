#include <stdio.h>

#define na_neparne(x)   (1 | (unsigned)(x)) // POROVNAVA SA LEN NA 0-tom BITE!!!

int main()
{
    unsigned char i = 69; // 0100 0101;
    
    unsigned char k = 4; // 00000100
    
    k = k << 5; // ==  k <<= 5;
    printf("%d\n", k);     // 1000 0000, jednicka sa posunula o 5 pozicii dolava

    i >>= 2; 
    printf("%d\n", i);     // 0100 0101 sa zmeni na - 0001 0001 /       01 napravo sa ztrati

    return 0;
} 