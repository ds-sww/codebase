#include<iostream>
#include<cstdio>
using namespace std;
int a[10001],b[10001],s[10001];
int n,top,head;
int main()
{
	scanf("%d",&n);
	while (n!=0)
	{
		scanf("%d",&a[1]);
		while (n!=0)
		{
			for (int i=2;i<=n;i++)
				scanf("%d",&a[i]);
			for (int i=1;i<=n;i++)
				b[i]=i;
			head=1;top=0;
			for (int i=1;i<=n;i++)
			{
				if (top>0 && s[top]==a[i])
				{
					top--;
				}
				else
				{
					while (head<=n && a[i]!=b[head])
					{
						s[++top]=b[head++];
					}
					if (head<=n && b[head]==a[i]) head++;
					else break;
				}
			}
			if (top==0) printf("Yes\n");
			else printf("No\n");
			scanf("%d",&a[1]);
			if (a[1]==0) n=0;
		}
		scanf("%d",&n);
		if (n!=0) printf("\n");
		if (n==0) break;
	}
	return 0;
}
