/******************************

 NAME : Anish Naskar
 M.Sc Data Science
 SEM 1

 Binary_Search(Non-recursive)

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


int Binary(int a[],int n,int L)
{
	int T,flag,M,s;
	printf("\nEnter the value you want to search\n");
	scanf("%d",&s);
	T=n-1;
	flag=0;
	while(flag!=1 && L<=T)
	{
		M=ceil((L+T)/2);
		if(s==a[M])
		{
			printf("\nThe location of the element is %d\n",M);
			printf("-----------------------------------------------------------\n");
			flag=1;
		}
		else if(s<a[M])
		{
			T=M-1;
		}
		else if(s>a[M])
		{
			L=M+1;
		}
	}
	if(flag==0)
	{
		printf("\nThe required element does not exist\n");
		printf("-----------------------------------------------------------\n");
	}
	return 0;
}


int main()
{
	int i,n,L=0;
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
	printf("-----------------------------------------------------------");
	Sort(&a[0],n);
	Binary(&a[0],n,L);
	printf("Do you want to Create Another Array and continue searching (y/n)?\n");
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