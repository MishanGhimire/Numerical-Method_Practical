// Problem y' = x+y^2, y(0) = 1 , h= 0.1 , y(0.5)=? Ans: 2.234481
#include <stdio.h>
#include <math.h>
#define f(x, y) x + pow(y, 2)
int main()
{
    float x0, y0, h, xn, x, y, k1, k2, k3, k4, k, x1, y1;
    int n;
    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter no of steps h: ");
    scanf("%f", &h);
    n = (xn - x0) / h;
    x = x0;
    y = y0;
    for (int i = 0; i < n; i++)
    {
        k1 = f(x, y);
        k2 = f(x + (h / 2), y + k1 * (h / 2));
        k3 = f(x + (h / 2), y + k2 * (h / 2));
        k4 = f(x + h, y + k3 * h);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y1 = y + k * h;
        x1 = x + h;
        x = x1;
        y = y1;
        printf("\nValue of y(%f) = %f", x, y);
    }
    printf("\n\n Therefore, value of y at x = %0.2f is %f", x1, y1);
    return 0;
}