#include <stdio.h>

int Push_Array(int a[],int n,int TOP);//This Function will Enter Elements in Stack.
int Pop_Array(int a[],int TOP);//This Function will Delete Elements from Top of Stack one after another.
int Status_Array(int a[],int n,int TOP);//This Function will check the status of the Stack i.e. whether the stack is full or Empty or How much space available in the Stack.
int Display(int a[],int TOP);//This Function will Show the Elements in the stack.

int main()
{
	int i,n,x;
	int TOP=-1;//This variable will store the uppermost index of the Element of the Stack.
	printf("\nHow many elements do you want to enter inside the array?\n");
	scanf("%d",&n);//n is the size of Arrray
	int a[n];//Application of Flexible Array.

	while(1)
	{
		printf("\n");
		printf("1) Push\n");
		printf("2) Pop\n");
		printf("3) status\n");
		printf("4) Display\n");
		printf("5) Exit\n\n");
		printf("Enter your choice\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
			TOP=Push_Array(&a[0],n,TOP);
			break;

			case 2:
			TOP=Pop_Array(&a[0],TOP);
			break;

			case 3:
			TOP=Status_Array(&a[0],n,TOP);
			break;

			case 4:
			TOP=Display(&a[0],TOP);
			break;

			case 5:
			return 0;

			default:
			printf("\nWarning : Enter Correct Choice\n");
		}
	}
return 0;
}

int Push_Array(int a[],int n,int TOP)
{
    int ITEM;//This variable will store the value of number entered inside Stack.

	if(TOP>=n-1)//comparing TOP with n-1 because TOP is initialized with -1.
		printf("\nWarning : Stack is Full\n");
	else
	{
		TOP=TOP+1;
		printf("\nEnter the integer you want to enter inside stack\n");
		scanf("%d",&ITEM);
		a[TOP]=ITEM;
	}
	return TOP;
}

int Pop_Array(int a[],int TOP)
{
	int ITEM;
	if(TOP<0)
		printf("\nStack is Empty\n");
	else
	{
		ITEM=a[TOP];
		TOP=TOP-1;
		printf("\nThe Last Element is Deleted\n");
	}
	return TOP;
}

int Status_Array(int a[],int size,int TOP)
{
	float free;//This variable will hold the value of percentage of free stack.
	float x;//x will hold TOP.
	x=TOP+1;//As TOP is initialized with -1.*/
	
	if(TOP<0)
		printf("\nStack is Empty\n");
	else
	{
		if(TOP>=size-1)//comparing TOP with size-1 because TOP is initialized with -1.
			printf("\nWarning : Stack is Full\n");
		else
		{
			printf("\nThe topmost element is %d\n",a[TOP]);
			
			free=(((float)size-x)/(float)size)*100;//percentage of free stack calculation.
			printf("\nSpace Available in Stack is : %f %% \n",free);	
		}
	}
	return TOP;
}

int Display(int a[],int TOP)
{
	int i;
	if(TOP==-1)
	{
		printf("\nStack is Empty\n");
	}
	else
	{
		printf("\n========================================================================================\n");
	    printf("\nThe Elements in Stack =");
		for(i=0;i<=TOP;i++)
	    {
		   printf("[%d]\t",a[i]);
	    }
	    printf("\n========================================================================================\n");
	}
	return TOP;
}