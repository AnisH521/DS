/*
Name : Anish Naskar
M.Sc Data Science
SEM 1
QUEUE IMPLEMENTATION OF CIRCULAR LINKED LIST
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	float data;struct node *link;
};

typedef struct node* nde;

nde create_node();
void enqueue();
void dequeue();
void display();

nde front=NULL;//front will store the address of the first node of the Queue.
nde rear=NULL;//rear will store the address of the last node of the Queue.

//escape sequences and ANSI codes used
//[H : tells the terminal to move the cursor to the top left corner
//[2J : clear the screen
//[3J : clear the scrollback buffer
//[1;32m : code for green
int main()
{
	int choice;
	while(1) {
		printf("\e[1;32m");
		printf("\nQUEUE IMPLEMENTATION OF CIRCULAR LINKED LIST\n");
		printf("\n<1> : Enqueue <2> : Dequeue <3> : Display <4> : EXIT PROGRAM\n");
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
			enqueue();
			printf("\e[H\e[2J\e[3J\e[1;32m");
			break;

			case 2:
			dequeue();
			break;

			case 3:
			display();
			break;

			case 4:
			return 0;

			default:
			printf("\nwrong choice : Try again!\n");
			break;
		}
	}
}

//this function will create a node and return a pointer holding the address of that node.
nde create_node() {
	nde ptr;
	ptr=(nde)malloc(sizeof(nde));
	if(ptr!=NULL) {
		ptr->link=NULL;
		return ptr;
	}
	else
		printf("Memory allocation is not possible");
	return ptr;
}

//This Function will Enter Elements in Queue.
void enqueue() {
	nde newnode;//newnode will be the pointer to the structure of type nde. 
	newnode=create_node();//allocating memory for the node to be inserted and storing its address in newnode.
	float y;
	printf("\nEnter the value you want to enter inside queue\n");
	scanf("%f",&y);
	newnode->data=y;
	if(front==NULL && rear==NULL) {
		front=rear=newnode;
		front->link=front;
		return;
	}
	rear->link=newnode;//last node will now point to new node.
	newnode->link=front;//new node will also point to last node.
	rear=newnode;//rear will now store address of newnode.
}

//This Function will Delete Elements from Queue.
void dequeue() {
	nde newnode;//newnode will be the pointer to the first node of the Queue to be deleted.
	newnode=front;//newnode will now store the address of the first node.
	if(front==NULL) {
		printf("\nNo Item is present in queue\n");
		return;
	}
	else if(front==rear) {//both pointers contains same address.
		front=rear=NULL;
	}
	else {
		front=front->link;
		rear->link=front;
	}
	free(newnode);//freeing the node whose pointer is newnode into memory bank.
	printf("\nThe Item is Succesfully deleted from Queue\n");
}

void display() {
	nde temp=front;
	if(temp==NULL)
		printf("\nQueue is empty\n");
	else {
		printf("\n");printf("front->\t");
		do {
			printf("%f\t",temp->data);
			temp=temp->link;
		}while(temp!=front);
		printf("->rear->(front)");printf("\n");
	}
}