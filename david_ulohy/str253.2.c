#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    char jmeno[21];
    int stari;
} A_STCT;



void napln(A_STCT *p, char meno[], int vek);

int main()
{
    A_STCT prva_stack;
    
    napln(&prva_stack, "Tomas", 18);
    
    A_STCT *p_heap = (A_STCT *) malloc(sizeof(A_STCT));
    napln(p_heap, "Bober", 17);

    printf("Prva struktura na stacku: %s, %d\nDruha struktura na heape: %s, %d\n", prva_stack.jmeno, prva_stack.stari, p_heap->jmeno, p_heap->stari);

    free((void *)p_heap);

    return 0;

}


void napln(A_STCT *p, char meno[], int vek)
{
    strcpy(p->jmeno, meno);
    p->stari = vek;
}