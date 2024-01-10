#include <stdio.h>
#include <math.h>

#define f(x) (x-cos(x))

int main()
{
    float x1, x2, x0, f1, f2, f0, e;
    int Sn = 1;
    printf("\nThis CODE IS RUN BY  MISHAN GHIMIRE\n");
    printf("\nEnter the error criteria:");
    scanf("%f", &e);

up:
    printf("\nEnter two initial guesses: ");
    scanf("%f%f", &x1, &x2);
    f1 = f(x1);
    f2 = f(x2);
    if ((f1 * f2) > 0)
    {
        printf("\nWRONG Initial Guess\n");
        goto up;
    }

    printf("\nSN\t\tx1\t\tx2\t\tx0\t\tf(x0)\n");
    do
    {
        x0 = (x1 + x2) / 2;
        f0 = f(x0);
        printf("%d\t\t%f\t%f\t%f\t%f\n", Sn, x1, x2, x0, f0);

        if ((f0 * f1) < 0)
        {
            x2 = x0;
            f2 = f0;
        }
        else
        {
            x1 = x0;
            f1 = f0;
        }

        Sn++;

    } while (fabs(f0) > e);

    printf("\nRequired root = %f\n", x0);

    return 0;
}
