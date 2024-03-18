#define lze_tisknout(c)    ((((c) >= 32) && ((c) <= 126)) ? c : 0)
#include <stdio.h>

int main()
{
    int g;

    for (g = 0; g < 255; g++) {
        if (lze_tisknout(g))
        printf("%c", lze_tisknout(g));
    }

    return 0;
}