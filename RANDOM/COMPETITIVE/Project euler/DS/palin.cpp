#include<iostream>
using namespace std;
class node{
	public:
	char v;
	node *next;
    node *prev;
};
class queue{
	node *front,*rear;
	int size;
	public:
	queue()
	{
		front=new node();
		rear=NULL;
		size=0;
	}
	void enqueue(char a)
	{
		node *newnode=new node();
		newnode->v=a;
		if(rear!=NULL)
		{
			rear->next=newnode;
			newnode->prev=rear;
			newnode->next=NULL;
			rear=newnode;
		}
		else
		{
			front->next=newnode;
			front->prev=NULL;
			newnode->next=NULL;
			newnode->prev=front;
			rear=newnode;
		}
		size++;
	}
	int si()
	{
		return size;
	}
	int check()
	{
		int count;
		node *p=new node();
		p=front->next;
	    	while(p!=NULL && rear!=NULL)
	    	{
	    		if(p->v==rear->v)
	    		{
	    			count++;
	    		}
	    		p=p->next;
	    		rear=rear->prev;
	    	}
	    	return count;

	}
};
int main()
{
	queue q1;
		int s,num;
	cout<<"Enter size of string :";
	cin>>s;
		char a[s],n;
	cout<<"Enter string :";
	cin>>a;
	for(int i=0;i<s;i++)
	{
		n=a[i];
		q1.enqueue(n);
	}

	num=q1.check();
	int ns=s%2;
	if(ns==1)
	{
	if(num==(s-1))
	{
		cout<<"Palindrome"<<endl;
	}
	else
	{
		cout<<"not a Palindrome";
	}
    }
    else
    {
    	if(num==s)
	{
		cout<<"Palindrome"<<endl;
	}
	else
	{
		cout<<"not a Palindrome";
	}
    }
	return 0;
}
