#include <stdio.h>

void vymen(int *px, int *py)
{
    int pomocna;
    pomocna = *px;
    *px = *py;
    *py = pomocna;
}

int main(int argc, char *argv[])
{

    int i = 5, j = 3;

    vymen(&i, &j);

    printf("i = %d, j = %d", i, j);
    return 0;
}
