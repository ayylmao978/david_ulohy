#include <stdio.h>

typedef struct
{
    float f;
    char c;
    int d;
} A_struct;

typedef union
{
    float f, g, h, j;
    char c;
    int d;
} B_union;



int main()
{
    A_struct prve;

    B_union druhe;
    druhe.d = 257;


    printf("Adresa structu: %p\nAdresa unionu: %p\n", &prve, &druhe); // vzdy vypise adresy prvych premennych v danej strukture


    return 0;
}
