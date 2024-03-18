 #include <stdio.h>
 #include <math.h>

typedef double (*P_INT)();

P_INT p_fd;

P_INT g(void)
{
    return (sqrt);
}

int main()
 {
    printf("%lf", (*(g()))(10.0));

    return 0;
 }