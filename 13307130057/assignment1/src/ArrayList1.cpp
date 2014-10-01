#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;
class List {
public :
	virtual int size() const = 0;
	virtual bool isEmpty() const = 0;
	virtual int get(int index) = 0;
	virtual void add(int& element) = 0;
	virtual int remove(int index) = 0;
};
class ArrayList:public List
{
private:
	int *a,n,s;
	const static int s0=10;
	void copy(int *b,int *c,int n)
	{
		int i;
		for (i=0;i<n;i++)
			b[i]=c[i];
	}
	void expand()
	{
		s=s*2;
		int *b=new int[s];
		copy(b,a,n);
		delete []a;
		a=b;
	}
	void shrink()
	{
		if (s<=s0) return;
		s=s/2;
		int *b=new int[s];
		copy(b,a,n);
		delete []a;
		a=b;
	}
	void check(int x)
	{
		assert((x>=0)&&(x<=n));
	}
public:
	ArrayList()
	{
		s=s0;
		a=new int[s];
		n=0;
	}
	ArrayList(int x)
	{
		if (x<=s0) s=s0;
		else s=x;
		a=new int[s];
		n=0;
	}
	~ArrayList()
	{
		delete []a;
	}
	int size() const 
	{
		return n;
	}
	bool isEmpty() const
	{
		if (n==0) return true;
		else return false;
	}
	int get(int x)
	{
		check(x);
		return a[x];
	}
	void add(int& x)
	{
		n++;
		if (n>=s) expand();
		a[n]=x;
	}
	int remove(int x)
	{
		int i,t;
		check(x);
		t=a[x];
		for (i=x;i<n;i++)
			a[i]=a[i+1];
		a[n]=0;
		n--;
		if (n<s/3) shrink();
		return t;
	}
};
int main()
{
	int n,i,x;
	ArrayList a;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>x;
		a.add(x);
	}
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>x;
		cout<<a.remove(x)<<endl;
	}
	return 0;
}
