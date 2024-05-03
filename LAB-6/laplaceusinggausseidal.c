#include <stdio.h>
#include <math.h>

int main() {
    int SIZE_X, SIZE_Y, m = 0, max_iterations = 1000;
    float tolerance = 1e-6;
    printf("\n This code is run by Mishan Ghimire \n");
    printf("Enter number of steps in x direction: ");
    scanf("%d", &SIZE_X);
    printf("Enter number of steps in y direction: ");
    scanf("%d", &SIZE_Y);
    
    float grid[SIZE_X][SIZE_Y];
    float temp_grid[SIZE_X][SIZE_Y];
    
    // Input boundary values
    for (int i = 0; i < SIZE_X; i++) {
        printf("Enter value on bottom side U%d,0: ", i);
        scanf("%f", &grid[i][0]);
    }
    for (int i = 0; i < SIZE_X; i++) {
        printf("Enter value on top side U%d,%d: ", i, SIZE_Y - 1);
        scanf("%f", &grid[i][SIZE_Y - 1]);
    }
    for (int j = 1; j < SIZE_Y - 1; j++) {
        printf("Enter value on left side U0,%d: ", j);
        scanf("%f", &grid[0][j]);
    }
    for (int j = 1; j < SIZE_Y - 1; j++) {
        printf("Enter value on right side U%d,%d: ", SIZE_X - 1, j);
        scanf("%f", &grid[SIZE_X - 1][j]);
    }

    // Print initial grid values
    printf("\nInitial Grid Values:\n");
    for (int j = SIZE_Y - 1; j >= 0; j--) {
        for (int i = 0; i < SIZE_X; i++) {
            printf("\t%.2f ", grid[i][j]);
        }
        printf("\n");
    }    

    // Gauss-Seidel iteration
    float max_diff;
    do {
        max_diff = 0.0;
        for (int i = 1; i < SIZE_X - 1; i++) {
            for (int j = 1; j < SIZE_Y - 1; j++) {
                temp_grid[i][j] = grid[i][j];
                grid[i][j] = 0.25 * (grid[i + 1][j] + grid[i - 1][j] + grid[i][j + 1] + grid[i][j - 1]);
                float diff = fabs(grid[i][j] - temp_grid[i][j]);
                if (diff > max_diff) {
                    max_diff = diff;
                }
            }
        }
        m++;
    } while (max_diff > tolerance && m < max_iterations);

    // Print final grid values
    printf("\nFinal Grid Values after %d iterations:\n", m);
    for (int j = SIZE_Y - 1; j >= 0; j--) {
        for (int i = 0; i < SIZE_X; i++) {
            printf("\t%.2f ", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}
