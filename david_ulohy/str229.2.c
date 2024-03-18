#include <stdio.h>

int main()
{
    int pole[5][5];

    printf("Adresa pole--> %p\n", pole);

    //  prvok [0][0]
    printf("Adresa pole[0][0]--> %d\n", &pole[0][0]);

    //  prvok [1][0]
    printf("Adresa pole[1][0]--> %p\n", &pole[1]);

    printf("Adresa pole[4][4]--> %d\n", &pole[4][4]);

    // cele pole = 5*5*4
    printf("Velkost pole --> %d ints\n", sizeof(pole));

    // jedna riadka = 4int * 5
    printf("Velkost pole[0] --> %d\n", sizeof(pole[0]));

    // jeden int
    printf("Velkost pole[4][4] --> %d\n", sizeof(pole[4][4]));

    return 0;
}