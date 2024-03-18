/*
Dolna trojuholnikova matica
*/

#include <stdlib.h>
#include <stdio.h>


int main()
{
    // pole desiatich prvkov typu pointer na int
    int *pole[10];
    int i, j;


    for (i = 0; i < 10; i++) // idem po riadkoch
    {
        pole[i] = (int *)malloc(sizeof(int) * (i + 1));
    }


    return 0;
}