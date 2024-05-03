#include <stdio.h>
#include <math.h>

#define f(x, y) (x + pow(y, 2))

int main() {
    float x0, y0, h, xn, x, y, k1, k2, k3, k4, k;
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
    n = (xn - x0) / h;
    x = x0;
    y = y0;
    for (int i = 0; i < n; i++) {
        k1 = f(x, y);
        k2 = f(x + h / 2, y + k1 * h / 2);
        k3 = f(x + h / 2, y + k2 * h / 2);
        k4 = f(x + h, y + k3 * h);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y += k * h;
        x += h;
        printf("\nValue of y(%f) = %f", x, y);
    }
    printf("\n\nTherefore, value of y at x = %0.2f is %f", xn, y);
    return 0;
}
