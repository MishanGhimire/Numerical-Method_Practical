#include <stdio.h>
#include <math.h>

float f1(float y, float z)
{
    return (17 - y + 2 * z) / 20.0f;
}

float f2(float x, float z)
{
    return (-18 - 3 * x + z) / 20.0f;
}

float f3(float x, float y)
{
    return (25 - 2 * x + 3 * y) / 20.0f;
}

int main()
{
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
    int count = 1;
    // printf("This code is run by Mishan Ghimire. \n");
    // printf("This code is run by Sankalpa Chapagain. \n");
    printf("This code is run by Swagat Kafle. \n");



    printf("Enter tolerable error: ");
    scanf("%f", &e);

    printf("\nCount\tx\ty\tz\n");
    do
    {
        x1 = f1(y0, z0);
        y1 = f2(x1, z0);
        z1 = f3(x1, y1);

        printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);

        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);

        count++;

        x0 = x1;
        y0 = y1;
        z0 = z1;
    } while (e1 > e || e2 > e || e3 > e);

    printf("\nSolution: x=%0.3f, y=%0.3f, and z=%0.3f\n", x1, y1, z1);

    return 0;
}
