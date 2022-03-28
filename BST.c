#include<stdio.h>
#include<malloc.h>

struct node {
	int data;struct node *lchild;struct node *rchild;
};

typedef struct node* tree;

tree GetNode();
tree data_in_root_node(tree);
void insert_in_BST(tree);
void delete_in_BST(tree,int);
tree successor(tree);
void inorder(tree);
void preorder(tree);
void postorder(tree);
void search(tree);

//escape sequences and ANSI codes used
//[H : tells the terminal to move the cursor to the top left corner
//[2J : clear the screen
//[3J : clear the scrollback buffer
//[1;32m : code for green
//[1;31m : code for light-red
int main()
{
    tree root=NULL;int num,choice,choice1,flag;
    printf("\e[H\e[2J\e[3J\e[1;32m");
    root=data_in_root_node(root);
    while(1) {
    	printf("<1>: insert\t<2>: delete\t<3>: traversal\t<4>: search\t<5>: exit");
    	printf("\nEnter your choice\t:\t");
    	scanf("%d",&choice);
    	switch(choice) {
    		case 1:
    		printf("\e[H\e[2J\e[3J\e[1;32m");
    		insert_in_BST(root);
    		break;

    		case 2:
    		printf("\e[H\e[2J\e[3J\e[1;31m");
    		printf("\nEnter the data you want to delete inside node : ");
			scanf("%d",&num);
			delete_in_BST(root,num);
    		break;

    		case 3:
    		printf("\e[H\e[2J\e[3J\e[1;32m");
    		flag=1;
			while(flag==1) {
				printf("\n<1>: inorder traversal <2>: preorder traversal <3>: postorder traversal <4>: Go back to main menu\n");
				printf("\nEnter your choice\t:\t");
				scanf("%d",&choice1);

				switch(choice1) {
					case 1:
					printf("\e[H\e[2J\e[3J\e[1;32m");
					inorder(root);
					printf("\n");
					break;

					case 2:
					printf("\e[H\e[2J\e[3J\e[1;32m");
					preorder(root);
					printf("\n");
					break;

					case 3:
					printf("\e[H\e[2J\e[3J\e[1;32m");
					postorder(root);
					printf("\n");
					break;

					case 4:
					printf("\e[H\e[2J\e[3J\e[1;32m");
					flag=0;
					break;

					default:
					printf("\nEnter correct choice\n");
					break;
				}
			}
			break;

			case 4:
			printf("\e[H\e[2J\e[3J\e[1;32m");
			search(root);
			break;

			case 5:
			return 0;

			default :
			printf("\e[H\e[2J\e[3J\e[1;32m");
			printf("\nEnter correct choice");
			break;
    	}
    }
}

//this function is used to create a node
tree GetNode()
{
	tree ptr;
		ptr=(tree)malloc(sizeof(tree));
		if(ptr!=NULL) {
			ptr->lchild=NULL;
			ptr->rchild=NULL;
		}
		else
			printf("\nMemory allocation is not possible");
	return ptr;
}

//this function is used to put data in root node
tree data_in_root_node(tree root)
{
	int x;
	if(root==NULL) {
		root=GetNode();
		if(root!=NULL) {
			printf("\nEnter the integer you want to enter inside root node : ");
			scanf("%d",&x);
			root->data=x;
		}
	}
	return root;
}

//this function is used to put node in BST
void insert_in_BST(tree root)
{
	tree ptr=root,temp,newnode;int flag=0,num;

	printf("\nEnter the data you want to enter inside node : ");
	scanf("%d",&num);

	while(ptr!=NULL && flag==0) {
		if(num<ptr->data) {
			temp=ptr;
			ptr=ptr->lchild;
		}
		else if(num>ptr->data) {
			temp=ptr;
			ptr=ptr->rchild;
		}
		else if(ptr->data==num) {
			flag=1;
			printf("\nThe given number already exist");
		}
	}
	if(ptr==NULL) {
		newnode=GetNode();
		newnode->data=num;
		if(temp->data<num)
			temp->rchild=newnode;
		else
			temp->lchild=newnode;
	}
}

//this funcction will delete a node in BST
//this function cannot delete the root node
void delete_in_BST(tree root,int num)
{
	tree ptr=root,parent,ptr1,ptr2;int flag=0,flag1,num1;

	//step to find location of the node
	while(ptr!=NULL && flag==0) {
		if(num<ptr->data) {
			parent=ptr;
			ptr=ptr->lchild;
		}
		else if(num>ptr->data) {
			parent=ptr;
			ptr=ptr->rchild;
		}
		else if(ptr->data==num)
			flag=1;
	}

	//in case the node does not exist
	if(flag==0) {
		printf("\nThe required number does not exist : No Deletion");
		return;
	}

	//cases of deletion
	if(ptr->lchild==NULL && ptr->rchild==NULL)//node having no child
		flag1=1;
	else {
		if(ptr->lchild!=NULL && ptr->rchild!=NULL)//node having both left and right child
			flag1=3;
		else
			flag1=2;
	}

	//case 1
	if(flag1==1) {
		if(parent->lchild==ptr)
			parent->lchild=NULL;
		else
			parent->rchild=NULL;
		free(ptr);
	}

	//case 2
	if(flag1==2) {
		if(parent->lchild==ptr) {
			if(ptr->lchild==NULL)
				parent->lchild=ptr->rchild;
			else
				parent->lchild=ptr->lchild;
		}
		else {
			if(parent->rchild==ptr) {
				if(ptr->lchild==NULL)
					parent->rchild=ptr->rchild;
				else
					parent->rchild=ptr->lchild;
			}
		}
		free(ptr);
	}

	//case 3
	//when the node contains both left and right child
	if(flag1==3) {
		ptr1=successor(ptr);//finding the inorder successor of the node
		num1=ptr1->data;
		delete_in_BST(root,ptr1->data);//delete the inorder successor
		ptr->data=num1;//replace the data with inorder successor
	}
}

//to find inorder successor of a node
tree successor(tree ptr)
{
	tree ptr1;
	ptr1=ptr->rchild;
	if(ptr1!=NULL) {
		while(ptr1->lchild!=NULL) {
			ptr1=ptr1->lchild;
		}
	}
	return ptr1;
}

//inorder traversal purpose i.e left subtree ->root->right subtree
void inorder(tree root)
{
	tree ptr=root;
	if(ptr!=NULL) {
		inorder(ptr->lchild);
		printf("%d\t",ptr->data);
		inorder(ptr->rchild);
	}
	return;
}

//inorder traversal purpose i.e root->left subtree->right subtree
void preorder(tree root)
{
	tree ptr=root;
	if(ptr!=NULL) {
		printf("%d\t",ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
	return;
}

//inorder traversal purpose i.e left subtree ->right subtree->root
void postorder(tree root)
{
	tree ptr=root;
	if(ptr!=NULL) {
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d\t",ptr->data);
	}
	return;
}

//this function will search a node address in BST
void search(tree root)
{
	tree ptr=root;int flag=0,num;//start from root node

	printf("\nEnter the data you want to search : ");
	scanf("%d",&num);

	while(ptr!=NULL && flag==0) {
		if(num<ptr->data)//going to left sub tree
			ptr=ptr->lchild;
		else if(ptr->data==num)//for successful search
			flag=1;
		else if(num>ptr->data)//going to right sub tree
			ptr=ptr->rchild;
	}

	if(flag==1)
		printf("\nThe number is found at node address : %p\n",ptr);
	else
		printf("\nThe required number does not exist on tree\n");
}