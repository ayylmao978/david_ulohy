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

    char substring[20];
    printf("Zadajte slovom ktore budeme hladat :\n");
    scanf("%s", substring);
    putchar('\n');

    while (fgets(riadok, 502, fr) != NULL)
    {
        pole[i] = (char *) malloc(strlen(riadok) + 1);
        strcpy(pole[i], riadok);
        if (strstr(pole[i], substring))
            printf("%s", pole[i]);
        i++;
    }
    int pom = i;
    if (fclose(fr) == EOF)
        return -2;



    FILE *fw;
    if ((fw = fopen("ODKAZY.TXT", "w"))== NULL)
        return -1;

    i--;
    while (i >= 0)
        {
        if (strstr(pole[i], substring))
            fprintf(fw, "Cislo riadku - %d - %s", i+1, pole[i]);
        i--;
        }   




    if (fclose(fw) == EOF)
        return -2;



    for (i = i ; i > 0; i--)
    {
        free(pole[i-1]);
        pole[i-1] = NULL;
    }

    return 0;
}