#include<stdio.h>


int MinPlace(int a[],int L,int n)
{
	int mE,mL,i;
	mE=a[L];
	mL=L;
	for(i=L+1;i<=n-1;i++)
	{
		if(mE>a[i])
		{
			mE=a[i];
			mL=i;
		}
	}
	return(mL);
}


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
		j=MinPlace(&a[0],i,n);
		if(i!=j)
		{
			a[i]=a[i]+a[j];
			a[j]=a[i]-a[j];
			a[i]=a[i]-a[j];
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