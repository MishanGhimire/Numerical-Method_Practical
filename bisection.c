#include <stdio.h>
#include <math.h>

double f(double x)
{

    return pow(x, 3) - 4 * x - 9;
}

int main()
{

    double x0, x1, x2, f0, f1, f2, e;
    int SN = 1;
    printf("\nThis CODE IS RUN BY  MISHAN GHIMIRE\n");
    printf("Enter the error criteria (e): ");
    scanf("%lf", &e);

up:

    printf("Enter two initial guesses (x1 and x2): ");
    scanf("%lf %lf", &x1, &x2);

    f1 = f(x1);
    f2 = f(x2);

    if (f1 * f2 > 0)
    {
        printf("Wrong Initial Guesses!!\n");
        goto up;
    }

    printf("S.N\t   x1\t   x2\t   x0\t   f(x0)\n");

    while (fabs(f(x0)) > e)
    {

        x0 = (x1 + x2) / 2;

        f0 = f(x0);

        printf("%d\t%lf\t%lf\t%lf\t%lf\n", SN, x1, x2, x0, f0);

        if (f0 * f1 < 0)
        {
            x2 = x0;
            f2 = f0;
        }
        else
        {
            x1 = x0;
            f1 = f0;
        }

        SN++;
    }

    printf("Required Root is: %lf\n", x0);

    return 0;
}
