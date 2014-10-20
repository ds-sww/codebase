#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int h[111111];

int main(void)
{
	int n = 0;
	while(scanf("%d",&n) != EOF && n)
	{
		for(int i = 0;i < n;i++) scanf("%d",&h[i]);
		h[n] = 0;
		
		ll ans = 0;
		stack<pii> stacky;
		for(int i = 0;i <= n;i++)
		{
			int x = i;
			while(stacky.size() && stacky.top().first > h[i])
			{
				x = stacky.top().second;
				ans = max(ans, (ll)stacky.top().first * (i - x));
				stacky.pop();
			}
			stacky.push(pii(h[i],x));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
