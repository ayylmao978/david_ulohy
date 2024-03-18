#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char jmeno[30];
    int rocnik;
}   STUDENT;


STUDENT *vytvor1(void) // vracia pointer na typ student
{
    STUDENT *p_pom;
    p_pom = (STUDENT *) malloc(sizeof(STUDENT));
    if (p_pom == NULL)
        printf("Malo pamati\n");

    return p_pom; // vytvorenie STUDENT na heape a vratenie pointeru na tu adresu
}


void vytvor2(STUDENT **p_s)
{
    *p_s = (STUDENT *) malloc(sizeof(STUDENT));

    if (*p_s == NULL)
        printf("Malo pamati\n"); // vytvorenie STUDENT na heape ale adresa sa dava do hodnoty parametra - nic nevraciam len menim hodnotu pointeru v parametri
}


void nastav(STUDENT *p_s, char *meno, int rok) // menim STUDENT vlastnosti vdaka adrese v parametri
{
    p_s->rocnik = rok;
    strcpy(p_s->jmeno, meno);
}


int main()
{
    STUDENT s, *p_s1, *p_s2;

    p_s1 = vytvor1();
    vytvor2(&p_s2);

    s.rocnik = 3;
    p_s1->rocnik = s.rocnik + 1;
    p_s2->rocnik = 5;
    nastav(&s, "Honza", 4);


    return 0;
}
