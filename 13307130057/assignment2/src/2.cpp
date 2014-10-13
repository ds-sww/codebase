#include <cstdio>
#include <iostream>
using namespace std;
int a[10000];
void work(int l,int r)
{
	int i,j,x,t;
	i=l;j=r;
	x=a[(l+r)/2];
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
	if (j<r) work(l,j);
	if (i>l) work(i,r);
}
int main()
{
	int n,i,j,s,t;
	cin>>n;
	for (i=0;i<n;i++)
		cin>>a[i];
	work(0,n-1);
	s=0;
	while (n>2)
	{
		t=a[0]+a[1];
		s=s+t;
		i=2;
		while ((a[i]<t)&&(i<n))
		{
			a[i-2]=a[i];
			i++;
		}
		a[i-2]=t;
		n--;
		for (j=i-1;j<n;j++)
			a[j]=a[j+1];
	}
	s=s+a[0]+a[1];
	cout<<s<<endl;
	return 0;
}