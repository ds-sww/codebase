#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN = 20010;
int a[MAXN];
void qsort(int x,int y)
{
	int i,j,k;
	i = x;
	j = y;
	k = a[(x + y) >> 1];
	while (i < j)
	{
		while (a[i] > k) i++;
		while (a[j] < k) j--;
		if (i <= j)
		{
			int t;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}
	if (x < j) qsort(x,j);
	if (i < y) qsort(i,y);
}
int main()
{
	int t;
	scanf("%d",&t);
	for (int o = 0; o < t; o++)
	{
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++)		
		{
			scanf("%d",&a[i]);
		}
		qsort(1,n);
		int i = 3;
		int ans = 0;
		while (i <= n)
		{
			ans += a[i];
			i += 3;
		}
		printf("%d\n",ans);
	}
	return 0;
}
