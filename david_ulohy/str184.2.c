#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *p_x, pocet = 10;

    p_x = (int *)(malloc(sizeof(int) * pocet));  // vytvorenie pola pomocou pointeru na velkost pocet(10 intov)

    for (int i = 1; i <= pocet; i++) {
        *(p_x + i - 1) = 6 * i; // zaplnenie pola nasobkami cisla 6
    }
    
    int *p_nove = (int *) realloc((void *)(p_x), 20 * sizeof(int));

    for (int i = 0; i < 20; i++) {
        printf("%d\n", *(p_nove + i)); // zaplnenie pola nasobkami cisla 6
    }

    return 0;
}