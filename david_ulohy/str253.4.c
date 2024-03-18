#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// tu si vytvaram zaklad struktury
typedef struct a
{
    char jmeno[21];
    int stari;
    struct a *p_dalsi; // toto je pointer na dalsiu strukturu, vytvaram tak linked list
} A_STCT;

// prototypy funkcii
int priemer(A_STCT *p_struct);
void najdimeno_a_free(A_STCT *p_struct, int priemer);

int main()
{
    FILE *fr;

    // test na otvorenie suboru
    if ((fr = fopen("MENA_VEK.txt", "r")) == NULL)
    {
        perror("Zlyhalo otvaranie");
        exit(1);
    }

    // nacitana veta zo suboru
    char veta[401];

    // pocitadlo, na ktorom riadku som
    int riadok = 0;

    // retazec znakov pre vek, ktory potom prekonvertujem na int
    char vek_str[4];

    // pointer na prvu strukturu a aktualny
    // prvu strukturu vyuzivam pri predavani do funkcie za parameter
    A_STCT *p_prvy, *p_aktualny;


    p_prvy = (A_STCT *) malloc(sizeof(A_STCT));
    p_aktualny = p_prvy;
    
    while (fgets(veta, 402, fr) != NULL)
    {   

        int i;
        int j = 0;

        // pri prvom opakovani chcem pouzit prvu strukturu
        if (riadok == 0) p_aktualny = p_prvy;

        // inak sa bude uz musiet vytvorit nadchadzajuca
        else
        {
            p_aktualny->p_dalsi = (A_STCT *) malloc(sizeof(A_STCT));
            p_aktualny = p_aktualny->p_dalsi;
        }
        

        for (i = 0; i < strlen(veta); i++)
        {   
            // ak je znak pismeno
            if (isalpha(veta[i]))
            {
                p_aktualny->jmeno[i] = veta[i];
            }
            // ak je znak medzera, ukoncujem string znakom '\0'
            if (veta[i] == ' ')
            {
                p_aktualny->jmeno[i] = '\0';
            }
            // ak je znak ciselny, pridavam ho do ineho stringu, vek_str
            if (isdigit(veta[i]))
            {
                vek_str[j++] = veta[i];
            }
        }
        // konvertovanie stringu cisiel na realne cislo
        p_aktualny->stari = atoi(vek_str);

        riadok++;
    }

    // pointer v poslednej strukture nastavim na NULL, aby som vedel kedy mi linked list konci
    p_aktualny->p_dalsi = NULL;

    // hodnotu priemer ukladam do premennej int aby som volal casovo narocnu funkciu len raz!
    int hodnota_priemer = priemer(p_prvy);

    printf("Priemerny vek je: %d\nLudia, co maju rovnaky vek:\n", hodnota_priemer);

    // void funkcia najdimeno_a_free bude sama printovat
    najdimeno_a_free(p_prvy, hodnota_priemer);



    // zatvorit subor
    if (fclose(fr) == EOF)
    {
        perror("Zlyhalo zatvaranie");
        exit(1);
    }


    return 0;
}


int priemer(A_STCT *p_struct) // parameter je pri oboch funkciach pointer na prvu strukturu
{
    int i;
    unsigned int sucet, velkost;
    sucet = velkost = 0;
    while (p_struct != NULL) // *kym nie sme na poslednej strukture*
    {   
        velkost++; // pocitadlo kvoli deleniu pri vypocte priemeru
        sucet += p_struct->stari;

        p_struct = p_struct->p_dalsi; // posun na dalsiu strukturu
   }

   return sucet / velkost; // aritmeticky priemer
}


void najdimeno_a_free(A_STCT *p_struct, int priemer)
{
    A_STCT *p_pred;
    int i;
    unsigned int sucet, velkost;
    while (p_struct != NULL)
    {   
        p_pred = p_struct;

        if (p_struct->stari == priemer)
        {
           printf("%s\n", p_struct->jmeno);
        }
        p_struct = p_struct->p_dalsi;
        free((void *)p_pred); /* uvolnovanie pamate vdaka premennej p_pred (predosla struktura + posledna, kedze p_struct sa pri poslednej iteracii zmeni na NULL)
                                zmenenim na null uz nebude existovat dalsia struktura tym padom sa s vymazanim p_pred vymaze ozajstne kazda struktura z heapu.
                                
                                Je to cursed ale co uz*/
   }                           
}