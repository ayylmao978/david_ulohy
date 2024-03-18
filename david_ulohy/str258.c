#include <stdio.h>

int main()
{
    short int i = 5; //         0000 0000 0000 0101

    // vynasobeni cislom 80
    short int k = i*80; //      0000 0001 1001 0000 = 400

    // alebo to spravim rychlejsie pomocou manipulacie bitov

    i = (i << 6) + (i << 4); // (0000 0001 0100 0000 = 320 ) + (0000 0000 0101 0000 = 80)
    // je to fes necitatelne ale rychlejsie, i ked si myslim ze dnesne kompilery to robia za nas pri kompilacii



    return 0;
}