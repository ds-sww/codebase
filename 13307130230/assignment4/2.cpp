#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<algorithm>
using namespace std;
const int size=100005;
int n,top,a[size],stk[size];
long long ans,f[size],g[size];
int main()
{
	freopen("1.in","r",stdin);
	while (scanf("%d",&n),n)
	{
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		top=0;
		stk[top++]=0;
		for (int i=1;i<=n;i++)
		{
			while (top&&a[stk[top-1]]>=a[i]) top--;
			f[i]=i-stk[top-1];
			stk[top++]=i;
		}
		
		reverse(a+1,a+n+1);
		top=0;
		stk[top++]=0;
		for (int i=1;i<=n;i++)
		{
			while (top&&a[stk[top-1]]>=a[i]) top--;
			g[i]=i-stk[top-1];
			stk[top++]=i;
		}
		
		long long ans=0;
		for (int i=1;i<=n;i++) ans=max(ans,1LL*a[i]*(f[n-i+1]+g[i]-1));
		printf("%lld\n",ans);
	}

	return 0;
}
