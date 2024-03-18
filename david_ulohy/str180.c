#include <stdio.h>

int main()
{
    int x[4];
    for (int i = 0; i < 4; i++) {
        x[i] = i + 1;
    }

    printf("%d \n", *(x + 1));

    printf("%d \n", *((char *) x + sizeof(int)));



    return 0;
}