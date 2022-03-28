#include<stdio.h>
#include<stdlib.h>

struct Node
{
int COEF;
int EXP;
struct Node *link;
};


struct Node* Multiplication(struct Node *Head,struct Node *Head1)
{
	struct Node *Hptr,*H1ptr,*Head2=NULL,*next,*H2ptr;

	Hptr=Head,H1ptr=Head1;

	Head2=(struct Node *)malloc(sizeof(struct Node));

	H2ptr=Head2;

	/*if(H1ptr==NULL || Hptr==NULL)
		{
			Head2=Head2->link;
			return Head2;
		}

	if(H1ptr==NULL && Hptr==NULL)
		{
			return Head2;
		}*/

	while(Hptr!=NULL)
	{
		H1ptr=Head1;
		while(H1ptr!=NULL)
		{
			next=(struct Node *)malloc(sizeof(struct Node));
			H2ptr->link=next;
			H2ptr=next;

			H2ptr->COEF=Hptr->COEF*H1ptr->COEF;
			H2ptr->EXP=Hptr->EXP+H1ptr->EXP;
			H2ptr->link=NULL;

			H1ptr=H1ptr->link;
		}
		Hptr=Hptr->link;
	}
	Head2=Head2->link;
	return Head2;
}


struct Node* FinalADD(struct Node *Head2)
{
	struct Node *H2ptr,*H2ptr0;
	H2ptr=Head2;
	H2ptr0=H2ptr;

	if(H2ptr->link==NULL)
		return Head2;

	while(H2ptr0->link->link!=NULL)
	{
		H2ptr0=H2ptr;
	    H2ptr=H2ptr->link;
		if(H2ptr0->EXP==H2ptr->EXP)
		{
			H2ptr0->COEF=H2ptr0->COEF+H2ptr->COEF;
			
	        H2ptr0->link=H2ptr->link;

	        free(H2ptr);

	        H2ptr=H2ptr0;
		}
		else if(H2ptr0->EXP<H2ptr->EXP || H2ptr0->EXP>H2ptr->EXP)
		{
			continue;
		}
	}
	return Head2;
}


struct Node* Display(struct Node *Head)
{
	if(Head==NULL)
		printf("\nLinked list is Empty\n");
	struct Node *temp;
	temp=Head;
	printf("\n=============================================================================\n");
	while(temp!=NULL)
	{
		printf("%dx^%d\t",temp->COEF,temp->EXP);
		temp=temp->link;
		if(temp!=NULL)
			printf("+\t");
	}
	printf("\n=============================================================================\n");
	return Head;
}


struct Node* Insert_End(struct Node *Head)
{
	int x,y;
	struct Node *ptr, *temp;
	ptr=Head;
	temp=(struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter the coefficient of the variable\n");
	scanf("%d",&x);
	printf("\nEnter the exponent of the variable\n");
	scanf("%d",&y);

	temp->COEF=x;
	temp->EXP=y;
	temp->link=NULL;

	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=temp;
	return Head;
}


struct Node* create_list(struct Node *Head)
{
	int x1,x2,x3;
	char choice;
	Head=NULL;

	printf("\nEnter 1 to create First Term of the Polynomial Else Enter 0\n");
    scanf("%d",&x2);

    if(x2==1)
    {
       Head=(struct Node *)malloc(sizeof(struct Node));
       printf("\nEnter the coefficient of the variable\n");
       scanf("%d",&x1);
       printf("\nEnter the exponent of the variable\n");
       scanf("%d",&x3);
       Head->COEF=x1;
       Head->EXP=x3;
       Head->link=NULL;
       pnt :
         printf("\nDo You Want To Continue(y/n)?\n");
         scanf("%s",&choice);
            if(choice=='y')
            {
                Head=Insert_End(Head);
                goto pnt;
            }
            else if(choice=='n')
            {
	            return Head;
            }
    }
    else if(x2==0)
    	{
	        return Head;
        }
           
 printf("\nWrong Input!\n");
 return Head;
}


struct Node* SortEXP(struct Node *Head)
{
	struct Node *last,*prev,*next;

	if(Head->link==NULL)
	   return Head;

	for(last=NULL;last!=Head->link;last=prev)
	{
		for(prev=Head;prev->link!=last;prev=prev->link)
		{
			next=prev->link;
			if(prev->EXP<next->EXP)
			{
				prev->EXP=prev->EXP+next->EXP;
				next->EXP=prev->EXP-next->EXP;
				prev->EXP=prev->EXP-next->EXP;

				prev->COEF=prev->COEF+next->COEF;
				next->COEF=prev->COEF-next->COEF;
				prev->COEF=prev->COEF-next->COEF;
			}
		}
	}
	return Head;
}


int main()
{
	printf("\nThis Program Will Add Two Polynomial with Integer coefficients using single Linked list\n");

	struct Node *Head,*Head1,*Head2;
	int i;

	Head=NULL;
	Head1=NULL;
	Head2=NULL;

	while(1)
    {
    	printf("\n============================================================================\n");

		printf("\n1>  Create Polynomials\n");
		printf("\n2>  Multiply Polynomials\n\n[NOTE : This option will work only if each Polynomial contain atleast one term]\n");
		printf("\n3>  Display\n\n[NOTE : This option will work only afer multiplication]\n");
		printf("\n4>  Exit\n");

		printf("\n============================================================================\n");
		printf("\nEnter Your Choice\n");
		scanf("%d",&i);
    	switch(i)
    	{
    		case 1:

    		Head=create_list(Head);
    		printf("\nFirst Polynomial is Created!\n");
    		printf("\n============================================================================\n");
	        Head1=create_list(Head1);
	        printf("\nSecond Polynomial is Created!\n");
	        printf("\n============================================================================\n");

	        break;

	        case 2:

	        Head=SortEXP(Head);
	        Head1=SortEXP(Head1);

	        Head2=Multiplication(Head,Head1);

	        Head2=SortEXP(Head2);

	        Head2=FinalADD(Head2);

	        printf("\nMultiplication of two Polynomials is done\n");

	        break;

	        case 3:

	        Head2=Display(Head2);

	        break;

	        case 4:

	        printf("\n============================================================================\n");
			printf("\nProcess Ends\n");
			printf("\n============================================================================\n");
			return 0;

			default :

			printf("\nYou Entered  Incorrect Choice\n");
    	}
    }

	return 0;
}