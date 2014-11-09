#include <iostream>
#include <cstdio>
using namespace std;
void merge(int a[],int l,int r)
{
	int i,j,k,x,p,b[100000];
	x=(l+r)/2;i=k=l;j=x+1;
	while ((i<=x)&&(j<=r))
	{
		if (a[i]<a[j]) 
		{
			if (i<=x) b[k++]=a[i++];
		}
		else
		{
			if (j<=r) b[k++]=a[j++];
		}
	}
	for (p=i;p<=x;p++) b[k++]=a[p];
	for (p=j;p<=r;p++) b[k++]=a[p];
	for (i=l;i<=r;i++) a[i]=b[i];
}
void ms(int a[],int l,int r)
{
	if (l>=r) return;
	int m=(l+r)/2;
	ms(a,l,m);
	ms(a,m+1,r);
	merge(a,l,r);
}
int main()
{
	int n,i,a[100000];
	cin>>n;
	for (i=0;i<n;i++) cin>>a[i];
	ms(a,0,n-1);
	for (i=0;i<n-1;i++) cout<<a[i]<<' ';
	cout<<a[n-1]<<endl;
	return 0;
}