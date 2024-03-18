#include <stdio.h>
#include <ctype.h>


#define POCET       10

// cistenie bufferu
#define cisti()     while (getchar() != '\n')


// podobne  #define
typedef enum {
    CISLO = 'I',
    ZNAK = 'C'
}   TYP;

// vzdy obsahuje len jednu tuto hodnotu, bud CHAR alebo INT
typedef union {
    char c;
    int i;
}   CHARINT;

// slovnik ako v pythone, hodnota bude typu CHARINT - union - cize vzdy len jedna  hodnota - / bud INT alebo CHAR/
// typ bude typu TYP co je enum, co vlastne znamena ze tam bude bud 'I' alebo 'C', kedze CISLO a ZNAK su len ine nazvy pre dane znaky
typedef struct {
    CHARINT hodnota;
    TYP     typ;
} PRVEK;

// staticka globalna premenna
PRVEK pole[POCET]; // pole je pole desiatich PRVKOV

int main()
{
    int i, c;

    for (i = 0; i < POCET; i++)
    {   
        printf("%d. polozka : \ntyp : ", i + 1);
        c = toupper(getchar());
        cisti(); // zbavi sa znaku \n po napisani typu polozky

        switch (c) {
            case CISLO : // case 'I'
                pole[i].typ = CISLO; 
                printf("cislo : ");
                scanf("%d", &pole[i].hodnota.i);
                break;
            
            case ZNAK :
                pole[i].typ = ZNAK;
                printf("znak : ");
                scanf("%c", &pole[i].hodnota.c);
                break;
            
            default:
                printf("Neznamy typ, zadajte (ENTER)\n");
                break;
        }
        cisti(); // po switch sa tiez musime zbavit newline characteru, lebo sme tiez zadali \n
    }
    // tlacenie nacitanych hodnot
    for (i = 0; i < POCET; i++)
    {
        if (pole[i].typ == CISLO)
            printf("%d. polozka = %d \n", i+1, pole[i].hodnota.i); // idem na prvok v poli na indexi i, chcem hodnotu ktora je typu charint, a vyberiem si typ INT cize i
        else
            printf("%d. polozka = %c \n", i+1, pole[i].hodnota.c); /*idem na prvok v poli na indexi i, chcem hodnotu ktora je typu charint, a vyberiem si typ CHAR cize c
                                                                     ale v CHARINT je akokeby len jedna hodnota*/
    }

    return 0;
}