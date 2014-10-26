#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=100010;
int h[MAXN],p[MAXN],s[MAXN];
long long ans,tmp;
int n,head,tail,k;
//take care of overflow!!!
int main()
{
	scanf("%d",&n);
	while (n!=0)
	{
		for (int i=1;i<=n;i++)
			scanf("%d",&h[i]);
		h[++n]=0;
		ans=0;
		p[1]=h[1];
		s[1]=1;
		head=1;
		tail=1;
		for (int i=2;i<=n;i++)
		{
			k=i;
			while ((tail>=head)&&(h[i]<p[tail]))
			{
				tmp=(long long)(i-s[tail])*(long long)p[tail];
				if (tmp>ans) ans=tmp;
				k=s[tail];
				tail--;
			}
			if (h[i]>p[tail])
			{
				tail++;
				s[tail]=k;
				p[tail]=h[i];
			}
		}
		printf("%lld\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
