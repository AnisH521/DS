/*
Name : Anish Naskar
M.Sc Data Science
SEM 1
CHECKING HEIGHT OF A TREE
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node
{
	int data;struct node *lchild;struct node *rchild;
};

typedef struct node* nde;

nde GetNode();
nde data_in_node(int);
bool ComputeHeight(nde,int *);
void inorder(nde);

int main()
{
	nde root = NULL;int height = 0;
	root = data_in_node(1);
	root->lchild = data_in_node(2);
    root->rchild = data_in_node(3);
    root->lchild->lchild = data_in_node(4);
    root->lchild->rchild = data_in_node(5);
    root->rchild->lchild = data_in_node(6);
    root->lchild->lchild->lchild = data_in_node(7);

    printf("\nThe data in Tree are\n");
    inorder(root);
    
    if (ComputeHeight(root, &height))
        printf("\nTree is balanced\n");
    else
        printf("\nTree is not balanced\n");
    return 0;
}

//this function is used to create a node
nde GetNode()
{
	nde ptr;
		ptr=(nde)malloc(sizeof(nde));
		if(ptr!=NULL) {
			ptr->lchild=NULL;
			ptr->rchild=NULL;
		}
		else
			printf("\nMemory allocation is not possible");
	return ptr;
}

//this function is used to put data in node
nde data_in_node(int num)
{
	nde root=GetNode();
	if(root!=NULL) {
		root->data=num;
	}	
	return root;
}

bool ComputeHeight(nde root,int *height)
{
	int hl = 0,hr = 0,l = 0,r = 0;
	nde lptr,rptr;
	if (root == NULL) {
		*height = 0;
		return 1;
	}
	else {
		lptr=root->lchild;
		rptr = root->rchild;
		l=ComputeHeight(lptr,&hl);
		r=ComputeHeight(rptr,&hr);
		if (hl <= hr)
			*height = 1 + hr;
		else
			*height = 1 + hl;
		
		if (abs(hl - hr) >= 2)
        	return 0;
        else
        	return 1 && r;
	}
}

void inorder(nde root)
{
	nde ptr=root;
	if(ptr!=NULL) {
		inorder(ptr->lchild);
		printf("%d\t",ptr->data);
		inorder(ptr->rchild);
	}
	return;
}

