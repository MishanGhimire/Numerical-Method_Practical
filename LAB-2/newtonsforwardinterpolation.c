#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20], xp, diff[20][20], p, h, nr, dr, yp;

    // Step 5: Read n, x, y
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the values of x:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y:\n");
    for (i = 0; i < n; i++) {
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    // Step 6: Read xp
    printf("Enter the value of xp: ");
    scanf("%f", &xp);

    // Step 7: Calculate Differences
    h = x[1] - x[0];
    for (i = 0; i < n - 1; i++) {
        diff[i][1] = y[i + 1] - y[i];
    }

    for (j = 2; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    // Step 8: Calculate Interpolation
    p = (xp - x[0]) / h;
    yp = y[0];
    nr = 1.0;
    dr = 1.0;

    for (j = 1; j < n; j++) {
        nr *= (p - j + 1);
        dr *= j;
        yp += (nr / dr) * diff[0][j];
    }

    // Output interpolated value
    printf("Interpolated value at xp: %f\n", yp);

    return 0;
}
