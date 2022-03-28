#include<stdio.h>
#include<stdlib.h>

struct Node
{
int COEF;
int EXP;
struct Node *link;
};


struct Node* Addition(struct Node *Head,struct Node *Head1)
{
	struct Node *Head2,*H2ptr,*H1ptr,*Hptr,*next;

	Hptr=Head;
	H1ptr=Head1;
	
	Head2=(struct Node *)malloc(sizeof(struct Node));
	
	H2ptr=Head2;

	while(Hptr!=NULL && H1ptr!=NULL)
	{
		if(Hptr->EXP==H1ptr->EXP)
		{
			next=(struct Node *)malloc(sizeof(struct Node));
			H2ptr->link=next;
			H2ptr=next;

			H2ptr->COEF=Hptr->COEF+H1ptr->COEF;
			H2ptr->EXP=Hptr->EXP;
			H2ptr->link=NULL;
					
			Hptr=Hptr->link;
			H1ptr=H1ptr->link;
		}

		else if(Hptr->EXP>H1ptr->EXP)
		{
			next=(struct Node *)malloc(sizeof(struct Node));
			H2ptr->link=next;
			H2ptr=next;

			H2ptr->COEF=Hptr->COEF;
			H2ptr->EXP=Hptr->EXP;
			H2ptr->link=NULL;

			Hptr=Hptr->link;
		}

		else if(Hptr->EXP<H1ptr->EXP)
		{
			next=(struct Node *)malloc(sizeof(struct Node));
			H2ptr->link=next;
			H2ptr=next;

			H2ptr->COEF=H1ptr->COEF;
			H2ptr->EXP=H1ptr->EXP;
			H2ptr->link=NULL;

			H1ptr=H1ptr->link;
		}
	}

	if(Hptr!=NULL && H1ptr==NULL)
	{
		while(Hptr!=NULL)
		{
			next=(struct Node *)malloc(sizeof(struct Node));
			H2ptr->link=next;
			H2ptr=next;

			H2ptr->COEF=Hptr->COEF;
			H2ptr->EXP=Hptr->EXP;
			H2ptr->link=NULL;

			Hptr=Hptr->link;
		}
	}

	else if(Hptr==NULL && H1ptr!=NULL)
	{
		while(H1ptr!=NULL)
		{
			next=(struct Node *)malloc(sizeof(struct Node));
			H2ptr->link=next;
			H2ptr=next;

			H2ptr->COEF=H1ptr->COEF;
			H2ptr->EXP=H1ptr->EXP;
			H2ptr->link=NULL;

			H1ptr=H1ptr->link;
		}
	}

Head2=Head2->link;

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
	printf("\n============================================================================\n");
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
           	printf("\nNo Polynomial is created!\n");
	        return Head;
        }
           
 printf("\nWrong Input!\n");
 return Head;
}


struct Node* SortEXP(struct Node *Head)
{
	struct Node *last,*prev,*next;	
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

	struct Node *Head,*Head1,*Head2,*Head3;
	int i;

    Head=NULL;
    Head1=NULL;
    Head2=NULL;
    Head3=NULL;

    while(1)
    {
    	printf("\n============================================================================\n");

		printf("\n1>  Create Polynomials\n");
		printf("\n2>  Add Polynomials\n\n[NOTE : This option will work only if each Polynomial contain atleast one term]\n");
		printf("\n3>  Display\n\n[NOTE : This option will work only afer addition]\n");
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

	        Head2=Addition(Head,Head1);

	        printf("\nAddition of two Polynomials is done\n");

	        break;

	        case 3:

	        Head3=Display(Head2);

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