#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;
    // printf("This code is run by Mishan Ghimire. \n");
    printf("This code is run by Sankalpa Chapagain. \n");


    printf("Enter number of unknowns: ");
    scanf("%d", &n);
    printf("Enter coefficients of Augmented Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
                
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        x[i] = a[i][n] / a[i][i];
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %0.3f\n", i + 1, x[i]);
    }

    return 0;
}
