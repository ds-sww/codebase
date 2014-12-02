#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a[50010];
int n,t,l,ans;
long long now;
void qsort(int x,int y)
{
	int i,j,k;
	i = x;
	j = y;
	k = abs(a[(i + j) >> 1]);
	while (i < j)
	{
		while (abs(a[i]) < k) i++;
		while (abs(a[j]) > k) j--;
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
	if (i < y) qsort(i,y);
	if (x < j) qsort(x,j);
}
int main()
{
	freopen("p3618.in","r",stdin);
	freopen("p3618.out","w",stdout);
	scanf("%d %d",&t,&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	qsort(1,n);
	int i = 0;
	l = 0;
	ans = 0;
	now = 0;
	while (i < n)
	{
		i++;
		now += (long long)abs(l - a[i]);
		if (now > t) break;
		l = a[i];
		ans++;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
