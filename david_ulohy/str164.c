#include <stdio.h>

int main()
{
    double c;
    printf("Zadajte realne cislo: \n");
    scanf("%lf", &c);

    double *p_d;
    p_d = &c;
    printf("Cislo, ktore ste zadali ma hodnotu : %lf\n", *p_d);
    for (int i = 1; i <= sizeof(c); i++) {
        printf("Adresa bytu cislo %d. je %p\n", i, ((unsigned char *)p_d + i - 1));
    }

    return 0;
}