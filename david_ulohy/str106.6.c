#include <stdio.h>

#define cti_int(i)      (((scanf("%d", &i)) != 0) ? i : 0)

int main()
{
    printf("Zadaj cislo na terminal\n");
    int k;
    k = cti_int(k);
    if (k)
        printf("%d", k);

    return 0;
}