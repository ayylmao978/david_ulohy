#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fr;
    fr = fopen("texty/CISLA.TXT", "r");

    double p, sucet = 0;
    int pocet = 0;
    while ((fscanf(fr, "$%lf\n", &p)) == 1) {
        pocet += 1;
        sucet += p;
    }
    printf("Priemer je : %0.2lf", sucet / pocet);
        
    return 0;
}   