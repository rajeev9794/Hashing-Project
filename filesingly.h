#include<iostream>
using namespace std;
template<class T>
class node
{
public:
	T info;
	node<T> *next;

	node()
	{
		info=0;
		next=NULL;
	}
	node(T x)
	{
		info=x;
		next=NULL;
	}
	~node()
	{
	}
	
	
};
template<class T>
class sllist
{
	node<T> *head;
public:
	sllist()
	{
		head=NULL;
	}
	~sllist()
	{
	
	}
	void insbeg(T x);
	void inslast(T x);
	void display_sll();
};
template<class T>
void sllist<T>::insbeg(T x)
{	
	node<T> *p;
	p=new node<T>(x);
	if(head==NULL)
	{
		head=p;
	}
	else{
	p->next=head;
	head=p;
	}
}
template<class T>
void sllist<T>::inslast(T x)
{
	node<T> *p,*q,*r;
	q=new node<T>(x);
	p=head;
	if(p==NULL)
	{
	head=q;
	}
	else{
	
	while(p!=NULL)
	{
	r=p;
	p=p->next;
	}
	r->next=q;
	}
}
template<class T>
void sllist<T>::display_sll()
{
	node<T> *p;
	p=head;
	while(p!=NULL)
	{
		cout<<"->"<<p->info;
		p=p->next;
	}
}
