#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fw;
    fw = fopen("texty\\CISLA.TXT", "w");

    int i;
    float pi = 3.14;

    for (i = 1; i <= 20; i++) {
        fprintf(fw, "$%.2f\n", i*pi);
    } 

    return 0;
}