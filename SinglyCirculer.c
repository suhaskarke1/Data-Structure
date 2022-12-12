#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))    // Empty LL
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else    // LL contains atleast one node
    {
        newn->next = *First;
        *First = newn;
        (*Last)->next = *First;
    }
}

void InsertLast(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))    // Empty LL
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else    // LL contains atleast one node
    {
        (*Last) -> next = newn;
        *Last = newn;
        (*Last)->next = *First;
    }
}
void DeleteFirst(PPNODE First, PPNODE Last)
{
	

     if((*First == NULL) && (*Last == NULL))   
    {
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
		*First=NULL;
		*Last=NULL;
       
    }
    else 
    {
        (*First) = (*First) -> next;
        free((*Last)->next);
		(*Last)->next = *First;
		
// (*First)=(*First)->next;
		//free(temp);
		//(*Last)->next=*First;
		
    }


}
void DeleteLast(PPNODE First, PPNODE Last)
{
	
    PNODE temp = *First;

     if((*First == NULL) && (*Last == NULL))   // A
    {
        return;
    }
    else if(*First==*Last)
    {
        free(*First);
       (*Last)->next = *First;
    }
    else // C
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
	  temp->next=newn;
	  
       	  
	}
}
void DeleteAtPosition(PPNODE First,PPNODE Last,int iPos)
{
	int iNodeCnt=0;
	int iCnt=0;
	
	PNODE temp1=*First;
	PNODE temp2=NULL;
	
	iNodeCnt = Count(*First,*Last);
	if((iPos<1)||(iPos>iNodeCnt))
	{
	   printf("Position is Invalid \n");
      return;	   
	}
	if(iPos==1)
	{
		DeleteFirst(First,Last);
		
	}
	else if(iPos==iNodeCnt+1)
	{
		DeleteLast(First,Last);
		
		
	}
	else
	{
	  for(iCnt=1;iCnt<iPos-1;iCnt++)
	  {
		  temp1=temp1->next;
	  }
	  
       	  temp2 =temp1->next;
		  temp1->next=temp2->next;
		  free(temp2);
	}
}
void Display(PNODE First,PNODE Last)
 {
	 printf("The Node in link list are :\n");
	 do
	 {
	    printf("| %d |->",First->data);
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
    
    InsertLast(&Head, &Tail, 101);
    InsertLast(&Head, &Tail, 111);
    InsertLast(&Head, &Tail, 121);
    Display(Head, Tail);
    iRet = Count(Head, Tail);

    printf("Number of elements are : %d\n",iRet);
    InsertAtPosition(&Head,&Tail,105,3);
	Display(Head, Tail);
    iRet = Count(Head, Tail);
	printf("Number of elements are : %d\n",iRet);
	
 DeleteAtPosition(&Head,&Tail,3);
	Display(Head, Tail);
    iRet = Count(Head, Tail);
	printf("Number of elements are : %d\n",iRet);
	
    
	DeleteFirst(&Head,&Tail);
	Display(Head, Tail);
    iRet = Count(Head, Tail);

    printf("Number of elements are : %d\n",iRet);
	
	DeleteLast(&Head,&Tail);
	Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of elements are : %d\n",iRet);
	
	
	

    return 0;
}