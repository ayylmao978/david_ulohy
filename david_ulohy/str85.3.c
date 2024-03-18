#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fr;
    fr = fopen("texty\\PISMENA.TXT", "r");
    int pocet_znakov = 0;
    do {
        pocet_znakov += 1;
    } while (getc(fr) != EOF);

    printf("Pocet znakov v subore pismena.txt je : %d", pocet_znakov);
    
    return 0;
}