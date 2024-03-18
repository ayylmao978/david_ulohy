#include <stdio.h>
#include <ctype.h>
#define POCET   ('Z' - 'A' + 1)

int main()
{
    FILE *fr;
    int c, i;
    int pole[POCET];

    // vynulovanie pola
    for (i = 0; i < POCET; i++)
        pole[i] = 0;

    // kontrola spravneho otvorenia suboru
    if ((fr = fopen("texty/PISMENA.TXT", "r")) == NULL) {
        printf("Subor neexistuje\n");
        return -1;
    }

    while ((c = getc(fr)) != EOF) {     // ak nie si na konci suboru
        if (isalpha(c))                 // ak je znak pismeno
            pole[toupper(c) - 'A']++;   // pripocitaj jednotku k hodnote pismena v poli
    }
    printf("V subore bol tento pocet jednotlivych pismen : \n");
    for (i = 0; i < POCET; i++) {
        printf("%c - %d\n", (i + 'A'), pole[i]);
    }

    if (fclose(fr) == EOF) { 
        printf("Subor sa nepodarilo zavriet\n");
        return -2;
    }
    return 0;
}
