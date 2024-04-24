#include <stdio.h>

int main()
{

    // printf("This code is run by Mishan Ghimire.\n");
    printf("\n This code is run by Swagat kafle");


    int n, i;
    float sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0, a, b;

    /* Input */
    printf("How many data points?\n");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Error: Please enter a valid positive integer for the number of data points.\n");
        return 1; // Exit with an error code
    }

    if (n > 100)
    {
        printf("Error: The program currently supports up to 100 data points. Please reduce the number of data points.\n");
        return 1; // Exit with an error code
    }

    float x[100], y[100]; // Assuming a maximum of 100 data points

    printf("Enter data:\n");

    for (i = 0; i < n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);

        printf("y[%d]=", i);
        scanf("%f", &y[i]);
    }

    /* Calculating Required Sum */
    for (i = 0; i < n; i++)
    {
        sumX = sumX + x[i];
        sumX2 = sumX2 + x[i] * x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + x[i] * y[i];
    }

    /* Check for division by zero */
    if (n * sumX2 - sumX * sumX == 0)
    {
        printf("Error: Division by zero. Unable to calculate coefficients.\n");
        return 1; // Exit with an error code
    }

    /* Calculating a and b */
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;

    /* Displaying value of a and b */
    printf("Values are: a=%0.2f and b = %0.2f", a, b);
    printf("\nEquation of best fit is: y = %0.2f + %0.2fx", a, b);

    return 0;
}
