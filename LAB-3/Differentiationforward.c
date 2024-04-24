#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 20

// Function to calculate factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    // Declare variables
    float x[MAX_POINTS], y[MAX_POINTS], XP, h, first_derivative = 0.0;
    int n, i, j;

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input the data points (x, y)
    printf("Enter data:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    // Input the point at which the derivative is to be calculated
    printf("Enter the point at which the derivative is to be calculated: ");
    scanf("%f", &XP);

    // Calculate h (assuming evenly spaced data points)
    h = x[1] - x[0];

    // Calculate forward differences
    float forward_diff[MAX_POINTS][MAX_POINTS];
    for (i = 0; i < n; i++) {
        forward_diff[i][0] = y[i];
    }
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            forward_diff[i][j] = forward_diff[i + 1][j - 1] - forward_diff[i][j - 1];
        }
    }

    // Calculate u value
    float u = (XP - x[0]) / h;

    // Calculate first derivative using Newton's divided difference formula
    first_derivative = forward_diff[0][0];
    float u_term = 1.0;
    for (i = 1; i < n; i++) {
        first_derivative += (u_term * forward_diff[0][i]) / (factorial(i) * pow(h, i));
        u_term *= (u - i + 1);
    }

    // Output the result
    printf("First derivative at x = %.2f is %.2f\n", XP, first_derivative);
    printf("\n This code is run by Swagat kafle");

    // Return 0 to indicate successful execution
    return 0;
}
