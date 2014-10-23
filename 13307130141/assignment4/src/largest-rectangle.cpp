#include <iostream>
#include <cstdio>
using namespace std;

const int N = 121111;

int h[N];
pair <int, pair <int, int> > stack[N];

int main()
{
	//ios::sync_with_stdio(false);
	int n;
	while(scanf("%d", &n))
	{
		if(n == 0)
			break;
		for(int i = 0; i < n; i++)
			scanf("%d", h + i);

		int top = 0;
		long long ans = 0;
		for(int i = 0; i < n; i++)
		{
			int left = i;
			while(top != 0 && stack[top - 1].first >= h[i])
			{
				int topLen = i - stack[top - 1].second.first;
				ans = max(ans, (long long)stack[top - 1].first * topLen);
				left = stack[top - 1].second.first;
				top --;
			}
			stack[top++] = make_pair(h[i], make_pair(left, i));
			//cout << ans << '\n';
		}

		for(int i = 0; i < top; i++)
			ans = max(ans, (long long)stack[i].first
				 * (stack[top - 1].second.second - stack[i].second.first + 1));

		cout << ans << '\n';
	}
	return 0;
}