// Problem y' = x+y, y(0) = 0 , h= 0.2 , y(1)=?
#include <stdio.h>
#define f(x, y) (x + y)
int main()
{
    float x0, y0, xn, h, yn;
    int i, n;

    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter h: ");
    scanf("%f", &h);

    n = (xn - x0) / h;

    for (i = 0; i <= n; i++)
    {
        yn = y0 + h * f(x0, y0);
        y0 = yn;
        x0 += h;
        printf("\n y(%0.2f) = %0.5f", x0, y0);
    }

    printf("\n\nTherefore, value of y at x = %0.2f is %0.5f\n", xn, yn);
    printf("This code is run by Mishan Ghimire");
    return 0;
}
