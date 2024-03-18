#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct
{
    char jmeno[21];
    int stari;
} A_STCT;


int priemer(A_STCT *p_pole, int velkost);

int main()
{
    FILE *fr;
    
    // pole struktur
    A_STCT pole[1000];

    //1) otvorit subor
    if ((fr = fopen("MENA_VEK.txt", "r")) == NULL)
    {
        perror("Zlyhalo otvaranie");
        exit(1);
    }

    // 2) citanie zo suboru
    char veta[401];
    int riadok = 0;
    char vek_str[4];
    
    while (fgets(veta, 402, fr) != NULL) // ahoj \n, strlen 4
    {   
        // 3) najdenie mena
        int i;
        int j = 0;

        for (i = 0; i < strlen(veta); i++)
        {
            if (isalpha(veta[i]) || veta[i] == ' ')
            {
                pole[riadok].jmeno[i] = veta[i];
            }

            // oddelenie veku, beriem v podtaz ze moze byt aj trojciferny
            if (isdigit(veta[i]))
            {
                vek_str[j++] = veta[i];
            }
        }

        pole[riadok].stari = atoi(vek_str);

        riadok++;
    }
    int i_priemer = priemer(pole, riadok);
    printf("Priemer vekov je : %d\n", i_priemer);
    printf("Ludia, ktori maju vek taky, ako je priemer:\n");
    int i = 0;
    while (i < 1000)
    {
        if (pole[i].stari == i_priemer)  printf("%s\n", pole[i].jmeno);
        i++;
    }

    //1) zatvorit subor
    if (fclose(fr) == EOF)
    {
        perror("Zlyhalo zatvaranie");
        exit(1);
    }


    return 0;
}


int priemer(A_STCT *p_pole, int velkost)
{
    int i;
    unsigned int sucet = 0;
    for (i = 0; i < velkost; i++)
    {
        sucet += p_pole[i].stari;
    }
    return (sucet / velkost);
}