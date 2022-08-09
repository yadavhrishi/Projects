#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
    struct node *prev;
};

template<class T>
class DoublyLL
{
   public:
		struct node<T> *Head;
		int Count;

	  
		DoublyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void Display();
		int CountNode();
		void DeleteFirst();
		void DeleteLast();
		void InsertAtPos(T ,int pos);
		void DeleteAtPos(int pos);
};

template<class T>
DoublyLL<T>::DoublyLL()
{
	Head = NULL;
	Count = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
	struct node<T> *newn = NULL;
	newn = new node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if(Head==NULL)
	{
		Head = newn;

	}

	else
	{
		newn->next = Head;
		Head->prev = newn;
		Head=newn;

	}

	Count++;

}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
	struct node<T> *newn = NULL;
	newn = new node<T>;

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if(Head==NULL)
	{
		Head = newn;

	}

	else
	{
		struct node<T> *temp = Head;

		while(temp->next!=NULL)
		{
			temp=temp->next;

		}

		newn->prev = temp;
		temp->next = newn;

		
	}


	Count++;
}

template<class T>
void DoublyLL<T>::Display()
{
	struct node<T> *temp = Head;

	cout<<"elements from linked list are:"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}


	cout<<endl;



}

template<class T>
int DoublyLL<T>::CountNode()
{
	return Count;
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
	if(Head==NULL)
	{
		return;
	}

	else if(Head->next==NULL)
	{
		delete (Head);
		Head=NULL;
	}

	else
	{
		struct node <T> *temp = Head;

		Head = temp->next;
		delete temp;
		Head->prev = NULL;

	}

	Count--;

}

template<class T>
void DoublyLL<T>::DeleteLast()
{
	if(Head==NULL)
	{
		return;
	}

	else if(Head->next==NULL)
	{
		delete (Head);
		Head=NULL;
	}

	else
	{
		struct node <T> *temp = Head;

		while(temp->next->next!=NULL)
		{
			temp = temp->next;
		}

		delete (temp->next);
		temp->next = NULL;
	}

	Count--;

}

template<class T>
void DoublyLL<T>::InsertAtPos(T no,int pos)
{
	int size = CountNode();

if((pos<1)||(pos>size+1))
{
	return;
}

else if(pos==1)
{
	InsertFirst(no);
}

else if(pos==(size+1))
{
	InsertLast(no);
}

else
{
	struct node<T> *newn = NULL;
	newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	struct  node<T> *temp = Head;

	for(int i=1;i<(pos-1);i++)
	{
		temp=temp->next;

	}

	newn->next = temp->next;
	temp->next->prev = newn;

	newn->prev = temp;
	temp->next = newn;

}

Count++;

}

template<class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
	int size = CountNode();

if((pos<1)||(pos>size))
{
	return;
}

else if(pos==1)
{
	DeleteFirst();
}

else if(pos==(size))
{
	DeleteLast();
}

else
{

	struct node<T> *temp = Head;

	for(int i=1;i<(pos-1);i++)
	{
		temp=temp->next;

	}

	
	temp->next = temp->next->next;
	 delete (temp->next->prev);
	 temp->next->prev = temp;
  
  
}

Count--;

}

int main()
{
	DoublyLL<int>obj1;

    DoublyLL<float>obj2;

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertFirst(156);
    obj1.InsertFirst(586);
    obj1.InsertLast(51);
    obj1.InsertLast(101);

	obj1.Display();
	cout<<"no of nodes are : "<<obj1.CountNode()<<endl;

	obj1.DeleteFirst();
    obj1.DeleteLast();
	
	obj1.Display();
	cout<<"no of nodes are : "<<obj1.CountNode()<<endl;


	obj1.InsertAtPos(425,2);
	obj1.Display();
	cout<<"no of nodes are : "<<obj1.CountNode()<<endl;


	obj1.DeleteAtPos(2);
	obj1.Display();
	cout<<"no of nodes are : "<<obj1.CountNode()<<endl;



	 obj2.InsertFirst(21.11);
    obj2.InsertFirst(11.15);
    obj2.InsertFirst(156.45);
    obj2.InsertFirst(586.26);
    obj2.InsertLast(51.58);
    obj2.InsertLast(101.6);

    obj2.DeleteFirst();
    obj2.DeleteLast();
	
	obj2.Display();
	cout<<"no of nodes are : "<<obj2.CountNode()<<endl;



	obj2.InsertAtPos(425.12,3);
	obj2.Display();
	cout<<"no of nodes are : "<<obj2.CountNode()<<endl;

	obj2.InsertAtPos(42.19,4);
	obj2.Display();
	cout<<"no of nodes are : "<<obj2.CountNode()<<endl;



	obj2.DeleteAtPos(3);
	obj2.Display();
	cout<<"no of nodes are : "<<obj2.CountNode()<<endl;

	obj2.DeleteAtPos(2);
	obj2.Display();
	cout<<"no of nodes are : "<<obj2.CountNode()<<endl;



	return 0;
}
