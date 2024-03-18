#include <stdio.h>

// NEFUNGUJE MI TATO BLBOST

int main()
{
    printf("Citat z Klavesnice (K) alebo zo Suboru (S)? [K/S] :\n");
    int choice = getchar();
    int cislo, pocet_parnych = 0;
    int otvor = 1;
    int fr;
    for (int i = 0; i < 10; i++) {

        printf("Zadaj %d. cislo", i);
        // getchar();

        if (choice == 'S') {
            if (otvor) {
                FILE *fr;
                fr = fopen("texty/cisla2.txt", "r");
                otvor = 0;
            }
            cislo = fscanf(fr, "%d", &cislo);
        }

        else {
            if (choice == 'K') {
            cislo = scanf("%d", &cislo);
            }
            else {
                return 1;
            }
        }
        if ((cislo % 2) == 0) {
            pocet_parnych += 1;
        }
    }

    printf("Pocet parnych cisel je: %d", pocet_parnych);
    if (otvor == 0)
        fclose(fr);
    return 0;
}