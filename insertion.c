#include<stdio.h>


int insertion_Sort(int a[],int n)
{
	int s,t,i,j,x;
	for(j=1;j<n;j++)
	{
		x=1;
		s=a[j];
		i=j-1;
		while(x==1)
		{
			if(s<a[i])
			{
				i=i-1;
				if(i==-1)
				{
					x=0;
				}
			}
			else
				x=0;
		}
		t=j;
		while(t>i+1)
		{
			a[t]=a[t-1];
			t=t-1;
		}
		a[i+1]=s;
	}
	printf("\n========================================================================================\n");
	printf("\nThe Elements After Sorting = ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\n========================================================================================\n");
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
	printf("\nThe Elements You Entered =");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	insertion_Sort(&a[0],n);
	return 0;
}