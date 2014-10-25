#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<cstring>
using namespace std;
const int size=1000005;
int head,tail,n,k;
int a[size],que[size];
void ins(int u,int type)
{
	if (head==tail)
	{
		que[tail++]=u; return;
	}
	if (type==0)
	{
		while (tail>head&&a[que[tail-1]]<a[u]) tail--;
	} else 
	{
		while (tail>head&&a[que[tail-1]]>a[u]) tail--;
	}
	que[tail++]=u;
}

void pop(int u)
{
	while (que[head]<=u) head++;
}

int main()
{
	//freopen("3.in","r",stdin);
	while (scanf("%d%d",&n,&k)==2)
	{
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		head=0; tail=0;
		for (int i=0;i<k;i++) ins(i,1);
		for (int i=k;i<n;i++)
		{
			printf("%d ",a[que[head]]);
			pop(i-k);
			ins(i,1);
		}
		pop(n-1-k);
		printf("%d\n",a[que[head]]);
		head=0; tail=0;
		for (int i=0;i<k;i++) ins(i,0);
		for (int i=k;i<n;i++)
		{
			printf("%d ",a[que[head]]);
			pop(i-k);
			ins(i,0);
		}
		pop(n-1-k);
		printf("%d\n",a[que[head]]);
	}
	return 0;
}
