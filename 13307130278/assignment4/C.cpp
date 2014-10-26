#include<iostream>
#include<stdio.h>
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
using namespace std;

int n, m;
int a[1000100];
int sta1[1000100], sta2[1000100];
int min1[1000100], min2[1000100];
int max1[1000100], max2[1000100];
int ans[1000100][2];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int top1 = 0, top2 = 0;
	int cnt = 0;
	int MIN = 2000000000;
	for (int i = 0; i <= 0; i++)
	{
		min1[i] = MIN; min2[i] = MIN;
		max1[i] = -MIN; max2[i] = -MIN;
	}
	for (int i = 1; i < m; i++)
	{
		++top1; sta1[top1] = a[i];
		min1[top1] = Min(a[i], min1[top1 - 1]);
		max1[top1] = Max(a[i], max1[top1 - 1]);
	}
	int tot = 0;
	for (int i = m; i <= n; i++)
	{ 
		++top1; sta1[top1] = a[i];
		min1[top1] = Min(a[i], min1[top1 - 1]);
		max1[top1] = Max(a[i], max1[top1 - 1]);
		if (!top2)
		{
			while (top1)
			{
				++top2;
				sta2[top2] = sta1[top1];
				min2[top2] = Min(sta2[top2], min2[top2 - 1]);
				max2[top2] = Max(sta2[top2], max2[top2 - 1]);
				--top1;
			}
		}
		++tot;
		ans[tot][0] = Min(min1[top1], min2[top2]);
		ans[tot][1] = Max(max1[top1], max2[top2]);
		--top2;
	}
	for (int i = 1; i <= tot; i++) printf("%d ", ans[i][0]);
	cout << endl;
	for (int i = 1; i <= tot; i++) printf("%d ", ans[i][1]);
	cout << endl;
	return 0;
}