#include <stdio.h>

int *Enqueue(int arr[],int max);//This Function will Enter Elements in Queue.
int *Dequeue(int arr[]);//This Function will Delete Elements From Front of Queue.
void *Display(int arr[]);//This Function will Show the Elements of Queue.

//front and rear will hold the first and last element's position in the array.
int front=-1,rear=-1;//initially they are -1 because array elements start from 0

int main()
{
	int max,choice;//max will be the array size.
	printf("\nEnter the number of Elements You want to Enter inside Array\n");
	scanf("%d",&max);
	int arr[max];

	while(1)
	{
		printf("\n1> Enqueue\n");
		printf("\n2> Dequeue\n");
		printf("\n3> Display\n");
		printf("\n4> Exit\n");
		printf("\n\nEnter Your choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			Enqueue(&arr[0],max);
			break;

			case 2:
			Dequeue(&arr[0]);
			break;

			case 3:
			Display(&arr[0]);
			break;

			case 4:
			return 0;

			default:
			printf("\nEnter Correct Choice\n");
		}
	}

	return 0;
}

int *Enqueue(int arr[],int max)
{
	int ITEM;//ITEM will be the element inserted in Queue.
	if(rear==max-1)//This condition will check whether the queue is full or not.
	{
		printf("\nQueue is Full\n");
		return arr;
	}
	else
	{
		if(rear==-1 && front==-1)//initially both are incremented to hold the first element's position number in array.
			front=0;
		rear=rear+1;//rear will hold the last element's position number in array.
		printf("\nEnter The Integer You Want To Enter Inside Queue\n");
		scanf("%d",&ITEM);
		arr[rear]=ITEM;
	}

	return arr;
}

int *Dequeue(int arr[])
{
	if(front==-1)//This will check whether the queue is empty or not.
	{
		printf("\nQueue is Empty\n");
		return arr;
	}
	else
	{
		int ITEM;//ITEM will be assigned the first element of the array.
		ITEM=arr[front];
		if(front==rear)//when Queue contains only one Element
		{
			rear=-1;
			front=-1;
		}
		else//When Queue contains more than one Element.
			front=front+1;
		printf("\nItem Inside Queue is Successfully Deleted\n");
	}

	return arr;
}

void *Display(int arr[])
{
	int i;

	if(front==-1)//when front is set -1 it implies Queue is Empty.
	{
		printf("\nQueue is Empty\n");
		return arr;
	}

	for(i=front;i<=rear;i++)//prints the elements in Queue from front to rear position.
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");

	return arr;
}