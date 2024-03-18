/*
************************************************
*                                              *
*    Program je nutne spustit cez terminal;    *
*    gcc str230.9.c                            *
*    /a.exe "ARGUMENT1" "ARGUMENT2"            *
*                                              *
************************************************
*/
#include <stdio.h>


int main(int argc, char *argv[])
{   
    char *p_c;
    FILE *kam = stdout;
    if (argc == 1)
    {
        printf("Zadajte nazov suboru, z ktoreho budeme citat\n");

        char nazov_s[30];
        scanf("%s", &nazov_s);
        p_c = nazov_s;
    }

    if (argc >= 2)
    {   
        if ((argv[1][0] == '-') && ((argv[1][1] == 'h') || (argv[1][1] == 'H')))
        {   
            printf("Prvy argument zmamena nazov suboru, z ktoreho budeme vypisovat (aj typ)\nDruhy argument znamena taktiez nazov suboru, do ktoreho budeme zapisovat\n");
            return 0;
        }

        p_c = argv[1];
        if (argc == 3)
        {
            if ((kam = fopen(argv[2], "w")) == NULL)
            {
                printf("Subor sa nepodarilo otvorit\n");
                return -1;;
            }
        }   
    }


    FILE *fr;
    fr = fopen(p_c, "r");
    // kontrola otvorenia
    if ((fr = fopen(p_c, "r")) == NULL)
    {
        printf("Subor sa nepodarilo otvorit\n");
        return -1;
    }


    char veta[501];
    while (fgets(veta, 502, fr) != NULL)
    {
        fprintf(kam, "%s", veta);
    }

    // kontrola zatvorenia
    if (fclose(fr) == EOF)
    {
        printf("Subor sa nepodarilo zavriet\n");
        return -1;
    }


    // kontrola zavretia premennej kam
    if (kam != stdout)
    {
        if (fclose(kam) == EOF)
        {
            printf("Subor sa nepodarilo zavriet\n");
            return -1; 
        }
    }

    return 0;
}


