#include <stdio.h>
#include <stdlib.h>


typedef struct prvek {
    int hodnota;
    struct prvek *dalsi;
} PRVEK;


int main()
{
    int pocet;   // pocet prvkov zoznamu
    PRVEK *p_akt, *p_prv, *p_pred;  // pointery na aktualny, prvy a predchozi prvok

    pocet = 15;

    if ((p_prv = (PRVEK *) malloc(sizeof(PRVEK))) == NULL)
    {
        printf("Malo pamate, chyba\n");
        return -1;
    }


    p_akt = p_prv; // akutalny nastavim na prvy

    p_prv->hodnota = 1; // hodnota v prvom prvku bude 1

    // zaplenenie dalsich prvkov

    int i;
    for (i = 2; i < pocet; i++)
    {
        if ((p_akt->dalsi = (PRVEK *) malloc(sizeof(PRVEK))) == NULL) // nastavenie pointeru na dalsi prvok, aby ukazol na nove pole
        {
        printf("Malo pamate, chyba\n");
        return -1;
        }

        p_akt = p_akt->dalsi; // aktualny sa zmeni na toto nove pole
        p_akt->hodnota = i;   // zapise sa do tohto noveho pola nova hodnota i
    }

    p_akt->dalsi = NULL; // ukoncenie pola








    return 0;
}