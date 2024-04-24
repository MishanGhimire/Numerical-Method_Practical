#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x - 4;
}

double g(double x)
{
    return sqrt(x + 4);
}

int main()
{
    double x0, x1, f1, e;
    int SN = 1, max_iterations = 10; // Set a maximum iteration limit

    printf("\nThis CODE IS RUN BY  MISHAN GHIMIRE\n");
    printf("Enter the error criteria (e): ");
    scanf("%lf", &e);

    printf("Enter the initial guess (x0): ");
    scanf("%lf", &x0);

    printf("S.N\t x0\t x1\t f(x1)\n");

    x1 = g(x0);

    while (fabs(f(x1)) > e && SN <= max_iterations)
    {
        f1 = f(x1);

        printf("%d\t%lf\t%lf\t%lf\n", SN, x0, x1, f1);

        x0 = x1;
        x1 = g(x0);
        SN++;
    }

    printf("Required root = %lf\n", x1);

    return 0;
}
