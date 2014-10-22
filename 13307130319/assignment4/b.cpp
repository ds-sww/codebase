#include <cstdio>
#include <algorithm>
#include <iostream>
typedef long long LL;

const int Maxn=100001;

int h[Maxn], left[Maxn], right[Maxn];

int main()
{
	int n;
	scanf("%d", &n);
	while (n)
	{
		for (int i=1; i<=n; ++i) scanf("%d", h+i);
		for (int i=1; i<=n; ++i)
		{
			int j=i-1;
			while (j && h[j]>=h[i]) j=left[j]-1;
			left[i]=j+1;
		}
		for (int i=n; i; --i)
		{
			int j=i+1;
			while (j<=n && h[j]>=h[i]) j=right[j]+1;
			right[i]=j-1;
		}
		LL ans=0;
		for (int i=1; i<=n; ++i)
			ans=std::max(ans, (LL)(right[i]-left[i]+1)*h[i]);
		std::cout<<ans<<std::endl;
		scanf("%d", &n);
	}
	return 0;
}

