#include "str192.3.POZDRAVY.c" // ma include <stdio.h>
#include <ctype.h>

void (*pole_p_f[4])() = {ahoj, nazdar, vitaj, cau};

int main()
{

    char pole_znakov[4] = {'a', 'n', 'v', 'c'};

    int c;
    printf("Zadavajte znaky :\n");
    while (isalpha(c = getchar())) {
        // vycistenie bufferu
        getchar();
        int i;

        // najdenie pozicie v liste pole znakov
        for (i = 0; i < 4; i++) {
            if (pole_znakov[i] == c) {

            pole_p_f[i]();
            break;
            }
        }
    }

    return 0;
}
