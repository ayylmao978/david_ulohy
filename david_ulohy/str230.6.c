#include <stdio.h>

void napln(int pole[][10]);
void tiskni(int pole[][10]);

int main()
{   
    auto int pole[10][10]; // auto je default takze moze byt vynechane

    napln(pole);
    tiskni(pole);
    return 0;
}



void napln(int pole[][10])
{   
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            pole[i][j] = i*10 + j;
        }
    }
}


void tiskni(int pole[][10])
{   
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", pole[i][j]);
        }
        putchar('\n');
    }
}