#include<iostream>
#include"filesingly.h"
//#include"Record.h"
using namespace std;
template<class T >
class Hash
{
	sllist<T> *h;
public:
	Hash()
	{
		h=new sllist<T>[26];
	}
	~Hash()
	{
		delete []h;
	}
	void insert(T x);
	int index(T x);
	void insert1(T x);
	int index1(T x);
	void display();
};
template<class T>
void Hash<T>::insert(T x)
{
	int i=index(x);
	h[i].inslast(x);
}
template<class T>
int Hash<T>::index(T x)
{
	string s=x.firstname;
	int i=x.firstname[0]%26;
	return i;
}
//for second type sorting
template<class T>
void Hash<T>::insert1(T x)
{
	int i=index1(x);
	h[i].inslast(x);
}
template<class T>
int Hash<T>::index1(T x)
{
	string s=x.lastname;
	int i=x.lastname[0]%26;
	return i;
}
template<class T>
void Hash<T>::display()
{
	for(int i=0;i<26;i++)
	{
		cout<<"h["<<i<<"]="<<endl;
		h[i].display_sll();
		cout<<endl;
	}
}

