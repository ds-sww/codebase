#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
typedef long long LL;
LL n, m;
bool cc(LL k)
{
	LL b, c, res = 0;
	for (LL j = 1; j <= n; j++)
	{
		b = 100000 + j;
		c = j * j - 100000 * j - k;
		LL ans = (sqrt(1.0 * (b * b - 4 * c)) - b) / 2.0;
		if (ans * ans + b * ans + c == 0)
			ans--;
		ans = ans > n ? n : ans;
		ans = ans < 0 ? 0 : ans;
		res += ans;
		if (res >= m)
			return false;
	}
	return res < m;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%lld%lld", &n, &m);
		//cin>>n>>m;
		LL left, right, mid;
		left = -100000*n, right = n*n*3+100000*n;
		
		while (right-left>1){
			mid = (left + right) >> 1;
			if (cc(mid))
				left = mid;
			else
				right = mid;
			
		}
		printf("%lld\n", left);
	}
	return 0;
}