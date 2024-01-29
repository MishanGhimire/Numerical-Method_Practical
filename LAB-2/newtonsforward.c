#include<stdio.h>

int main()
{
    printf("This code is run by Mishan Ghimire.\n");
    int n,i,j,k;
	printf("\n Enter the no of data provided(n):");
	scanf("%d",&n);
	float x[20], y[20],diff[20][20],xp,p,h,nr=1.0,dr=1.0,yp;
    printf("\nEnter the values in form x,y:\n");
    for (i=0;i<=n-1;i++)
    scanf("%f %f",&x[i],&y[i]);
    printf("\nEnter the value of x for which the value of y is wanted: \n");
    scanf("%f",&xp);
    h=x[1]-x[0];
        for (i=0;i<n;i++)
        diff[i][1] = y[i+1]-y[i];
        for (j=2;j<n;j++)
        for(i=0;i<n-j;i++)
        diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
   		 p = (xp-x[0])/h;
    	 yp = y[0];
    for (k=1;k<n;k++)
    {
        nr *=p-k+1;
        dr *=k;
        yp +=(nr/dr)*diff[i][k];
    }
    printf("\nWhen x = %f, corresponding y = %f\n",xp,yp);
    return 0;
}

