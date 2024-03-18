#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct riadka_stct
{
    char veta[81];
    int dlzka;
    struct riadka_stct *p_dalsi;
} RIADKA_STCT;


int main()
{
    // 1 vytvorit struktury
    RIADKA_STCT *p_prva, *p_aktualna, *p_pred, *p_najdlhsia; 
    p_prva = (RIADKA_STCT *) malloc(sizeof(RIADKA_STCT));
    p_aktualna = p_prva;


    // 2 prechadzat jednotlive riadky
    FILE *fr;
    if ((fr = fopen("TEXT.TXT", "r")) == NULL)
    {
        perror("Zlyhalo otvaranie");
        exit(1);
    }

    int max = 0;
    while (fgets(p_aktualna->veta, 81, fr) != NULL)
    {
        p_aktualna->dlzka = strlen(p_aktualna->veta);
        p_aktualna->p_dalsi = (RIADKA_STCT *) malloc(sizeof(RIADKA_STCT));

        // najst najvacsi
        if (p_aktualna->dlzka > max)
        {
            max = p_aktualna->dlzka;
            p_najdlhsia = p_aktualna;
        }
        p_aktualna = p_aktualna->p_dalsi;
    }
    p_aktualna->p_dalsi = NULL;


    // 5 vypisat najvacsi
    printf("Najdlsia veta mala %d znakov :\n%s", p_najdlhsia->dlzka, p_najdlhsia->veta);


    // 6 uvolnit pamat A zavriet subor
    if (fclose(fr) == EOF)
    {
        perror("Zlyhalo otvaranie");
        exit(1);
    }

    RIADKA_STCT *p_pom = p_prva;
    while (p_pom->p_dalsi != NULL)
    {
        p_pred = p_pom;
        p_pom = p_pom->p_dalsi;

        free(p_pred);
    }

    return 0;
}