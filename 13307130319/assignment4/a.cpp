#include <cstdio>

const int Maxn=1001;

int a[Maxn], stack[Maxn];

bool check(int n)
{
	int p=0, top=0;
	for (int i=0; i<n; ++i)
	{
		while (top==0 || stack[top]!=a[i])
		{
			if (p==n) return false;
			stack[++top]=++p;
		}
		--top;
	}
	return true;
}

int main()
{
	int n;
	while (true)
	{
		scanf("%d", &n);
		if (n==0) break;
		while (true)
		{
			scanf("%d", a);
			if (a[0]==0) break;
			for (int i=1; i<n; ++i) scanf("%d", a+i);
			if (check(n)) puts("Yes"); else puts("No");
		}
		printf("\n");
	}
	return 0;
}

