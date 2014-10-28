#include<iostream>
#include<cstdio>
using namespace std;
long long a[10010],b[10010];
long long now,ans;
int n,ha,ta,hb,tb,ch,Time;
void qsort(int x,int y)
{
	int i,j;
	long long k,t;
	i=x;j=y;k=a[(x+y)>>1];
	while (i<j)
	{
		while (a[i]<k) i++;
		while (a[j]>k) j--;
		if (i<=j)
		{
			t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}
	if (x<j) qsort(x,j);
	if (i<y) qsort(i,y);
}
int main()
{
	cin>>n;
	ans=0;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	qsort(1,n);
	ha=1;ta=n;hb=1;tb=0;
	Time=0;
	while (1)
	{
		Time++;
		ch=0;
		now=2147483647;
		now=now*now;
		if ((ha<ta)&&(a[ha]+a[ha+1]<now))
		{
			now=a[ha]+a[ha+1];
			ch=1;
		}
		if ((ha<=ta)&&(hb<=tb)&&(a[ha]+b[hb]<now))
		{
			now=a[ha]+b[hb];
			ch=2;
		}
		if ((hb<tb)&&(b[hb]+b[hb+1]<now))
		{
			now=b[hb]+b[hb+1];
			ch=3;
		}
		if (ch==0) break;
		if (ch==1)
		{
			ha+=2;
		}
		else if (ch==2)
		{
			ha++;hb++;
		}
		else
		{
			hb+=2;
		}
		tb++;
		b[tb]=now;
		ans+=now;
	}
	cout<<ans<<endl;
	return 0;
}
