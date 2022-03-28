#include<stdio.h>
#include<stdlib.h>

//Structure Declaration
typedef struct Node
{
int data;struct Node *link;
}nde;

int Enqueue();//This Function will Enter Elements in Queue.
int Dequeue();//This Function will Delete Elements from Queue.	
int Display();//This function will show the Elements in Queue.

nde *front=NULL;//front will store the address of the first node of the Queue.
nde *rear=NULL;//rear will store the address of the last node of the Queue.

int main()
{
	int choice;

	while(1)
	{
		printf("\n1-> Enqueue\n");
		printf("\n2-> Dequeue\n");
		printf("\n3-> Display\n");
		printf("\n4-> Exit\n");
		printf("\n\nEnter Your Choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			Enqueue();
			break;

			case 2:
			Dequeue();
			break;

			case 3:
			Display();
			break;

			case 4:
			return 0;

			default:
			printf("\nEnter Correct Choice\n");
		}
	}
	return 0;
}

int Enqueue()
{
	nde *new;//new will the pointer to the structure of type nde. 
	new=(node *)malloc(sizeof(node));//allocating memory for the node to be inserted and storing its address in new.
	int y;

	printf("\nEnter the value you want to enter inside queue\n");
	scanf("%d",&y);

	new->data=y;
	new->link=NULL;

	if(front==NULL && rear==NULL)
	{
		front=rear=new;
		return 0;
	}

	rear->link=new;//giving the address of new to rear.
	rear=new;//rear will now become new.

	return 0;
}

int Dequeue()
{
	nde *new;//new will be the pointer to the first node of the Queue to be deleted.
	new=front;//new will now store the address of the first node.

	if(front==NULL)
	{
		printf("\nNo Item is present in queue\n");
		return 0;
	}

	if(front==rear)//both pointers contains same address.
	{
		front=rear=NULL;
	}

	else
		front=front->link;

	free(new);//freeing the node whose pointer is new into memory bank.

	printf("\nThe Item is Succesfully deleted from Queue\n");

	return 0;
}

int Display()
{
	nde *ptr;//ptr is the pointer to structure of type nde.
	ptr=front;//ptr will hold the address of first node.

	if(ptr==NULL)
		printf("\nQueue is Empty\n");

	while(ptr!=NULL)//traversing and printing data inside node.
	{
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");

	return 0;
}