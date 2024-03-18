#include <ctype.h>
#include <stdio.h>

#define je_velke(x)     (((x) >= 'A' && ((x) <= 'Z')) ? 1 : 0) // nechapem preco nemozem pouzit return 1 a return 0 ??

int main()
{
    int p = 96, hodnota;
    printf("Zadajte pismeno : ");
    p = getchar();
    hodnota = je_velke(p);
    printf("%d", hodnota);
    return 0;
}