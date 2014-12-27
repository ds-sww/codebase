#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for (int o = 0; o < t; o++)
	{
		int n;
		long long m,sum;
		scanf("%d %lld",&n,&m);
		long long l,r;
		l = - 99999999999LL;
		r = 199999999999LL;
		while (l <= r)
		{
			sum = 0;
			long long k = (l + r) >> 1;
			for (int j = 1; j <= n; j++)
			{
				
				if (k > 7500000000ll && j == 31225)
				{
					int ok;
					ok = false;
				}
				long long t1,t2,t3;
				t1 = 100000 + j;
				t2 = (long long)j * j;
				t2 = t2 - (long long)j * 100000 - k;
				t2 = t2 * 4;
				t3 = t1 * t1 - t2;
				if (t3 < 0) continue;
				double x1;
				x1 = t3;
				x1 = sqrt(x1);
				x1 = (x1 - t1) / 2;
				if (x1 > n) x1 = n;
				if (x1 < 0) x1 = 0;
				sum += x1;
			}
			if (sum < m) l = k + 1; 
			else r = k - 1;
		}
		printf("%lld\n",l);
	}
	return 0;
}

