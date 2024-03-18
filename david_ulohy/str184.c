#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *p_x, pocet = 10, *p_pom1, *p_pom2, *p_nove;

    p_x = (int *)(malloc(sizeof(int) * pocet));  // vytvorenie pola pomocou pointeru na velkost pocet(10 intov)

    for (int i = 1; i <= pocet; i++) {
        *(p_x + i - 1) = 6 * i; // zaplnenie pola nasobkami cisla 6
    }

    p_nove = (int *)(malloc(sizeof(int)*( pocet + 10)));

    p_pom1 = p_x;
    p_pom2 = p_nove;

    while (p_pom1 < p_x + pocet) {
        *p_pom2++ = *p_pom1++;
    }

    p_x -= pocet;
    p_pom1 = p_pom2 = NULL;
    pocet += 10;
    p_x = p_nove;

    for (int i = 0; i < 20; i++)
        printf("%d\n", *(p_x + i));

    free((void *)p_x);

    return 0;
}
