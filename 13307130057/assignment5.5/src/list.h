#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;
void qs(int a[],int l,int r)
{
	int i,j,x,t;
	i=l;j=r;
	x=a[(i+j)/2];
	do
	{
		while ((a[i]<x)&&(i<r)) i++;
		while ((a[j]>x)&&(j>l)) j--;
		if (i<j)
		{
			t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}while (i<j);
	if (j<r) qs(a,l,j);
	if (i>l) qs(a,i,r);
}
struct Node
{
	int num;
	Node *next;
};
class List
{
private:
	Node *head;
public:
	List()
	{
		head=NULL;
	}
	void create()
	{
		int n,i;
		Node *a;
		cin>>n;
		assert(n>=0);
		head=new Node[sizeof(Node)];
		if (n==0)
		{
			head->next=NULL;
			return;
		}
		head->next=a=new Node[sizeof(Node)];
		for (i=0;i<n-1;i++)
		{
			cin>>a->num;
			a=a->next=new Node[sizeof(Node)];
		}
		cin>>a->num;
		a->next=NULL;
	}
	int size()
	{
		Node *a;
		int i=0;
		if ((head==NULL)||(head->next==NULL)) return 0;
		for (a=head->next;a;a=a->next) i++;
		return i;
	}
	void display()
	{
		Node *a;
		if (head->next==NULL)
		{
			cout<<"No elements!"<<endl;
			return;
		}
		for (a=head->next;a->next;a=a->next)
			cout<<a->num<<' ';
		cout<<a->num<<endl;
	}
	void insert(int x,int y)
	{
		Node *a,*b;
		int i;
		if (y<0) 
		{
			cout<<"Error!"<<endl;
			return;
		}
		if (y==0)
		{
			a=new Node[sizeof(Node)];
			a->num=x;
			a->next=head->next;
			head->next=a;
		}
		else 
		{
			a=head->next;
			for (i=0;i<y-1;i++)
			{
				if (a==NULL)
				{
					cout<<"Error!"<<endl;
					return;
				}
				a=a->next;
			}
			if (a==NULL)
			{
				cout<<"Error!"<<endl;
				return;
			}
			b=new Node[sizeof(Node)];
			b->num=x;
			b->next=a->next;
			a->next=b;
		}
		return;
	}
	int remove(int x)
	{
		Node *a,*b;
		int i,t;
		if ((x<0)||(head->next==NULL))
		{
			cout<<"Error!"<<endl;
			return 2147483647;
		}
		b=head->next;
		if (x==0)
		{
			t=b->num;
			a=b->next;
			delete b;
			head->next=a;
			return t;
		}
		else 
		{
			a=head->next;
			for (i=0;i<x-1;i++)
			{
				if (a->next==NULL)
				{
					cout<<"Error!"<<endl;
					return 2147483647;
				}
				a=a->next;
			}
			if (a->next==NULL)
			{
				cout<<"Error!"<<endl;
				return 2147483647;
			}
			t=a->next->num;
			b=a->next;
			a->next=a->next->next;
			delete b;
			return t;
		}
	}
	int pos(int x)
	{
		Node *a;
		int i=0;
		for (a=head->next;a;a=a->next)
		{
			if (a->num==x) return i;
			i++;
		}
		return -1;
	}
	void sort(int x,int y)
	{
		Node *a;
		int i,p[10000];
		memset(p,0,sizeof(p));
		i=0;
		for (a=head->next;a;a=a->next)
		{
			p[i]=a->num;
			i++;
		}
		if (y>=i)
		{
			cout<<"Error!"<<endl;
			return;
		}
		qs(p,x,y);
		a=head->next;
		for (i=0;i<x;i++) a=a->next;
		for (i=x;i<=y;i++)
		{
			a->num=p[i];
			a=a->next;
		}
	}
};