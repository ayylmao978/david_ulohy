#include <stdio.h>
/*
************************************************
*                                              *
*    Program je nutne spustit cez terminal;    *
*    gcc str230.9.c                            *
*    /a.exe "ARGUMENT1" "ARGUMENT2"            *
*                                              *
************************************************
*/

int main(int argc, char *argv[])
{
    int pocet = argc;
    FILE *fr;

    
    if (pocet == 1)
    {
        printf("Navod k pouzitiu : 1. argument je cely nazov .txt suboru, ktory VYPISEME.\n2. argument je nazov suboru, do ktoreho mozeme, ale nemusime pisat\n");
        return 0; // koniec programu pri nezadani ziadnych argumentov
    }

    if ((fr = fopen(argv[1], "r")) == NULL)
    {
        return -1;
    }

    char veta[501];

    if (pocet == 3)
    {
        FILE *fw;
        fw = fopen(argv[2], "w");
        if (fw == NULL)
            return -1;
        
        while (fgets(veta, 502, fr) != NULL)
        {
            fprintf(fw, "%s", veta);
        }


        if (fclose(fw) == EOF)
        {   
        return -1;
        }
    }

    else
    {
        while (fgets(veta, 502, fr) != NULL)
        {
            printf("%s", veta);
        }
    }



    if (fclose(fr) == EOF)
    {   
        return -1;
    }

    return 0;
}