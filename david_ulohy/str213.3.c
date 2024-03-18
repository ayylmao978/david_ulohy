#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>




void sort(char p_string[], char p_sortedstring[])
{
    int i, k;
    int dlzka = strlen(p_string);
    int pos, pom, max;
    pos = pom = 0;
    char znak;

    for (k = 0; k < dlzka; k++)
    {
        max = 122;
        for (i = 0; i < dlzka; i++)
        {
            znak = p_string[i];
            if (znak == '\0')
              continue;
            znak = tolower(znak);
            if (znak <= max)
            {
                max = znak;
                pom = i;
            }
        }
        p_string[pom] = '\0';
        p_sortedstring[k] = (char) max;
    }
}

int main()
{
    char retezec1[21]; // '\0'
    char retezec2[21];
    printf("Zadajte slovo\n");
    fgets(retezec1, 22, stdin);  // '\0' && '\n'

    // zbavenie sa '/n'
    char *p_pom = strrchr(retezec1, '\n');
    *p_pom = '\0';

    sort(retezec1, retezec2);

    printf("%s", retezec2);

    return 0;
}