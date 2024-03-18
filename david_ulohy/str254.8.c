#include <stdio.h>


typedef enum
{
    NE, ANO // 0, 1
} BOOLEAN;


BOOLEAN je_tu(char *nazov);  // prototyp funkcie


int main()
{
    char nazov[31];
    printf("Zadavajte nazvy suborov :\n");
    while (scanf("%s", nazov))  // while while (scanf("%s", nazov) == 1)
    {
        while (getchar() != '\n'); // cistenie stdin bufferu

        if (je_tu(nazov))   printf("Subor EXISTUJE!\n\n");
        else                printf("Subor NEEXISTUJE!\n\n");
    }

    return 0;
}

BOOLEAN je_tu(char *meno_suboru)
{
    FILE *f;
    if ((f = fopen(meno_suboru, "r")) == NULL)
        return NE;


    else if (fclose(f) == EOF)
        return NE;


    return ANO;
}