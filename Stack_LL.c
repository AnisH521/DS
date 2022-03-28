#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
int data;struct Node *link;
}n;

n* Push(n *TOP);//This Function will Enter Elements in Stack.
n* Pop(n *TOP);//This Function will Delete Elements from Top of Stack one after another.
n* Status(n *TOP);//This Function will check the status of the Stack.

int main()
{
	void *TOP=NULL;//TOP will be the pointer to the topmost node of the Stack.
	int x;

	while(1)
	{
		printf("\n");
		printf("1) Push\n");
		printf("2) Pop\n");
		printf("3) status\n");
		printf("4) Exit\n\n");
		printf("Enter your choice\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
			TOP=Push(TOP);
			break;

			case 2:
			TOP=Pop(TOP);
			break;

			case 3:
			TOP=Status(TOP);
			break;

			case 4:
			return 0;

			default:
			printf("\nWarning : Enter Correct Choice\n");
	    }
    }
    return 0;
}

n* Push(n *TOP)
{
	n *new;//new will be the pointer to the node to be inserted at the Top of Stack.
	new=(n *)malloc(sizeof(n));//Allocating memory.
	int ITEM;

	printf("\nEnter The value you want to put inside Node\n");
	scanf("%d",&ITEM);
	new->data=ITEM;
	new->link=TOP;
	TOP=new;

	return TOP;
}

n* Pop(n *TOP)
{
	n *temp;//temp will be a temporary pointer to the node, which will be deleted.
	temp=(n *)malloc(sizeof(n));//Allocating Memory.
	int ITEM;//data portion of the node to be deleted will be assigned to ITEM for simplicity.

	if(TOP==NULL)
		printf("\nStack is Empty\n");
	else
		{
			temp=TOP;
			ITEM=temp->data;
			TOP=TOP->link;
			free(temp);
			printf("\nItem at Top of Stack is successfully Deleted\n");
		}
	return TOP;
}

n* Status(n *TOP)
{
	n *temp;//temp will be temporarily assigned to the TOP pointer for status checking purpose and traversing the list.
	int count;//count will count the number of nodes present in Stack.

	temp=TOP;
	if(temp==NULL)
		printf("\nStack is Empty\n");
	else
	{
		count=0;
		while(temp!=NULL)
		{
			count++;
			temp=temp->link;
		}
		printf("\nThe item At Top is %d and Stack Contains %d items\n",TOP->data,count);
	}
	return TOP;
}