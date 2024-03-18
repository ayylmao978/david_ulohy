#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fr;
    if ((fr = fopen("TEXT.TXT", "r"))== NULL)
        return -1;
    

    // pole pointerov na jednotlive znaky - vytvorim pre kazdy riadok jeden pointer

    char *pole[1000];
    char riadok[501];

    int i = 0;
    // precitat riadku
    // mallocovat dostatocnu velkost pre riadku
    // zapisat
    // opakovat

    while (fgets(riadok, 502, fr) != NULL)
    {
        pole[i] = (char *) malloc(strlen(riadok) + 1);
        strcpy(pole[i], riadok);
        i++;
    }
    int pom = i;
    if (fclose(fr) == EOF)
        return -2;


    FILE *fw;
    if ((fw = fopen("TEXTwrite.TXT", "w"))== NULL)
        return -1;


    // pocet riadkov je ulozeny v premennej i

    for (i = i-1; i >= 0; i--)
    {
        fprintf(fw, "%s", pole[i]);
    }
    



    if (fclose(fw) == EOF)
        return -2;

    i = pom;
    for (i = i ; i > 0; i--)
    {
        free(pole[i-1]);
        pole[i-1] = NULL;
    }

    return 0;
}