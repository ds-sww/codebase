#include<iostream>
#include<stdio.h>
using namespace std;

int h[200000], len[200000];
int sta[200000];
int n, top, tot;
int main()
{
	cin >> n;
	while (n)
	{
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &h[i]);
		top = 0; tot = 0;
		long long p = 0;
		long long min = 2000000000;
		for (int i = 1; i <= n; i++)
		{
			p = 0;
			min = 2000000000;
			while ((top) && (h[i] < sta[top]))
			{
				p += len[top];
				if (sta[top]<min) min = sta[top];
				--top;
				if (p*min>ans) ans = p*min;
			}
			++top; len[top] = p+1; sta[top] = h[i];
		}
		while ((top))
		{
			p += len[top];
			if (sta[top]<min) min = sta[top];
			--top;
			if (p*min>ans) ans = p*min;
		}

		cout << ans << endl;
		cin >> n;
	}
	return 0;
}