/*
program zisti pocet jednotlivych pismen na kazdej riadke, nerrozlisujem velke a male - pouzijem toLower()

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


void nulovanie_zoznamu(int **p_pole)
{
    int *a = *p_pole;
    for (int k = 0; k < 26; k++)
	    *(a + k) = 0;
}



void vypis_zoznam(int **p_pole, int pos)
{    
    int *a = *p_pole;
    printf("Riadok cislo %d, hodnoty : ", pos+1);
    for (int k = 0; k < 26; k++) {
        printf("%c:%d ", (k+'A'), *(a + k));
    }
    printf("\n");
}


int main()
{
    FILE *fr;
    fr = fopen("TEXT.TXT", "r");
    if (fr == NULL)
        return -1;

    // pole na odkladanie poctov jednotlivych pismen (nerozlisujem velke a male)
    int *zoznam = (int *)malloc(26*sizeof(int));

    // nulovanie zoznamu
    nulovanie_zoznamu(&zoznam);

    int i;
    int c;
    for (i = 0; i < 20; i++) {
        while ((c = getc(fr)) != '\n') {

            if (c == EOF) { // koniec suboru
                vypis_zoznam(&zoznam, i);
                free((void *) zoznam);
                return 0;
            }
            
            if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a')) {
                c = toupper(c);
                *(zoznam + (c - 'A')) += 1;
            }
        }
        vypis_zoznam(&zoznam, i);
        nulovanie_zoznamu(&zoznam);
    }
    free((void *) zoznam);
    return 0;
}