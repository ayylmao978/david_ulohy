#include <stdlib.h>
#include <stdio.h>

int *spocitaj_znaky(FILE *fr) // funkcia spocita pocet jednotlivych znakov v subore s pointerom fr a vrati pointer na mallocovane pole s poctami
{
    // vytvorenie pola - prva polovica VELKE pismena - druha polovica male pismena
    // na zaciatku budu vsetky inicializovane na hodnotu 0


    // nulovanie pola
    int *arr = (int*)malloc(52 * sizeof(int));
    for (int i = 0; i < 52; i++) {
        *(arr + i) = 0;
    }

    // prechadzanie suborom a zapocet znakov
    int c;
    while ((c = getc(fr)) != EOF) {
        if ((c <= 'Z') && (c >= 'A')) {
            *(arr + (c - 'A')) += 1; // pri znaku A bude index 0
        }
        else if ((c <= 'z') && (c >= 'a')) {
            *(arr + (c - 'a' + 26)) += 1; // pri znaku a bude index 26
        }
    }
    return arr;

}


int main()
{
    FILE *fr = fopen("texty/PISMENA.TXT", "r");
    // test na spravne otvorenie suboru
    if (fr == NULL) 
        return -1;
    
    int *p_pole = spocitaj_znaky(fr);
    for (int i = 0; i < 26; i++) {
        printf("Znak %c sa vyskytol %d-krat\n", (65+i), p_pole[i]);
    }

    for (int i = 26; i < 52; i++) {
        printf("Znak %c sa vyskytol %d-krat\n", (71+i), p_pole[i]);
    }

    free((void *)p_pole);
    p_pole = NULL;
    return 0;


}