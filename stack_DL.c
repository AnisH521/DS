/*
Name : Anish Naskar
M.Sc Data Science
SEM 1
STACK IMPLEMENTATION OF DOUBLE LINKED LIST
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float data;struct node *llink;struct node *rlink;
}nde;

nde* create_node();//This function will allocate memory for the node of structure nde and return a pointer to that node.
nde* push(nde *TOP);//This Function will Enter Elements in Stack.
nde* pop(nde *TOP);//This Function will Delete Elements from Top of Stack one after another.
void status(nde *TOP);//This Function will check the status of the Stack.
void display2(nde *TOP);//This Function will show the elements of the Stack.

//escape sequences used
//[H : tells the terminal to move the cursor to the top left corner
//[2J : clear the screen
//[3J : clear the scrollback buffer
//[1;32m : code for green
int main()
{
	nde *TOP=NULL;int choice;//TOP will be the pointer to the topmost node of the Stack.
	while(1) {
		printf("\e[1;32m");
		printf("\nSTACK IMPLEMENTATION OF DOUBLE LINKED LIST\n");
		printf("\n<1> : push <2> : pop <3> : status <4> : EXIT PROGRAM\n");
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
			printf("\e[H\e[2J\e[3J\e[1;32m");
			TOP=push(TOP);
			break;

			case 2:
			printf("\e[H\e[2J\e[3J\e[1;32m");
			TOP=pop(TOP);
			break;

			case 3:
			printf("\e[H\e[2J\e[3J\e[1;32m");
			status(TOP);
			break;

			case 4:
			return 0;

			default:
			printf("\e[H\e[2J\e[3J\e[1;32m");
			printf("\nwrong choice : Try again!\n");
			break;
		}
	}
}

nde* create_node()
{
	nde *ptr;
	ptr=(nde *)malloc(sizeof(nde));
	if(ptr!=NULL) {
		ptr->llink=NULL;
		ptr->rlink=NULL;
	}
	else
		printf("Memory allocation is not possible");
	return ptr;
}

nde* push(nde *TOP)
{
	nde *newnode;//new will be the pointer to the node to be inserted at the Top of Stack.
	newnode=create_node();//Allocating memory.
	float ITEM;

	printf("\nEnter The value you want to put inside Node\n");
	scanf("%f",&ITEM);

	if(TOP==NULL) {
		newnode->data=ITEM;
		newnode->rlink=TOP;
		TOP=newnode;
	}
	else {
		newnode->data=ITEM;
		newnode->llink=TOP;
		TOP->rlink=newnode;
		TOP=newnode;
	}
	return TOP;
}

nde* pop(nde *TOP)
{
	nde *temp;//temp will be a temporary pointer to the node, which will be deleted.
	temp=create_node();//Allocating Memory.

	if(TOP==NULL)
		printf("\nStack is Empty\n");
	else
		{
			temp=TOP;
			TOP=TOP->llink;
			free(temp);
			printf("\nItem at Top of Stack is successfully Deleted\n");
		}
	return TOP;
}

void status(nde *TOP)
{
	nde *temp;//temp will be temporarily assigned to the TOP pointer for status checking purpose and traversing the list.
	int count;//count will count the number of nodes present in Stack.

	temp=TOP;
	if(temp==NULL)
		printf("\nStack is Empty\n");
	else {
		count=0;
		while(temp!=NULL) {
			count++;
			temp=temp->llink;
		}
		printf("\nThe elements inside stack are\n");
		display2(TOP);
		printf("\nThe item At Top is %f and Stack Contains %d items\n",TOP->data,count);
	}
}

void display2(nde *TOP)
{
	nde *temp=TOP;
	printf("TOP\n|\nv");
	printf("\n");
		while(temp!=NULL) {
			printf("%f\t",temp->data);
			if(temp->llink!=NULL)
				printf("<=>\t");
			temp=temp->llink;
		}
	printf("\n");			
}