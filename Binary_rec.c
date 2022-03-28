/******************************

 NAME : Anish Naskar
 M.Sc Data Science
 SEM 1

 Binary_Search(recursive)

 *****************************/

#include<stdio.h>
#include<math.h>


int Sort(int a[],int n)
{
	int i,j,k;
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
	printf("\nThe elements after sorting in ascending order\n");
	printf("\n===========================================================\n");
	for(k=0;k<n;k++)
	{
		printf("\t%d",a[k]);
	}
	printf("\n===========================================================\n");
	return 0;
}


int Binary(int L,int T,int z,int a[])
{
	int flag=0,M;
	if(flag==0 && L>T)
	{
		printf("\nThe Element is not present in the array\n");
		return 0;
	}
	M=ceil((L+T)/2);
	if(z==a[M])
	{
		printf("\nThe location of the element is %d\n",M);
		printf("-----------------------------------------------------------\n");
		flag=1;
		return 0;
	}
	else if(z<a[M])
	{
		Binary(L,M-1,z,&a[0]);
	}
	else if(z>a[M])
	{
		Binary(M+1,T,z,&a[0]);
	}
	return 0;
}


int main()
{
	int L=0,s,i,n,T;
	char choice;

	up :
	L=0;
	printf("\nHow many elements you want to enter inside the array?\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("\nEnter the value you want to enter inside Array\n");
		scanf("%d",&a[i]);
	}

	T=n-1;

	Sort(&a[0],n);

	printf("\nEnter the value you want to search\n");
	scanf("%d",&s);

	Binary(L,T,s,&a[0]);

	printf("\nDo you want to Create Another Array and continue searching (y/n)?\n");
	scanf("%s",&choice);
	if(choice=='y')
	{
		goto up;
	}
	else if(choice=='n')
		{
			printf("\nThe process Terminated\n");
			return 0;
		}
	return 0;
}