#include <stdio.h>




void ahoj()
{   
    static int i = 1;
    printf("Cislo %d \t Ahoj\n", i);
    i++;
}


int main()
{
    void (*p_f)() = ahoj;
    for (int i = 0; i < 10; i++) {
        (*p_f)();
    }

    return 0;
}