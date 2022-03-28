/*
Name : Anish Naskar
M.Sc Data Science
SEM 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	float data;struct Node *llink;struct Node *rlink;
}nde;

nde *create_node();//this function will create a node of double linked list.
nde *data_in_first_node(nde *head);//this function will put data inside first node.
nde *create_list(nde *head);//this function is capable of creating double linked list with any no. of node.
nde *insert_at_beginning(nde *head);//this function will enter elements at beginning of list.
nde *insert_at_end(nde *head);//this function will enter elements at end of list.
nde *insert_at_any_position(nde *head);//this function will enter elements at any position of linked list.
nde *delete_from_beginning(nde *head);//this function will delete elements from beginning of list.
nde *delete_from_end(nde *head);//this function will delete elements from end of list.
nde *delete_from_any_pos(nde *head);//this function will delete elements from any position of list.
nde *sort(nde *head);//this function will sort the list in ascending sort using bubble sort.
nde *reverse(nde *head);//this function will reverse the list.
nde *merge(nde *head,nde *head1,nde *head2);//this function will merge two list.
void display1(nde *head);//this function will display the list in front order.
void display2(nde *head);//this function will display the list in reverse order.


//escape sequences used
//[H : tells the terminal to move the cursor to the top left corner
//[2J : clear the screen
//[3J : clear the scrollback buffer
//[1;33m : code for yellow
//[1;32m : code for green
//[1;31m : code for light-red
int main()
{
    nde *head=NULL,*head1=NULL,*head2=NULL;
	int choice,choice1,flag;
	while(1) {
		printf("\e[H\e[2J\e[3J\e[1;33m");
		printf("\n------------------\n");
		printf("DOUBLE LINKED LIST ");
		printf("\n------------------\n");

		printf("\n--------------------------------------------------------------------------------------------------\n");
		printf("\n1>  Create list <2>:  Insert <3>:  Deletion <4>:  Display <5>:  Merge <6>:  Reverse <7>:  Sort\n");
		printf("\n<<8>>  EXIT");
		printf("\n--------------------------------------------------------------------------------------------------\n");
		printf("\nEnter Your Choice\n");
		scanf("%d",&choice);

		switch(choice) {
			case 1:
			printf("\e[H\e[2J\e[3J\e[1;33m");
			head=create_list(head);
			break;

			case 2:
			printf("\e[H\e[2J\e[3J\e[1;32m");
			flag=1;
			while(flag==1) {
				printf("\n<1>: Insert at beginning <2>: Insert at end <3>: Insert at any position <4>: Go back to main menu\n");
				printf("\nEnter your choice\t:\t");
				scanf("%d",&choice1);

				switch(choice1) {
					case 1:
					head=insert_at_beginning(head);
					break;

					case 2:
					head=insert_at_end(head);
					break;

					case 3:
					head=insert_at_any_position(head);
					break;

					case 4:
					flag=0;
					break;

					default:
					printf("\nEnter correct choice\n");
					break;
				}
			}
			break;

			case 3:
			printf("\e[H\e[2J\e[3J\e[1;31m");
			flag=1;
			while(flag==1) {
				printf("\n<1>: Delete from beginning <2>: Delete from end <3>: Delete from any position <4>:go back to main menu\n");
				printf("\nEnter your choice\t:\t");
				scanf("%d",&choice1);

				switch(choice1) {
					case 1:
					head=delete_from_beginning(head);
					break;

					case 2:
					head=delete_from_end(head);
					break;

					case 3:
					head=delete_from_any_pos(head);
					break;

					case 4:
					flag=0;
					break;

					default:
					printf("\nEnter correct choice\n");
					break;
				}
			}
			break;

			case 4:
			printf("\e[H\e[2J\e[3J\e[1;33m");
			flag=1;
			while(flag==1) {
				printf("\n<1> Display from beginning <2> Display from end <3> Go back to main menu\n");
				printf("\nEnter your choice\t:\t");
				scanf("%d",&choice1);

				switch(choice1) {
					case 1:
					display1(head);
					break;

					case 2:
					display2(head);
					break;

					case 3:
					flag=0;
					break;

					default:
					printf("\nEnter correct choice\n");
					break;
				}
			}
			break;

			case 5:
			printf("\e[H\e[2J\e[3J\e[1;33m");
			printf("\n....................................\n");
			printf("List 1");
			printf("\n....................................\n");
			head1=create_list(head1);
			printf("\n....................................\n");
			printf("List 2");
			printf("\n....................................\n");
			head2=create_list(head2);
			head=merge(head,head1,head2);
			printf("\nMerging Done!\n");
			break;

			case 6:
			printf("\e[H\e[2J\e[3J\e[1;33m");
			head=reverse(head);
			break;

			case 7:
			printf("\e[H\e[2J\e[3J\e[1;33m");
			head=sort(head);
			break;

			case 8:
			printf("\e[H\e[2J\e[3J\e[1;33m");
			return 0;

			default:
			printf("\e[H\e[2J\e[3J\e[1;33m");
			printf("\nEnter correct choice\n");
			break;	
		}
	}
}

//this function is used to create memory for node only in double linked list.
nde *create_node()
{
	float x;nde *ptr;

		ptr=(nde *)malloc(sizeof(nde));
		if(ptr!=NULL){
			ptr->llink=NULL;
			ptr->rlink=NULL;
		}
		else
			printf("\nMemory allocation is not possible\n");

	return ptr;
}

//this function will put data inside first node.
nde *data_in_first_node(nde *head)
{
	float x;
	if(head==NULL) {
		head=create_node();
		if(head!=NULL) {
			printf("\nEnter the real number you want to enter inside node\n");
			scanf("%f",&x);
			head->data=x;
		}
	}
	return head;
}

//this function can create a double linked list.
//here we can insert nodes at beginning as well as at the end. 
nde *create_list(nde *head)
{
	char choice;
	printf("\nEnter (Y/N) to create or not create a node\n");
	scanf("%*c%c",&choice);
	if(choice=='Y' || choice=='y') {
		head=data_in_first_node(head);

		printf("\ndo you want to continue(Y/N)?\n");
		scanf("%*c%c",&choice);

		if(choice=='Y' || choice=='y') {
			printf("\nTo insert at beginning enter 'B/b' or to insert at end enter 'E/e'\n");
			scanf("%*c%c",&choice);

			if(choice=='B' || choice=='b') {
				do {
					head=insert_at_beginning(head);
					printf("\ndo you want to continue(Y/N)?\n");
					scanf("%*c%c",&choice);
				}while(choice=='Y' || choice=='y');
			}
			else if(choice=='E' || choice=='e') {
				do {
					head=insert_at_end(head);
					printf("\ndo you want to continue(Y/N)?\n");
					scanf("%*c%c",&choice);
				}while(choice=='Y' || choice=='y');
			}
		}
	}
	else
		printf("\nNo node is created\n");
return head;
}

//newNode will be the pointer to the node to be inserted.
//x will store the data to be inserted at node of list.
nde *insert_at_beginning(nde *head)
{
	nde *newNode;
	float x;

	if(head==NULL) {
		head=data_in_first_node(head);
		return head;
	}

	newNode=create_node();
	if(newNode!=NULL){
		printf("\nEnter the real number you want to enter inside node\n");
		scanf("%f",&x);
		newNode->data=x;

		newNode->rlink=head;
		head->llink=newNode;
		head=newNode;
	}
	return head;
}

//ptr will be the pointer to the last node of the list.
//newNode will be the pointer to the node to be inserted.
//x will store the data to be inserted at node of list.
nde *insert_at_end(nde *head)
{
	nde *ptr=head,*newNode;float x;

	if(head==NULL) {
		head=data_in_first_node(head);
		return head;
	}

	while(ptr->rlink!=NULL){
		ptr=ptr->rlink;
	}
	newNode=create_node();
	if(newNode!=NULL){
		printf("\nEnter the real number you want to enter inside node\n");
		scanf("%f",&x);
		newNode->data=x;

		newNode->llink=ptr;
		ptr->rlink=newNode;
	}
	return head;
}

//ptr will be the pointer to the node just before ptr1.
//ptr1 will be pointer to the node before which the node is to be inserted.
//when count is 1 the insert_at_beginning function is called.
//whenever desired position will not be found the node will be inserted at the end. 
nde *insert_at_any_position(nde *head)
{
	nde *ptr,*ptr1=head,*newNode;int count=0,pos;float x;

	if(head==NULL) {
		head=data_in_first_node(head);
		return head;
	}

	newNode=create_node();

	if (newNode!=NULL) {
		printf("\nEnter the position where you want to enter the node\n");
		scanf("%d",&pos);

		while(ptr1!=NULL) {
			count++;
			if(count==pos)
				break;
			ptr=ptr1;
			ptr1=ptr1->rlink;
		}

		if(count==1) {
			head=insert_at_beginning(head);
			return head;
		}

		else if(ptr1==NULL) {
			head=insert_at_end(head);
			return head;
		}

		printf("\nEnter the real number you want to enter inside node\n");
		scanf("%f",&x);
		newNode->data=x;

		newNode->llink=ptr;
		newNode->rlink=ptr1;
		ptr->rlink=newNode;
		ptr1->llink=newNode;
	}
	return head;
}

nde *delete_from_beginning(nde *head)
{
	if(head==NULL) {
		printf("\nlist is empty : deletion is not possible\n");
		return head;
	}
	else {
		if(head->rlink==NULL) {
			free(head);
			head=NULL;
			return head;
		}
		head=head->rlink;
		free(head->llink);
		head->llink=NULL;
	}
	return head;
}

nde *delete_from_end(nde *head)
{
	nde *ptr=head;

	if(head==NULL) {
		printf("\nlist is empty : deletion is not possible\n");
		return head;
	}	

	if(ptr->rlink==NULL) {
		free(ptr);
		head=NULL;
		return head;
	}

	while(ptr->rlink->rlink!=NULL) {
		ptr=ptr->rlink;
	}
	free(ptr->rlink);
	ptr->rlink=NULL;
	return head;
}

//ptr will be the pointer to the node to be deleted.
//ptr1 will be the pointer to the previous node of ptr.
//ptr1 will be the pointer to the next node of ptr.
nde *delete_from_any_pos(nde *head)
{
	nde *ptr=head,*ptr1,*ptr2;float item;int flag=0;

	if(ptr==NULL) {
		printf("\nlist is empty : deletion is not possible\n");
		return head;
	}

	printf("\nenter the data you want to delete\n");
	scanf("%f",&item);

	while(ptr->data!=item && ptr->rlink!=NULL) {
		ptr=ptr->rlink;
		flag=1;
	}

	if(flag==0) {
		head=delete_from_beginning(head);
		return head;
	}

	else if(ptr->data==item) {
		ptr1=ptr->llink;
		ptr2=ptr->rlink;
		ptr1->rlink=ptr2;

		if(ptr2!=NULL) {
			ptr2->llink=ptr1;
		}
		free(ptr);
	}
	else
		printf("\nthe required data does not exist\n");
	
	return head;
}

//last will be the pointer to the node before which we will check the value inside node.
//temp and temp2 will be the pointer to the node for sorting purpose. 
nde* sort(nde *head)
{
	if(head==NULL) {
		printf("\nlist is empty : sorting is not possible\n");
		return head;
	}
	nde *last,*temp,*temp2;	
	for(last=NULL;last!=head->rlink;last=temp)
	{
		for(temp=head;temp->rlink!=last;temp=temp->rlink)
		{
			temp2=temp->rlink;
			if(temp->data>temp2->data)
			{
				temp->data=temp->data+temp2->data;
				temp2->data=temp->data-temp2->data;
				temp->data=temp->data-temp2->data;
			}
		}
	}
	printf("Sorting Done!");
	return head;
}

nde* reverse(nde *head)
{
	if(head==NULL) {
		printf("\nlist is empty : reversal is not possible\n");
		return head;
	}
	nde *temp=NULL;

	while(head!=NULL)
	{
		temp=head->llink;
		head->llink=head->rlink;
		head->rlink=temp;
		head=head->llink;
	}
	temp=temp->llink;
	head=temp;
	printf("\nReversal Done!\n");
	return head;
}

nde *merge(nde *head,nde *head1,nde *head2)
{
	nde *ptr;
	ptr=head1;
	while(ptr->rlink!=NULL)
	{
		ptr=ptr->rlink;
	}
	ptr->rlink=head2;
	head2->llink=ptr;
	head=head1;
	return head;
}	

//for display purpose from beggning of the list.
void display1(nde *head)
{
	nde *temp=head;

	if(temp==NULL){
		printf("\nLinked List is Empty\n");
	}
	else {
		printf("\n");
		while(temp!=NULL) {
			printf("%f\t",temp->data);
			if(temp->rlink!=NULL)
				printf("<=>\t");
			temp=temp->rlink;
		}printf("\n");
	}	
}

//firstly temp will be send to hold the address of the last node
//then the data is printed in reverse order.
void display2(nde *head)
{
	nde *temp=head;

	if(temp==NULL){
		printf("\nLinked List is Empty\n");
	}
	else {
		while(temp->rlink!=NULL)
			temp=temp->rlink;
		printf("\n");
		while(temp!=NULL) {
			printf("%f\t",temp->data);
			if(temp->llink!=NULL)
				printf("<=>\t");
			temp=temp->llink;
		}printf("\n");
	}	
}