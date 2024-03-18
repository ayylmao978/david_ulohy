#include <stdio.h>



int main()
{
    int matica[10][10];
    
    int i, k;
    int pocet = 0;

    for (i = 0; i < 10; i++)
    {
        for (k = 0; k < 10; k++)
        {   
            matica[i][k] = pocet++;

            if (i == 0)
                printf("0%d ", matica[i][k]);
            else
                printf("%d ", matica[i][k]);
        }
        putchar('\n');
    }


    return 0;
}