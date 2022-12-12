#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
	newn->prev=NULL;

    if((*First == NULL) && (*Last == NULL))    
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else   
    {
        newn->next = *First;
		(*First)->prev = newn;
        *First = newn;
        (*Last)->next = *First;
    }
}
void InsertLast(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))    
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else    
    {
        (*Last) -> next = newn;
        *Last = newn;
		newn->prev = *First; 
        (*Last)->next = *First;
    }
}
void DeleteFirst(PPNODE First,PPNODE Last)
{
	if((*First==NULL)&&(*Last==NULL))
	{
		return;
	}
	else if(*First==*Last)
	{
		free(*First);
		*First=NULL;
		(*Last)->next = *First;
		
	}
	else
	{
	   
        *First = (*First) -> next;
        free((*First)->prev);              
        (*First)->prev = NULL; 	
		(*Last)->next = *First;
	}
}
void DeleteLast(PPNODE First,PPNODE Last)
{
	PNODE temp=*First;
	if((*First==NULL)&&(*Last==NULL))
	{
		return;
	}
	else if(*First==*Last)
	{
		free(*First);
		*First=NULL;
		(*Last)->next = *First;
		
	}
	else
	{
		while(temp->next!=*Last)
		{
			temp=temp->next;
		}
	   
	   free(temp->next);
	   *Last=temp;
		(*Last)->next=*First;
        
	}
}
void InsertAtPosition(PPNODE First,PPNODE Last,int no,int iPos)
{
	int iNodeCnt=0;
	int iCnt=0;
	PNODE newn=NULL;
	PNODE temp=NULL;
	
	iNodeCnt = Count(*First,*Last);
	if((iPos<1)||(iPos>(iNodeCnt+1)))
	{
	   printf("Position is Invalid \n");
      return;	   
	}
	if(iPos==1)
	{
		InsertFirst(First,Last,no);
		
	}
	else if(iPos==iNodeCnt+1)
	{
		InsertLast(First,Last,no);
		
	}
	else
	{
	 newn =(PNODE)malloc(sizeof(NODE));
     newn->data=no;
      newn->next=NULL;
	  temp=*First;
	  
	  for(iCnt=0;iCnt<iPos-1;iCnt++)
	  {
		  temp=temp->next;
	  }
	  newn->next=temp->next;
	  temp->next->prev = newn;
	  temp->next=newn;
	  newn->prev = temp; 
	  
       	  
	}
}
void DeleteAtPos(PPNODE First, PPNODE Last, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count(*First, *Last);
    PNODE temp1 = *First;
    PNODE temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First,Last);
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast(First,Last);
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
		 temp2->next->prev = temp1;
        free(temp2);
    }
}
void Display(PNODE First,PNODE Last)
 {
	 printf("The Node in link list are :\n");
	 printf("=>");
	 do
	 {
	    printf("| %d |=>",First->data);
           First=First->next;	
		   
	 }while(First !=Last->next);
		 printf("\n");
		 
 }
 int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;
    do
    {
        iCnt++;
        First = First -> next;
    }while(First != Last->next);
    return iCnt;
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int iRet = 0;
    
    InsertFirst(&Head, &Tail, 51);
    InsertFirst(&Head, &Tail, 21);
    InsertFirst(&Head, &Tail, 11);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("The Number of Node in Linked List are  %d\n",iRet);
	InsertLast(&Head, &Tail, 101);
    InsertLast(&Head, &Tail, 111);
    InsertLast(&Head, &Tail, 151);
	InsertAtPosition(&Head,&Tail,105,4);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("The Number of Node in Linked List are  %d\n",iRet);
	DeleteAtPos(&Head,&Tail,4);
	DeleteFirst(&Head,&Tail);
	DeleteLast(&Head,&Tail);
	
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("The Number of Node in Linked List are  %d\n",iRet);
	
}