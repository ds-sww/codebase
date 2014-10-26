#include<iostream>
#include<cstdio>
using namespace std;
//changed
const int MAXN=1000010;
int a[MAXN],p[MAXN],s[MAXN],mini[MAXN],maxi[MAXN];
int n,k,head,tail;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//mininum
	p[1]=a[1];
	s[1]=1;
	head=1;
	tail=1;
	for (int i=1;i<=k;i++)
	{
		while ((tail>=head)&&(a[i]<=p[tail]))
			tail--;
		tail++;
		p[tail]=a[i];
		s[tail]=i;
	}
	mini[1]=p[1];
	for (int i=2;i<=n-k+1;i++)
	{
		while ((s[head]<i)&&(head<i)) head++;
		while ((tail>=head)&&(a[i+k-1]<=p[tail]))
			tail--;
		tail++;
		p[tail]=a[i+k-1];
		s[tail]=i+k-1;
		mini[i]=p[head];
	}
	//maxinum
	p[1]=a[1];
	s[1]=1;
	head=1;
	tail=1;
	for (int i=1;i<=k;i++)
	{
		while ((tail>=head)&&(a[i]>=p[tail]))
			tail--;
		tail++;
		p[tail]=a[i];
		s[tail]=i;
	}
	maxi[1]=p[1];
	for (int i=2;i<=n-k+1;i++)
	{
		while ((s[head]<i)&&(head<i)) head++;
		while ((tail>=head)&&(a[i+k-1]>=p[tail]))
			tail--;
		tail++;
		p[tail]=a[i+k-1];
		s[tail]=i+k-1;
		maxi[i]=p[head];
	}
	//output
	for (int i=1;i<=n-k;i++)
	printf("%d ",mini[i]);
	printf("%d\n",mini[n-k+1]);
	for (int i=1;i<=n-k;i++)
	printf("%d ",maxi[i]);
	printf("%d\n",maxi[n-k+1]);
	return 0;
}
