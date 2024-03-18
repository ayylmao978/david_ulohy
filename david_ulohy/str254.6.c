/*
*************************
*  NEDOKONCENY PROGRAM  *
*************************
*/



#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct riadka_stct
{
    char **veta; // pointer na pointer na char
    int dlzka;
    struct riadka_stct *p_dalsi;
} RIADKA_STCT;


int main()
{
    // 1 vytvorit struktury
    RIADKA_STCT *p_prva, *p_aktualna, *p_najdlhsia; 
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
    int riadok = 0;
    char stack_veta[81];
    while (fgets(stack_veta, 81, fr) != NULL)
    {   
        if (riadok == 0)  p_aktualna = p_prva;
        else p_aktualna = p_aktualna->p_dalsi;

        p_aktualna->dlzka = strlen(stack_veta);
        p_aktualna->p_dalsi = (RIADKA_STCT *) malloc(sizeof(RIADKA_STCT));

        // ulozim vetu do heapu a budem ukladat pointer na nu

        char *heap_veta = ((char *) malloc(81 * sizeof(char)));
        p_aktualna->veta = &heap_veta;
        strcpy(*(p_aktualna->veta), stack_veta); // prekopirovanie

        // najdenie max
        if (p_aktualna->dlzka > max)
        {
            max = p_aktualna->dlzka;
            p_najdlhsia = p_aktualna;
        }
        riadok++;
    }
    p_aktualna->p_dalsi = NULL;


    // 5 vypisat najvacsi
    printf("Najdlsia veta mala %d znakov :\n%s", max, *(p_najdlhsia->veta));


    // 6 uvolnit pamat A zavriet subor
    if (fclose(fr) == EOF)
    {
        perror("Zlyhalo otvaranie");
        exit(1);
    }

    RIADKA_STCT *p_pom = p_prva;
    RIADKA_STCT *p_pred;

    // zistenie priemernej dlzky
    int sucet = 0;
    int pocet = 0;
    while (p_pom->p_dalsi != NULL)
    {   
        sucet += p_pom->dlzka;
        p_pom = p_pom->p_dalsi;
        pocet++;
    }
    int priemer = sucet / pocet; 

    // najdenie viet s poctom znakov rovnym priemeru a ich vymazanie

    printf("Riadky, ktore maju rovnaku dlzku ako je priemer %d:\n", priemer);
    p_pom = p_prva;
    while (p_pom->p_dalsi != NULL)
    {   
        p_pred = p_pom;

        if (p_pom->dlzka == priemer)
        {
            printf("%s", *(p_pom->veta));
        }

        p_pom = p_pom->p_dalsi;

        free((void *)(*(p_pred->veta)));
        free((void *)p_pred);
    }



    return 0;
}