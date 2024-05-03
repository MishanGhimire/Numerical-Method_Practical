// Problem y' = x+sqrt(y), y(0) = 1 , h= 0.2 , y(2)=? Ans: 1.881930
#include <stdio.h>
#include <math.h>

#define f(x, y) (x + sqrt(y))

int main() {
    printf("This code is run by Mishan Ghimire.\n");

    float x0, y0, h, xn, x, y, k1, k2, k, y1;
    int n;
    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter step size h: ");
    scanf("%f", &h);
    n = (int)((xn - x0) / h);
    x = x0;
    y = y0;
    for (int i = 0; i < n; i++) {
        k1 = f(x, y);
        k2 = f(x + h, y + k1 * h);
        k = 0.5 * (k1 + k2);
        y1 = y + (k * h);
        x += h;
        y = y1;
        printf("\nValue of y(%f) = %f", x, y);
        if (fabs(x - xn) < 0.0001) // Check if x is close enough to xn within a tolerance
            break;
    }
    printf("\n\nTherefore, value of y at x = %0.2f is %f\n", xn, y); // Print the value of y at xn
    return 0;
}
