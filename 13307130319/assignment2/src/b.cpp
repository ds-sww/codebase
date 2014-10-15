#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue< int, vector<int>, greater<int> > h;

int main()
{
	freopen("b.in", "r", stdin);
	int n, x, y;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		scanf("%d", &x);
		h.push(x);
	}
	int ans=0;
	for (int i=1; i<n; ++i)
	{
		x=h.top();
		h.pop();
		y=h.top();
		h.pop();
		ans+=x+y;
		h.push(x+y);
	}
	printf("%d\n", ans);
	return 0;
}

