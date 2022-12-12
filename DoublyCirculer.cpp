# include<iostream>
 using namespace std;
 
 # pragma pack(1)
 
 struct node
 {
	 int data;
	 struct node * next;
	  struct node *prev; 
 };
 typedef struct node NODE;
 typedef struct node * PNODE;
 
 class  SinglyLL 
 {
    public :
     	PNODE First;
		PNODE Last;
		int iCount;
		
		SinglyLL();
		
		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPosition(int no,int iPos);
		
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPosition(int iPos);
		
		void Display();
		
	
 };
  SinglyLL :: SinglyLL()
  {
	  First=NULL;
	  
	  iCount =0;
	  
  }
  void SinglyLL ::InsertFirst(int no)
  {
	PNODE newn = new NODE;
    newn->data=no;
    newn ->next =NULL;	
	newn->prev = NULL;  
	
	if(First==NULL)
	{
		
		First=newn;
		(First)->prev = newn;
		Last->next=First;
		iCount++;
		
	}
	else
	{
		newn->next=First;
		First=newn;
		iCount++;
		
	}
  }
  void SinglyLL ::InsertLast(int no)
  {
	PNODE newn = new NODE;
    newn->data=no;
    newn ->next =NULL;	
	newn->prev=NULL;
	if(First==NULL)
	{
		
		First=newn;
		Last->next=First;
		iCount++;
		
	}
	else
	{
		PNODE temp =First;
		while(temp->next !=NULL)
		{
			temp=temp->next;
			
		}
		temp->next=newn;
		newn->prev=temp;
		Last->next=First;
		iCount++;
		
	}
  }
  void SinglyLL ::InsertAtPosition(int no,int iPos)
  {
	 
	if((iPos < 1) ||(iPos >iCount+1))
	{
	    cout<<"postion is Invalid \n";
		return;
	}
	if(iPos==1)
	{
		InsertFirst(no);
	}
	else if(iPos ==iCount+1)
		
	{
		InsertLast(no);
		Last->next=First;
	}
	else
	{
		PNODE newn =new NODE;
		newn->data=no;
		newn->next=NULL;
		newn->next=NULL;
		PNODE temp=First;
		for(int iCnt=0;iCnt<iPos-1;iCnt++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		Last->next=First;
		iCount++;
		
	}
  }
  void SinglyLL :: DeleteFirst()
  {
	  if(First==NULL)
	  {
		  return;
	  }
	  else if(First ->next==NULL)
	  {
		  delete(First);
		  First=NULL;
		  Last->next=First;
		  iCount--;
		  
	  }
	  else
	  {
		  PNODE temp=First;
		  
		  First=First->next;
		  delete(temp->prev);
		  (First)->prev=NULL;
		  Last->next=First;
		  iCount--;
	  }
  }
  void SinglyLL :: DeleteLast()
  {
	  if(First==NULL)
	  {
		  return;
	  }
	  else if(First ->next==NULL)
	  {
		  delete(First);
		  First=NULL;
		  iCount--;
		  
	  }
	  else
	  {
		  PNODE temp=First;
		  
		  while(temp->next->next!=NULL)
		  {
			  temp=temp->next;
			  
		  }
		  delete(temp->next);
		  temp->next=NULL;
		  Last->next=First;
		  iCount--;
	  }
  }
   void SinglyLL :: DeleteAtPosition(int ipos)
{
	
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        PNODE temp2 = temp1->next;

        temp1->next = temp2->next;
		temp2->next->prev = temp1; 
        delete temp2;
      Last->next=First;
        iCount--;
    }
}
  void SinglyLL ::Display()
  {
	  cout<<"Node in link list are"<<"\n";
	  cout<<"NULL <=>";
	  
	  PNODE temp=First;
	  while(temp != NULL)
	  {
		  cout<<" | "<<temp->data <<" |=> ";
		  temp=temp->next;
		  
	  }
	 
	  
	  
  }
 int main()
 {
	SinglyLL obj; 
	 obj.InsertFirst(51);
	 obj.InsertFirst(21);
	 obj.InsertFirst(11);
	 cout<<"\n";
	 obj.Display();
  
  cout<<"The Number of node in linklist is : "<<obj.iCount<<"\n";
  
	 obj.InsertLast(101);
	 obj.InsertLast(111);
	 obj.InsertLast(121);
	 cout<<"\n";
	 obj.Display();
	 cout<<"\n";
	 cout<<"The Number of node in linklist is : "<<obj.iCount<<"\n";
	
	 obj.InsertAtPosition(105,4);
	  obj.Display();
	  
	 cout<<"\n";
	 cout<<"The Number of node in linklist is : "<<obj.iCount<<"\n";
	  
	  obj.DeleteFirst();
	 obj.Display();
	 cout<<"\n";
	 
	 cout<<"The Number of node in linklist is : "<<obj.iCount<<"\n";
	 
	 obj.DeleteLast();
	 obj.Display();
	 cout<<"\n";
	 cout<<"The Number of node in linklist is : "<<obj.iCount<<"\n";
	 
	 obj.DeleteAtPosition(4);
	 obj.Display();
	 cout<<"\n";
	 cout<<"The Number of node in linklist is : "<<obj.iCount<<"\n";
	 
	 return 0;
	 
 }