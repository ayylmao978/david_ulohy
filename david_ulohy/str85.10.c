#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int cislo, odpoved;
    int pokracuj = 1; // True

    for (cislo = 1; pokracuj; cislo++) {
        if ((cislo % 10) == 0) {
            printf("Mam pokracovat? [A/N] ");
            odpoved = getchar();
            getchar(); // Nacitanie '\n' *naprazdno* aby mi ten znak pri dalsom zadavani nezapocitalo
            if (odpoved == 'A') {
                pokracuj = 1;
            }
            else {
                if (odpoved != 'N')
                    printf("Zly znak, ukoncujem program . . .\n");
                pokracuj = 0;
            }
    
    
        }
    }
    cislo -= 1;
    printf("Dostali sme sa po cislo %d", cislo);

    return 0;
}