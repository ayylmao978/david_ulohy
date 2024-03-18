#include <stdio.h>
#include <string.h>
#include <ctype.h>


void hladaj_vypis(char *nazov_suboru, char *substring, int c, int n);


int main(int argc, char **argv)
{   
    char *p_substring = argv[2];
    int c = 0, n = 0;
    //  kontrola znakov na 3 pozicii
    if (argc == 4)
    {
        if (strlen(argv[3]) >= 1)
        {
            switch (argv[3][0])
            {
                case 'c':
                    c = 1;
                    break;
                case 'n':
                    n = 1;
                    break;
                default:
                    break;
            }
            if (strlen(argv[3]) == 2)
            {
                switch (argv[3][1])
            {
                case 'c':
                    c = 1;
                    break;
                case 'n':
                    n = 1;
                    break;
                default:
                    break;
            }
            }
            else if (strlen(argv[3]) > 2)
                printf("Chyba 1\n");
        }
        // ak dlzka je 0?
        else
            printf("Chyba 2\n");
    }

    hladaj_vypis(argv[1], p_substring, c, n);
}

void hladaj_vypis(char *nazov_suboru, char *substring, int c, int n)
{
    FILE *fr = fopen(nazov_suboru, "r");
    char veta[501];
    unsigned int riadok_poradie = 0;
    while (fgets(veta, 502, fr))
    {
        riadok_poradie++;
        if (c == 1)
        {
            if (n == 1) // c == 1, n == 1 // HOTOVO
            {
                if (strstr(veta, substring) != NULL)
                {   
                    printf("Riadok %d.:%s", riadok_poradie,  veta);
                }
            }
            else // c == 1, n == 0 HOTOVO
            {
                if (strstr(veta, substring) != NULL)
                {
                    printf("%s", veta);
                }
            }

        
        }
        else // c == 0, musim prieviest vetu aj substring na male a tak tam hladat
        {   
            int i;
            char novaveta[501];

            // zmensenie vety
            for (i = 0; i < 502; i++)
            {
                if (veta[i] == '\n')
                {
                    novaveta[i] = '\n';
                    novaveta[++i] = '\0';
                    break;
                }
                novaveta[i] = tolower(veta[i]); // zmensenie znakov
            }



            // zmensenie substringu
            int k = 0;
            while (substring[k] != '\0')
            {
                substring[k] = tolower(substring[k]);
                k++;
            }


            if (n == 1) // n == 1, c == 0
            {
                if (strstr(novaveta, substring) != NULL)
                {   
                    printf("Riadok %d.:%s", riadok_poradie, veta);
                }
            }
            else // n == 0, c == 0
            {
                if (strstr(novaveta, substring) != NULL)
                {
                    printf("%s", veta);
                }
            }
        }
    }





}