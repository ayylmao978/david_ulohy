#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fr;
    
    fr = fopen("ZNAKY.TXT", "r");

    if (fr == NULL) {
        printf("Subor sa nepodarilo otvorit");
        return 1;
    }

    int character;

    do
    {   
        switch (character = getc(fr))
        {
        case '1':
            printf("\nBola to jednicka ");
            break;

        case '0':
            printf("\nBola to nula ");
            break;

        default:
            printf("%c", character);
            break;
        }

    } while (character != EOF && character != 'q');
    
    if (fclose(fr) == EOF) {
        printf("Subor sa nepodarilo zavriet");
        return 2;
    }

    return 0;
}