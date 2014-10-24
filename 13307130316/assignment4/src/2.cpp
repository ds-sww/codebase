#include <iostream>
#include <cstdlib>
#include <cstdio>

#define MAX 100010

using namespace std;

int main()
{
	int n;
	long long a[MAX];
	int s[MAX],slen;
	
	while(1)
	{
		cin >> n;
		if(n == 0)
			break;

		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		
		long long ans = -1;
		slen = 0;
		for(int i=0;i<n;i++)
		{
			if(slen == 0 || a[s[slen - 1]] < a[i])
			{
				s[slen] = i;
				slen++;
			}
			else
			{
				int j = s[slen - 1];
				slen--;
				int w = (slen == 0) ? i : i - s[slen - 1] - 1;
				ans = max(ans , a[j] * w);
				i--;
			}
		}
		while(slen > 0)
		{
			int j = s[slen - 1];
			slen--;
			int w = (slen == 0) ? n : n - s[slen - 1] - 1;
			ans = max(ans , a[j] * w);
		}
		cout << ans << endl;
	}

	return 0;
}
