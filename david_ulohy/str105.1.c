#define N    5
#include <stdio.h>

int main()
{
    int i, sucet = 0;
    for (i = 1; i <= N; i++) {
        sucet += i;
    }

    printf("Sucet prvych %d cisel je %d", N, sucet);

    return 0;
}
