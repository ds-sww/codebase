#include <cstdio>
#include <iostream>
using namespace std;
long long a[100000],l[100000],r[100000];
int main()
{
	int n,i;
	long long s,max;
	cin>>n;
	while (n)
	{
		for (i=0;i<n;i++)
		{
			cin>>a[i];
			l[i]=i;r[i]=i;
		}
		for (i=1;i<n;i++)
			while ((l[i]>0)&&(a[l[i]-1]>=a[i])) l[i]=l[l[i]-1];
		for (i=n-2;i>=0;i--)
			while ((r[i]<n-1)&&(a[r[i]+1]>=a[i])) r[i]=r[r[i]+1];
		max=0;
		for (i=0;i<n;i++)
		{
			s=(r[i]-l[i]+1)*a[i];
			if (s>max) max=s;
		}
		cout<<max<<endl;
		cin>>n;
	}
	return 0;
}