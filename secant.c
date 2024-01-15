#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x - 4;
}

int main()
{
    double x0, x1, x2, f0, f1, f2, e;
    int SN = 1;

    printf("\nThis CODE IS RUN BY  MISHAN GHIMIRE\n");
    printf("Enter the error criteria (e): ");
    scanf("%lf", &e);

    printf("Enter two initial guesses (x0 and x1): ");
    scanf("%lf %lf", &x0, &x1);

    printf("S.N\t x0\t x1\t x2\t f(x2)\n");

    while (fabs(f(x2)) > e)
    {
        f0 = f(x0);
        f1 = f(x1);
        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        f2 = f(x2);

        printf("%d\t%lf\t%lf\t%lf\t%lf\n", SN, x0, x1, x2, f2);

        x0 = x1;
        x1 = x2;
        SN++;
    }

    printf("Required root = %lf\n", x2);

    return 0;
}
