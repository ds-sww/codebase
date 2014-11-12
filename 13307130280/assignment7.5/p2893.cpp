#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN = 1000010;
int a[MAXN],b[MAXN];
long long ans;
void merge(int x, int y)
{
	if (x == y) return;
	int d = (x + y) >> 1;
	merge(x,d);
	merge(d+1,y);
	int i = x;
	int j = d+1;
	int t = x;
	while (t <= y)
	{
		if ((i <= d) && ((j == y+1) || (a[i] < a[j])))
		{
			b[t] = a[i];
			t++;
			i++;
		}
		else
		{
			ans += (long long)(d - i + 1);
			b[t] = a[j];
			t++;
			j++;
		}
	}
	for (int i = x; i <= y; i++)
	{
		a[i] = b[i];
	}
}
int main()
{
	int m,n;
	int k;
	scanf("%d %d",&m,&n);
	while (m + n > 0)
	{
		k = 0;
		ans = 0;
		for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			int tmp;
			scanf("%d",&tmp);
			if (tmp > 0)
			{
				k++;
				a[k] = tmp;
			}
			else if (n % 2 == 0)
			{
				ans += (m - i);
			}
		}
		merge(1,k);
		if (ans % 2 == 0) printf("YES\n");
		else printf("NO\n");
		scanf("%d %d",&m,&n);
	}
	return 0;
}
