#include<cstdio>
#include<iostream>
using namespace std;
int a[50010][3];
int n,k;
void qsort(int s, int x, int y)
{
	int i,j,k;
	i = x;
	j = y;
	k = a [(i + j) >> 1][s];
	while (i < j)
	{
		while (a[i][s] > k) i++;
		while (a[j][s] < k) j--;
		if (i <= j)
		{
			int t;
			t = a[i][0];
			a[i][0] = a[j][0];
			a[j][0] = t;
			t = a[i][1];
			a[i][1] = a[j][1];
			a[j][1] = t;
			t = a[i][2];
			a[i][2] = a[j][2];
			a[j][2] = t;
			i++;
			j--;
		}
	}
	if (i < y) qsort(s,i,y);
	if (x < j) qsort(s,x,j);
}
int main()
{
	freopen("p3664.in","r",stdin);
	freopen("p3664.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d %d",&a[i][0],&a[i][1]);
		a[i][2] = i;
	}
	qsort(0,1,n);
	qsort(1,1,k);
	printf("%d\n",a[1][2]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
