#include <stdlib.h>
#include <stdio.h>


#define ERROR           perror("Chyba")
#define CLEAR           1
#define BITS_IN_CHAR    8

int bit(unsigned x, unsigned i)
{
    if (i >= sizeof(x) * BITS_IN_CHAR)  ERROR;
    else   return ((x >> i) & CLEAR); // keby nedam & CLEAR, tak (x >> i) bude len cislo posunute doprava, cize len podelene i-tou mocninou dvojky
                                      // vdaka clear vraciam len POROVANIE *AND* na poslednom bite, ktory bude po posunuti ten bit, ktory hladame a zvysok cisla sa voboec nevypise
}

int main()
{
    unsigned char k = 78; // 0100 1110
    unsigned char g = 2;


    printf("Hodnota %d-teho bitu v cisle %d je: %d\n", g, k, bit(k, g));

    return 0;
}