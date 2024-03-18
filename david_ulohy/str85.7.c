#include <stdio.h>
#include <stdlib.h>

int main()
{  
    FILE *fr;
    fr = fopen("texty/PISMENA.TXT", "r");

    if (fr == NULL) {
        printf("Subor sa nepodarilo otvorit");
        return 1;
    }

    printf("Ak chcete znaky vypisovat na obrazovku, stlacte cislo 1, inak stlacte enter a budu sa vypisovat do suboru :");

    int c;

    if (getchar() == '1') {
        while ((c = getc(fr)) != EOF) {
            putc(c, stdout);
        }
    }

    else {
        FILE *fw;
        fw = fopen("texty/NOVY.TXT", "w");
        while ((c = getc(fr)) != EOF) {
            putc(c, fw);
        }
        fclose(fw);
    }

    fclose(fr);

    return 0;
}