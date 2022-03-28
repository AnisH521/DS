/*   Name : Anish Naskar
     M.Sc Data Science
     SEM 1   */


#include<stdio.h>
#include<stdlib.h>

struct Node
{
int data;struct Node *link;
};


struct Node* Del_After(struct Node *Head)
{
	int x,i;
	struct Node *wezp,*wezp2;

	     printf("\nEnter the position of data after which you want to delete\n");
         scanf("%d",&x);
         if(x==1)
         {
         	wezp2=Head;
         	wezp=wezp2->link;
         	wezp2->link=wezp->link;
         	free(wezp);
		    wezp=NULL;
	        printf("\nThe value is successfully deleted\n");
            return Head;
         }
         else
         {
         	wezp2=Head;
	        wezp=wezp2->link;
	           while(wezp!=NULL)
	           {
		          for(i=0;i<x-1;i++)
		          {
			       wezp2=wezp;
			       wezp=wezp->link;
		          }
			       wezp2->link=wezp->link;
	               free(wezp);
		           wezp=NULL;
		           printf("\nThe value is successfully deleted\n");
		           return Head;
	           }
	        return Head;
         }        	
}


struct Node* Del_Before(struct Node *Head)
{
	int x,i;
	struct Node *wezp,*wezp2;

	     printf("\nEnter the position of data before which you want to delete\n");
         scanf("%d",&x);

         if(x==2)
         {
         	wezp=Head;
         	wezp2=Head->link;
         	Head=wezp2;
	        free(wezp);
		    wezp=NULL;
		    printf("\nThe value is successfully deleted\n");
		    return Head;

         }
         else
         {
         	wezp2=Head;
	        wezp=wezp2->link;
	           while(wezp!=NULL)
	           {
		          for(i=0;i<x-3;i++)
		          {
			       wezp2=wezp;
			       wezp=wezp->link;
		          }
			       wezp2->link=wezp->link;
	               free(wezp);
		           wezp=NULL;
		           printf("\nThe value is successfully deleted\n");
		           return Head;
	           }
	        return Head;
         }
}


struct Node* Del_Any_posno(struct Node *Head)
{
	int x,i;
	struct Node *wezp,*wezp2;
	wezp2=Head;
	wezp=wezp2->link;
	while(wezp!=NULL)
	{
		 printf("\nEnter the position of data you want to delete\n");
         scanf("%d",&x);

         if(x==1)
         {
         	wezp=Head;
         	wezp2=Head->link;
         	Head=wezp2;
	        free(wezp);
		    wezp=NULL;
		    printf("\nThe value is successfully deleted\n");
		    return Head;

         }
        else
        {
        	for(i=0;i<x-2;i++)
		{
			wezp2=wezp;
			wezp=wezp->link;
		}
		
			 wezp2->link=wezp->link;
	         free(wezp);
		     wezp=NULL;
		     printf("\nThe value is successfully deleted\n");
		     return Head;
        }
    } 
}


struct Node* Del_Any_Val(struct Node *Head)
{
	int x;
	struct Node *wezp,*wezp2;

	 printf("\nEnter the data you want to delete\n");
     scanf("%d",&x);

     wezp2=Head;

     if(wezp2->data==x)
     {
     	wezp=Head;
        wezp2=Head->link;
        Head=wezp2;
	    free(wezp);
		wezp=NULL;
		printf("\nThe value is successfully deleted\n");
	    return Head;
     }

     wezp=wezp2->link;

	while(wezp!=NULL)
	{
	
		if(wezp->data!=x)
		{
			wezp2=wezp;
			wezp=wezp->link;
		}
		else
		{
			 wezp2->link=wezp->link;
	         free(wezp);
		     wezp=NULL;
		     printf("\nThe value is successfully deleted\n");
		     return Head;
	    }
	}
}


struct Node* Del_Beg(struct Node *Head)
{
	struct Node *wezp;
	wezp=Head;
	if(wezp==NULL)
		printf("The lsit is empty : No Deletion");
	else{
		struct Node *wezp2;
	    wezp2=(struct Node *)malloc(sizeof(struct Node));
	    wezp2=Head->link;
		Head=wezp2;
		free(wezp);
		wezp=NULL;
		printf("\nThe value is successfully deleted\n");
	    }
	    return Head;
}


struct Node* Del_End(struct Node *Head)
{
	struct Node *wezp;
	wezp=Head;
	if(wezp->link==NULL)
	{
		printf("\nUse Delete Begin : No Deletion\n");
	}
	else if(wezp==NULL)
	{
		printf("\nThe List Is Empty!\n");
	}
	else
	{
		struct Node *wezp2;
	    wezp2=(struct Node *)malloc(sizeof(struct Node));
		while(wezp->link!=NULL)
		{
			wezp2=wezp;
		    wezp=wezp->link;
	    }
	    wezp2->link=NULL;
		free(wezp);
		wezp=NULL;
		printf("\nThe value is successfully deleted\n");
	}
	return Head;
}
	

