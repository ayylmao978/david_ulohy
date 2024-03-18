#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fr, *fw;

    fr = fopen("texty\\PISMENA.TXT", "r");
    fw = fopen("texty\\KOLIK.TXT", "w");

    int c, pocet;

    while ((c = getc(fr)) != EOF) {
        putc(c, fw);
        if (c != '\n') {
            pocet += 1;
        }
        else {
            fprintf(fw, "Pocet malych znakov na danej riadke : %d\n\n", pocet);
            pocet = 0;
        }
    }

    fclose(fr); fclose(fw);

    return 0;
}