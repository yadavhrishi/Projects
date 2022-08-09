#include<iostream>
using namespace std;

template <class T>
struct node
{
	T data;
	struct node *next;
};

template <class T>
class SinglyLL
{
	public:
		struct node<T> *Head;
		int Count;
		
		SinglyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T no,T iPos);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int iPos);
		void Display();
		int CountNode();
};

template<class T>
SinglyLL<T>::SinglyLL()
{
	Head = NULL;
	Count = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
	struct node<T> *newn = NULL;
	newn = new node<T>;
	
	newn->data = no;
	newn->next = NULL;
	
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		newn->next = Head;
		Head = newn;
	}
	Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
	struct node<T> *newn = NULL;
	newn = new node<T>;
	
	newn->data = no;
	newn->next = NULL;
	
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		struct node<T> *temp = Head;
		while(temp->next !=NULL)
		{
			temp = temp ->next;
		}
		
		temp->next = newn;
	}
	Count++;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T no,T iPos)
{
	int iSize = CountNode();
	
	if((iPos<1)&&(iPos>(iSize+1)))
	{
		return;
	}
	else if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == iSize+1)
	{
		InsertLast(no);
	}
	else
	{
		struct node <T> *newn = NULL;
		newn = new node<T>;
		
		newn->data = no;
		newn->next = NULL;
		
		struct node <T>*temp = Head;
		
		for(int i=1;i<(iPos-1);i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
	}
	Count++;
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
	struct node <T> *temp = Head;
	
	if(Head == NULL)
	{
		return;
	}
	else
	{
		Head = Head->next;
		delete(temp);
		Count--;
	}

}

template<class T>
void SinglyLL<T>::DeleteLast()
{
	struct node <T> *temp = Head;
	
	if(Head == NULL)
	{
		return;
	}
	else if(Head->next ==NULL)
	{
		delete Head;
		Head = NULL;
 	}
	else
	{
		
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete(temp->next);
	}
	temp->next = NULL;
	Count--;
}

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
	int iSize = CountNode();
	
	if((iPos<1)&&(iPos>(iSize+1)))
	{
		return;
	}
	else if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize+1)
	{
		DeleteLast();
	}
	else
	{
		
		struct node <T>*temp = Head;
		struct node <T>*tempdelete = NULL;
		
		for(int i=1;i<(iPos-1);i++)
		{
			temp = temp->next;
		}
		tempdelete = temp->next;
		temp->next = tempdelete->next;
		free(tempdelete);
	}
	Count--;
}

template <class T>
void SinglyLL<T>::Display()
{
	cout<<"Elemets from linked list are: "<<endl;
	struct node<T> *temp = Head;
	while(temp !=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

template<class T>
int SinglyLL<T>::CountNode()
{
	return Count;
}

int main()
{
    SinglyLL<int>obj1;
	SinglyLL<float>obj2;
	
	obj1.InsertFirst(21);
	obj1.InsertFirst(11);
	obj1.InsertLast(51);
	obj1.InsertLast(101);
	
	obj1.Display();
	cout<<"Number of nodes are: "<<obj1.CountNode()<<endl;
	
	obj2.InsertFirst(21.11);
	obj2.InsertFirst(11.23);
	obj2.InsertLast(51.54);
	obj2.InsertLast(101.87);
	obj2.Display();
	cout<<"Number of nodes are: "<<obj2.CountNode()<<endl;
	
	obj1.DeleteFirst();
	obj1.DeleteLast();
	
	obj2.DeleteFirst();
	obj2.DeleteLast();
	
	
	cout<<"\n\n";
	obj1.Display();
	cout<<"Number of nodes are: "<<obj1.CountNode()<<endl;
	
	obj2.Display();
	cout<<"Number of nodes are: "<<obj2.CountNode()<<endl;
	
	obj1.InsertAtPos(100,2);
	obj2.InsertAtPos(9.3,2);
	
	cout<<"\n\n";
	obj1.Display();
	cout<<"Number of nodes are: "<<obj1.CountNode()<<endl;
	
	obj1.DeleteAtPos(2);
	obj2.DeleteAtPos(2);
	
	
	cout<<"\n\n";
	obj1.Display();
	cout<<"Number of nodes are: "<<obj1.CountNode()<<endl;
	
	obj2.Display();
	cout<<"Number of nodes are: "<<obj2.CountNode()<<endl;

	return 0;
}