struct Node* Display(struct Node *Head)
{
	if(Head==NULL)
		printf("\nLinked list is Empty\n");
	struct Node *wezp=NULL;
	wezp=Head;
	printf("\n===================================\n");
	while(wezp!=NULL)
	{
		printf("%d\t",wezp->data);
		wezp=wezp->link;
	}
	printf("\n===================================\n");
	return Head;
}


struct Node* Insert_End(struct Node *Head)
{
	int x;
	struct Node *wezp, *Temp;
	wezp=Head;
	Temp=(struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter the value you want to enter inside node\n");
	scanf("%d",&x);
	Temp->data=x;
	Temp->link=NULL;
	while(wezp->link!=NULL)
	{
		wezp=wezp->link;
	}
	wezp->link=Temp;
	return Head;
}


struct Node* create_list(struct Node *Head)
{
	int x,x1,x2;
	char choice;
    printf("\nEnter 1 to create node Else Enter 0\n");
    scanf("%d",&x2);
        if(x2==1)
    {
       Head=(struct Node *)malloc(sizeof(struct Node));
       printf("\nEnter the number you want to put inside Node\n");
       scanf("%d",&x1);
       Head->data=x1;
       Head->link=NULL;
       pnt :
         printf("\nDo You Want To Continue(y/n)?\n");
         scanf("%s",&choice);
            if(choice=='y')
            {
                Insert_End(Head);
                goto pnt;
            }
            else if(choice=='n')
            {
            	printf("\nLinked list Creation is Done!\n");
	            return Head;
            }
    }
         else if(x2==0)
           {
           	    printf("\nNo Node is created!\n");
	            return Head;
           }
         printf("\nWrong Input!\n");
         return Head;
}


struct Node* Insert_Beg(struct Node *Head)
{
    int x;
	struct Node *wezp;
	wezp=(struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter the number you want to put inside Node\n");
    scanf("%d",&x);
    wezp->data=x;
    wezp->link=NULL;
    wezp->link=Head;
    Head=wezp;
    printf("Insertion Done!");
    return Head;
}


struct Node* Rev(struct Node *Head)
{
	struct Node *wezp=NULL;
	struct Node *wezp2=NULL;
	while(Head!=NULL)
	{
		wezp2=Head->link;
		Head->link=wezp;
		wezp=Head;
		Head=wezp2;
	}
	Head=wezp;
	printf("\nReversal Done!\n");
	return Head;
}


struct Node* Sort(struct Node *Head)
{
	struct Node *last,*wezp,*wezp2;	
	for(last=NULL;last!=Head->link;last=wezp)
	{
		for(wezp=Head;wezp->link!=last;wezp=wezp->link)
		{
			wezp2=wezp->link;
			if(wezp->data>wezp2->data)
			{
				wezp->data=wezp->data+wezp2->data;
				wezp2->data=wezp->data-wezp2->data;
				wezp->data=wezp->data-wezp2->data;
			}
		}
	}
	printf("Sorting Done!");
	return Head;
}	


struct Node* Insert_At_A_Specific_Position(struct Node *Head)
{
	int x,y;
	struct Node *wezp, *wezp2;
	wezp=Head;
	wezp2=(struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter the number you want to put inside Node\n");
    scanf("%d",&x);
    wezp2->data=x;
    wezp2->link=NULL;

	printf("\nEnter the position where you want to put the Node\n");
    scanf("%d",&y);
	while(y!=2)
	{
		wezp=wezp->link;
		y--;
	}
	wezp2->link=wezp->link;
	wezp->link=wezp2;
	printf("Insertion Done!");
	return Head;
}


struct Node* After_a_Node(struct Node *Head)
{
	int x,y,p;
	struct Node *wezp, *wezp2;
	wezp=Head;
	wezp2=(struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter the number you want to put inside Node\n");
    scanf("%d",&x);
    wezp2->data=x;
    wezp2->link=NULL;

	printf("\nEnter the node number after which you want to enter this node\n");
    scanf("%d",&p);
	for(y=1;y<p;y++)
	{
		wezp=wezp->link;
	}
	wezp2->link=wezp->link;
	wezp->link=wezp2;
	printf("Insertion Done!");
	return Head;
}


struct Node* Before_a_Node(struct Node *Head)
{
	int x,p,y;
	struct Node *wezp, *wezp2;
	wezp=Head;
	wezp2=(struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter the number you want to put inside Node\n");
    scanf("%d",&x);
    wezp2->data=x;
    wezp2->link=NULL;

	printf("\nEnter the node number before which you want to enter this node\n");
    scanf("%d",&p);
	for(y=1;y<p-2;y++)
	{
		wezp=wezp->link;
	}
	wezp2->link=wezp->link;
	wezp->link=wezp2;
	printf("Insertion Done!");
	return Head;
}


struct Node *conc(struct Node *Head,struct Node *Head1,struct Node *Head2)
{
	struct Node *ptr;
	ptr=Head1;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=Head2;
	Head=Head1;
	return Head;
}


int main()
{
    struct Node *Head,*Head1,*Head2;
    Head=NULL;
    Head1=NULL;
    Head2=NULL;
	printf("Only Integers will work in case of this program\n\n ");
	int u,v,x,y,z;
	while(99)
	{
		printf("\n===================================\n");

		printf("\n1>  Create list\n");
		printf("\n2>  Insert\n");
		printf("\n3>  Deletion\n");
		printf("\n4>  Display\n");
		printf("\n5>  Concatenate\n");
		printf("\n6>  Reverse\n");
		printf("\n7>  Sort\n");
		printf("\n8>  Exit\n");


		printf("\n===================================\n");
		printf("\nEnter Your Choice\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
			Head=create_list(Head);
			break;

			case 2:
			printf("\n===================================\n");

			printf("\n5>  Insert at beginning\n");
		    printf("\n6>  Insert at end\n");
			printf("\n7>  Insert at any Position\n");
			printf("\n8>  goto main menu\n");

			printf("\n===================================\n");
			printf("\nEnter Your Choice\n");
			scanf("%d",&y);
			if(y==5)
			{
				Head=Insert_Beg(Head);
			}
			else if(y==6)
				{
					Head=Insert_End(Head);
				}
			else if(y==7)
				{
					printf("\n===================================\n");

					printf("\n9>   Insert after a node\n");
		            printf("\n10>  Insert Before a node\n");
		            printf("\n11>  Insert at Specific position\n");
					printf("\n12>  goto main menu\n");

					printf("\n===================================\n");
					printf("\nEnter Your Choice\n");
					scanf("%d",&z);
					if(z==9)
					{
						Head=After_a_Node(Head);
					}
					else if(z==10)
					{
						Head=Before_a_Node(Head);
					}
					else if(z==11)
					{
						Head=Insert_At_A_Specific_Position(Head);
					}
					else if(z==12)
					{
						continue;
					}
					else
						printf("\n wrong choice , you have returned to main menu\n");
				}
				else if(y==8)
				{
					continue;
				}
				else
				{   printf("\n===================================\n");
					printf("\nwrong choice , you have returned to main menu\n");
					printf("\n===================================\n");
				}


			break;

			case 3:
			printf("\n===================================\n");

			printf("\n13>  Delete from Beginning\n");
			printf("\n14>  Delete from End\n");
			printf("\n15>  Delete from Specific Position\n");
			printf("\n16>  goto main menu\n");

			printf("\n===================================\n");
			printf("\nEnter Your Choice\n");
			scanf("%d",&v);
			if(v==13)
			{
				Head=Del_Beg(Head);
			}
			else if(v==14)
			{
				Head=Del_End(Head);
			}
			else if(v==15)
			{
				printf("\n===================================\n");

				printf("\n17>  Delete after a Node\n");
			    printf("\n18>  Delete before a node\n");
			    printf("\n19>  Delete Node in Specific Position\n");
			    printf("\n20>  Delete Node with Specific value\n");
			    printf("\n21>  goto main menu\n");

			    printf("\n===================================\n");
			    printf("\nEnter Your Choice\n");
			    scanf("%d",&u);

			    if(u==17)
		    	{
		    		Head=Del_After(Head);
		    	}
		    	else if(u==18)
		    	{
		    		Head=Del_Before(Head);
		    	}
		    	else if(u==19)
		    	{
		    		Head=Del_Any_posno(Head);
		    	}
		    	else if(u==20)
		    	{
		    		Head=Del_Any_Val(Head);
		    	}
		    	else if(u==21)
		    	{
		    		continue;
		    	}
			}
			else
				{
					printf("\n===================================\n");
					printf("\nwrong choice , you have returned to main menu\n");
					printf("\n===================================\n");
				}

			break;

			case 4:
			Head=Display(Head);
			break;

			case 5:
			{
				printf("\n===================================\n");
				printf("List 1");
				printf("\n===================================\n");
				Head1=create_list(Head1);
				printf("\n===================================\n");
				printf("List 2");
				printf("\n===================================\n");
				Head2=create_list(Head2);
				Head=conc(Head,Head1,Head2);
				printf("\nConcatenation Done!\n");
			}
			break;

			case 6:
			{
				Head=Rev(Head);
			}
			break;

			case 7:
			{
				Head=Sort(Head);
			}
			break;

			case 8:
			{
				printf("\n===================================\n");
				printf("\nProcess Ends\n\n***Thank You***\n\n");
				printf("\n===================================\n");
			    return 0;
			}
			break;


			default :
			printf("\nYou Entered  Incorrect Choice\n");
		}
	}
	return 0;
}