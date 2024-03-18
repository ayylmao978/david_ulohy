#include <stdio.h>
#include <stdlib.h>

#define VELKOST     10



int poley[10];

void zorad_vzostupne(int x[], int y[], int pocet)
{
    int *p_polex = x;
 
    int max;
    int hodnota, poloha;
    int i, k;

    for (i = pocet-1; i != -1; i--) {
        max = 0;
        // najdenie najvacsej hodnoty z 10 prvkov
        for (k = pocet-1 ; k != -1 ; k--) {
            hodnota = *(p_polex + k);
            if (hodnota >= max) {
                max = hodnota;
                poloha = k;
            }
        }
        // zapisanie najvacsieho cisla na koniec pola y
        y[i] = max;

        // odstranenie najdenej hodnoty z pocodneho listu
        *(p_polex + poloha) = INT_MIN; // nastavenie najmensej moznej hodnoty

    }
    // prejdem cely list a budem hladat najvacsie hodnoty
    // najvacsiu hodnotu zapisem na koniec (zoradujem vzostupne)
    // potom ju z povodneho zoznamu odstanim a opakujem dokopy 10x
}


int main()
{
    int polex[VELKOST] = {1, 1, 1, 9, 4, 23, 61, 6, 87, 2};

    //zorad_vzostupne(pole, zoradene, VELKOST);
    zorad_vzostupne(polex, poley, VELKOST);
    for (int i = 0; i < VELKOST; i++)
        printf("%d\n", poley[i]);

    return 0;
}