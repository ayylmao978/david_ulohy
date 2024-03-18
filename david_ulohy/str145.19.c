#include <stdio.h>
#include <time.h>
#define MAX     5000

int i;
int j;

int main()
{
    clock_t begin = clock();
    // register int i; 
    // register int j;

    // s register je to omnoho rychlejsie !!
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            i = i;
            j = j;
        }
    }
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf", time_spent);
    return 0;
}