#include <stdio.h>

#define POCET   10

int sude(int x[], int y[], int pocet);

int pole1[POCET] = {2, 4, 6, 5, 2, 4, 3, 7, 8, 10};
int pole2[POCET] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};



int main()
{
    int pocet_prvkov = sude(pole1, pole2, POCET);
    printf("%d\n\n", pocet_prvkov);
    for (int i = 0; i < POCET; i++)
        printf("%d\n", pole2[i]);


}


int sude(int x[], int y[], int pocet)
{
    int *p_x = x;
    int i;
    int k = 0;
    for (i = 0; i < pocet; i++) {
        if (*(p_x + i) % 2 == 0)
            y[k++] = *(p_x + i);
    }
    return k;
}