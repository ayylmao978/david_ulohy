#include <stdio.h>

int main()
{
    int znak = getchar();
    getchar();
    if (znak == 'd') {
        int znak2;
        printf("Zadajte cele cislo :\n");
        scanf("%d",&znak2);
    
    }
    else if (znak == 'f') {
        double znak3;
        printf("Zadajte realne cislo :\n");
        scanf("%lf",&znak3);
    }
}
