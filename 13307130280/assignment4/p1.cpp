#include<iostream>
#include<cstdio>
using namespace std;
int a[10001],b[10001],s[10001];
int n,top,head,t,k,head0,top0;
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
			head0=head=1;
			top0=top=0;
			t=1;
			while (((top>0)||(head<=n))&&(t<=n))
			{
				
				while (top>0&&s[top]==a[t])
				{
					top--;
					t++;
				}
				while (head<=n&&a[t]!=b[head])
				{
					top++;
					s[top]=b[head++];
				}
				while (top>0&&s[top]==a[t])
				{
					top--;
					t++;
				}
				if ((head<=n)&&(a[t]=b[head]))
				{
					head++;
					t++;
				}
				if (head0==head && top0==top) break;
				head0=head;
				top0=top;
			}
			if (t>n) printf("Yes");
			else printf("No");
			scanf("%d",&k);
			if (k==0) {n=0;break;}
			else {a[1]=k;printf("\n");}
		}
		scanf("%d",&n);
		if (n!=0) printf("\n\n");
		if (n==0) break;
	}
	return 0;
}
