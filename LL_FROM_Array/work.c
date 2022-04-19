/*******************
 Name : Anish Naskar
 M.Sc. Data Science 
 SEM 1
 Creation of Singly Linked list from array
 ******************/


#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;struct node *link;
};

typedef struct node* nde;

nde array_creation();//this function is creating a flexible array
nde array_to_ll(nde head,int arr[],int n);//this function is creating a single linked list taking data from array
nde create_node();//this function is creating a node
void Display(nde head);//this function is displaying elements in linked list
nde selection_Sort(nde head);//this function is sorting elements of linked list using selection sort

//escape sequences used
//[H : tells the terminal to move the cursor to the top left corner
//[2J : clear the screen
//[3J : clear the scrollback buffer
int main()
{
	nde head;
	int choice;
	while(1) {
		printf("\n1>  Create linked_list from array <2>:  selection sort <3>:  Display\n");
		printf("\n<<4>>  EXIT");
		printf("\n--------------------------------------------------------------------------------------------------\n");
		printf("\nEnter Your Choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
			head=array_creation(head);
			printf("\e[H\e[2J\e[3J");
			break;

			case 2:
			head=selection_Sort(head);
			printf("\e[H\e[2J\e[3J");
			break;

			case 3:
			Display(head);
			break;

			case 4:
			return 0;

			default :
			printf("\nYou Entered Wrong choice\n");
		}
	}	
}

nde create_node()
{
	nde ptr;
	ptr=(nde)malloc(sizeof(nde));
		if(ptr!=NULL) {
			ptr->link=NULL;
		}
		else
			printf("\nMemory allocation is not possible\n");
	return ptr;
}

//taking n from user and putting it inside array
//also calling conversion function from array to linked list
nde array_creation(nde head)
{
	int n,k;
	printf("\nHow many elements you want to enter inside the array?\n");
	scanf("%d",&n);
	int arr[n];
	for(k=0;k<n;k++) {
		printf("\nEnter the value you want to enter inside Array\n");
		scanf("%d",&arr[k]);
	}
	head=array_to_ll(head,&arr[0],n);
	return head;
}

//next is used to allocate memory for the node in linked list
//temp is used to put data inside linked list
nde array_to_ll(nde head,int arr[],int n)
{
	nde temp,next;
	temp=create_node();
	temp=head;
	temp->data=arr[0];
	for(int i=1;i<n;i++) {

		next=create_node();
		temp->link=next;
		temp=next;

		temp->data=arr[i];
	}
	return head;
}

//ptr will hold the address of first node 
//next will be traversed to second node
//min will hold the address of node containing minimum integer
nde selection_Sort(nde head)
{
	int val;
    nde ptr = head,min,next; 
    while (ptr!=NULL) {
        min = ptr;
        next = ptr->link;
        while (next!=NULL) {
            if (min->data > next->data)
                min = next;
            next = next->link;
        } 
        val = ptr->data;
        ptr->data = min->data;
        min->data = val;
        ptr = ptr->link;
    }
    printf("\nselection sorting is done\n");
    return head;
}

void Display(nde head)
{
	nde temp;
	if(head==NULL) {
		printf("\nNo data present in list\n");
	}
	temp=head;
	printf("\n");
	while(temp!=NULL) {
		printf("%d\t",temp->data);
		printf("->\t");
		temp=temp->link;
	}
	printf("NULL\n");
}