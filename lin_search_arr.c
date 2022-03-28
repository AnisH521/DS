#include<stdio.h>


int sear(int a[],int n)
{
	int i,y;
	i=0;
	printf("\n\nEnter the value you want to search\n");
	scanf("%d",&y);
	pm :
	if(y==a[i])
		{
			printf("\n========================================================================================\n");
			printf("\nthe value is at location %d",i);
			printf("\n========================================================================================\n");
			return 0;
		}
	else
	{
		i=i+1;
		if(i<=n)
			goto pm;
		else
			{
				printf("\nSorry The required element does not exist\n");
				return 0;
			}
	}
	return 0;
}


int main()
{
	int i,n;
	printf("How many elements you want to enter inside the array?\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("\nEnter the value you want to enter inside Array\n");
		scanf("%d",&a[i]);
	}
	printf("\n========================================================================================\n");
	printf("\nThe elements you entered =");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\n========================================================================================\n");
	sear(&a[0],n);
	return 0;
}
