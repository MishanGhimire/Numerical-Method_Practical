#include <stdio.h>
#include <conio.h>
#include <math.h>

/* Define function here */
#define f(x) 1 / (1 + x * x)

int main()
{
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;

    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);

    // Validate input and swap if lower > upper
    if (lower > upper) {
        float temp = lower;
        lower = upper;
        upper = temp;
    }

    printf("Enter number of sub intervals: ");
    scanf("%d", &subInterval);

    /* Calculation */
    /* Finding step size */
    stepSize = (upper - lower) / subInterval;

    /* Finding Integration Value */
    integration = f(lower) + f(upper);
    for (i = 1; i <= subInterval - 1; i++)
    {
        k = lower + i * stepSize;
        if (i % 3 == 0)
        {
            integration = integration + 2 * f(k);
        }
        else
        {
            integration = integration + 3 * f(k);
        }
    }
    integration = integration * stepSize * 3 / 8;
    printf("\nRequired value of integration is: %.3f", integration);
    // printf("\nThis code is run by Mishan Ghimire\n");
    printf("\n This code is run by Swagat Kafle");

    getch();
    return 0;
}
