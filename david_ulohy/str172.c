#include <stdlib.h>

void init(double **p_f)
{
    *p_f = ((double *) malloc(10 * sizeof(double)));
}


int main()
{   
    double a = 6.44;
    double *p_dbl;
    p_dbl = &a;
    init(&p_dbl);
    

    free((void *)p_dbl);
    return 0;
}