#include <stdio.h>
#include <stdlib.h>

void init(double **p_pole)
{   
    double *pole = *p_pole;
    p_pole = (double *)*p_pole;
    for (int i = 0; i < 5; i++) {
        *(pole) = 4.2314 * (i - 7.32);
    }
} 

int main()
{
    double *zoznam = malloc(5*sizeof(double));
    double *p_na_pole = &zoznam;
    init(p_na_pole);

    //free(*(void *)p_na_pole);
    return 0;

}   