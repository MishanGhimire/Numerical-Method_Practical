#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x - 4;
}

double g(double x)
{
    return 2 * x;
}

int main()
{
    double x0, x1, f0, f1, g0, e;
    int SN = 1;

    printf("\nThis CODE IS RUN BY MISHAN GHIMIRE\n");
    printf("Enter the error criteria (e): ");
    scanf("%lf", &e);

    printf("Enter the initial guess (x0): ");
    scanf("%lf", &x0);

    printf("S.N\t x0\t\t x1\t\t f(x0)\t\t f(x1)\n");

    x1 = x0 - (f(x0) / g(x0)); 

    while (fabs(f(x1)) > e)
    {
        f0 = f(x0);
        g0 = g(x0);
        x1 = x0 - (f0 / g0);
        f1 = f(x1);

        printf("%d\t%lf\t%lf\t%lf\t%lf\n", SN, x0, x1, f0, f1);

        x0 = x1;
        SN++;
    }

    printf("Required Root is: %lf\n", x1);

    return 0;
}
