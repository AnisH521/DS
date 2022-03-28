#include<stdio.h>

int main()
{
    int i,j,k,n;
    printf("How many elements you want to enter inside the array?\n");
	scanf("%d",&n);
	int a[n];
	for(k=0;k<n;k++)
	{
		printf("\nEnter the value you want to enter inside Array\n");
		scanf("%d",&a[k]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=a[j]+a[j+1];
			    a[j+1]=a[j]-a[j+1];
			    a[j]=a[j]-a[j+1];
			}
		}
	}
	printf("\nThe sorted elements are\n");
	printf("\n===========================================================\n");
	for(k=0;k<n;k++)
	{
		printf("\t%d",a[k]);
	}
	printf("\n===========================================================\n");

	return 0;
}
