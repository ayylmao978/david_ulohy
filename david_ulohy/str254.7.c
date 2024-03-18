#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/*  
    Subor o velkosti max 1000 riadkov
    do pole struktur : STRUKTURA pole[1000] : ulozi dlzku
    do vhniezdenej struktury ulozi bonusove info
*/

typedef struct pocet
{
    unsigned int pismena;
    unsigned int ostatne;
} POCET;



typedef struct strct_hlavna
{
    unsigned int dlzka;
    POCET var;
} STRCT_HLAVNA;


int main()
{   
    FILE *fr;

    if ((fr = fopen("text254.TXT", "r")) == NULL)
    {
        perror("Zlyhalo otvaranie suboru");
        exit(1);
    }


    // urobit pole struktur

    STRCT_HLAVNA zoznam[1000]; // citam - "premenna zoznam je typu pole 1000 prvkov, ktore su typu STRCT_HLAVNA"

    int i;
    char veta[201]; // max dlzku vety som dal 200 znakov
    for (i = 0; i < 1000, fgets(veta, 201, fr) != NULL; i++)
    {   
        unsigned int pocet_znakov = 0;
        unsigned int pocet_pismen = 0;
        unsigned int pocet_inych = 0;

        

        // zistenie poctu inych znakov // ahoj\0

        for (int k = 0; k < 201; k++)
        {   

            if (veta[k] == '\0') break;
            
            pocet_znakov++;

            if (isalpha(veta[k]))
            {
                pocet_pismen++;
            }
        }
        zoznam[i].dlzka = pocet_znakov;

        pocet_inych = pocet_znakov - pocet_pismen;

        // zapisanie

        zoznam[i].var.ostatne = pocet_inych;
        zoznam[i].var.pismena = pocet_pismen;

        printf("Pocet pismen na riadke %d: %d\n", i+1, pocet_pismen);
        printf("Pocet znakov na riadke %d: %d\n\n", i+1, pocet_znakov);
    }



    if (fclose(fr) == EOF)
    {
        perror("Zlyhalo zatvaranie suboru");
        exit(1);
    }

    return 0;
}