#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000],b[1000000],m[1000000];
int main()
{
	int n,i,k,h,t;
	cin>>n>>k;
	for (i=0;i<n;i++) cin>>a[i];
	for (i=0;i<k;i++) b[i]=0;
	b[0]=a[0];h=0;t=1;m[0]=0;
	for (i=1;i<n;i++)
	{
		while (m[h]<i-k+1)
		{
			b[h]=0;h++;
		}
		while ((t>h)&&(a[i]<b[t-1]))
		{
			t--;b[t]=0;
		}
		if (t-h<k)
		{
			b[t]=a[i];m[t]=i;t++;
		}
		else
		{
			b[h]=0;h++;
		}
		if (i>k-2) cout<<b[h]<<' ';
	}
	cout<<endl;
	for (i=0;i<k;i++) b[i]=0;
	b[0]=a[0];h=0;t=1;m[0]=0;
	for (i=1;i<n;i++)
	{
		while (m[h]<i-k+1)
		{
			b[h]=0;h++;
		}
		while ((t>h)&&(a[i]>b[t-1]))
		{
			t--;b[t]=0;
		}
		if (t-h<k)
		{
			b[t]=a[i];m[t]=i;t++;
		}
		else
		{
			b[h]=0;h++;
		}
		if (i>k-2) cout<<b[h]<<' ';
	}
	cout<<endl;
	return 0;
}