#include <stdio.h>
#include <stdlib.h>

//structure declaration
typedef struct Node
{
	float data;struct Node *link;
}nde;

nde *InsertBegin_CL(nde *last);//This function will create a circular linked list and enter nodes in it.
nde *DeleteBegin_CL(nde *last);//This function will delete nodes from linked list.
nde *search(nde *last);//This function will show the position number and address of the node in List.
nde *reverse(nde *last);//This function will reverse the list.
void Display(nde *last);//This function will show the list.

int main()
{
	nde *last=NULL;int choice;//last will be the pointer to the node after which a node is to be inserted.

	while(1)
	{
		printf("\n1 Insert a Node in Circular Linked List after creation\n");
		printf("\n2 Delete a Node in Circular Linked List\n");
		printf("\n3 Reverse a Circular Linked List\n");
		printf("\n4 Search a Node in Circular Linked List\n");
		printf("\n5 Display\n");
		printf("\n6 End Process\n");
		printf("\n\nEnter Your Choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			last=InsertBegin_CL(last);
			break;

			case 2:
			last=DeleteBegin_CL(last);
			break;

			case 3:
			last=reverse(last);
			break;

			case 4:
			last=search(last);
			break;

			case 5:
			Display(last);
			break;

			case 6:
			return 0;

			default:
			printf("\nEnter Correct Choice\n");
			break;
		}
	}
	return 0;
}

nde *InsertBegin_CL(nde *last)
{
	float item;nde *temp;//temp will be the pointer to the node to be inserted.

	if(last==NULL)//creation of circular linked list
	{
		last=malloc(sizeof(nde));

	    printf("\nEnter The Real Number You Want To Enter Inside Node\n");
	    scanf("%f",&item);

	    last->data=item;
		last->link=last;
	}

	else//insertion of node at the beginning of list.
	{
		temp=malloc(sizeof(nde));

		printf("\nEnter the Real Number you want to Enter Inside Node\n");
		scanf("%f",&item);

		temp->data=item;

		temp->link=last->link;
		last->link=temp;
	}
	return last;
}

nde *DeleteBegin_CL(nde *last)
{
	nde *temp, *temp1;//temp containing node address will be freed to memory bank.
                      //temp1 is maintained to keep the circular linked list.
	if(last==NULL)
		printf("\nThe List is Empty\n");

	else if(last->link==last)//in case of one node.
	{
		free(last);
		last=NULL;
	}

	else              //in case of more tan one node
	{
		temp=last->link;
		temp1=temp->link;
		last->link=temp1;
		free(temp);
	}
	return last;
}

nde *reverse(nde *last)
{					     //temp will be pointer to node just before last.
	nde *temp,*ptr,*head;//head will be pointer to first node.
                         //ptr will be pointer to the node whose linked portion will get updated.
	if(last==NULL)
	{
		printf("\nLinked List doesn't exist for Reversal\n");
		return last;
	}

	last=last->link;

	head=last;
	temp=last;
	ptr=last->link;
	last=last->link;

	while(last!=head)//for traversal.
	{
		last=last->link;
		ptr->link=temp;
		temp=ptr;
		ptr=last;
	}
	ptr->link=temp;

	return last;
}

nde *search(nde *last)
{
	nde *temp;float item;int count=0;//temp will be pointer to the node to be searched.
									 //count will store the position of the node.
	printf("\nEnter The Real Number You want to search\n");
	scanf("%f",&item);

	temp=last;
	do
	{
		temp=temp->link;
		count++;
	}while(temp->data!=item && temp!=last);//traversal purpose

	if(temp->data==item)//when the required data is found
		printf("\nThe item is present in %dth position and at address %p\n",count,temp);
	else                //when the required data is not present in the list.
		printf("\nThe Required item is not Present in the list\n");

	return last;
}

void Display(nde *last)
{
	nde *temp;//temp will be the pointer to the first node of the circular linked list.

	if(last==NULL)//for list containing no node.
		printf("\nLinked List Is Empty!\n");

	else
	{
		printf("\n");
		temp=last->link;
		do
		{
			printf("%f\t",temp->data);
			temp=temp->link;
		}
		while(temp!=last->link);//traversal purpose.
		printf("\n");
	}
}
