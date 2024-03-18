#include <stdio.h>

#define DOLNA       (-1)
#define HORNA         1
#define KROK          0.2

double foo1(double x)
{
    return (x*x + 8);
}


double foo2(double x)
{
    return(x*x*x - 3);
}



void tabulace(double d, double h, double k, double (*p_funkcia)())
{
    double pomocna;
    for (pomocna = d; pomocna <= h; pomocna+=k) {
        printf("%15.5lf \t %15.5lf \n", pomocna, (*p_funkcia)(pomocna));
    }

}


int main()
{
    tabulace(DOLNA, HORNA, KROK, foo2);

    return 0;
}