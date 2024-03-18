#include <stdio.h>
#include <string.h>

#define PI      3.14159265359

int main()
{
    int pocet;
    do
    {
        printf("Zadajte, na kolko desatinnych miest ma byt PI vypisane :\n");
        scanf("%d", &pocet);

        printf("%.*lf\n", pocet, PI);

    } while (pocet > 0 && pocet <= 11);


    return 0;
}