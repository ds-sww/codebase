#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
class Heap
{
private:
	int n,a[10000];
	void down(int x,int y)
	{
		int i,j;
		j=x*2+1;i=x;
		if (j>=y) return;
		if ((j+1<y)&&(a[j]<a[j+1])) j++; 
		while (a[i]<a[j])
		{
			swap(a[i],a[j]);
			i=j;j=i*2+1;
			if (j>=y) break;
			if ((j+1<y)&&(a[j]<a[j+1])) j++;
		}
	}
	void up(int x)
	{
		int i,j;
		if (x==0) return;
		j=(x-1)/2;i=x;
		while (a[i]>a[j])
		{
			swap(a[i],a[j]);
			if (j<=0) break;
			i=j;j=(i-1)/2;
		}
	}
public:
	Heap()
	{
		n=0;a[0]=-1;
	}
	int size()
	{
		return n;
	}
	void create()
	{
		int i;
		cin>>n;
		for (i=0;i<n;i++)
			cin>>a[i];
		a[n]=-1;
		for (i=(n-2)/2;i>=0;i--) down(i,n);
	}
	void display()
	{
		int i;
		for (i=0;i<n-1;i++)
			cout<<a[i]<<' ';
		cout<<a[n-1]<<endl;
	}
	void insert(int x)
	{
		a[n]=x;n++;a[n]=-1;
		up(x);
	}
	int remove(int x)
	{
		int t;
		t=a[x];n--;
		a[x]=a[n];a[n]=-1;
		up(x);down(x,n);
		return t;
	}
	void hs(int x,int y)
	{
		int i;
		for (i=y;i>x;i--)
		{
			swap(a[0],a[i]);
			down(0,i);
		}
	}
};
int main()
{
	Heap a;
	a.create();
	a.hs(0,a.size()-1);
	a.display();
	return 0;
}