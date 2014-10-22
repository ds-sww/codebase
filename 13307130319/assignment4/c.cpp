#include <cstdio>

const int Maxn=1000001;

int n, k, a[Maxn], min_q[Maxn], max_q[Maxn], min_ans[Maxn], max_ans[Maxn];

void print(int *ans)
{
	for (int i=k; i<n; ++i) printf("%d ", ans[i]);
	printf("%d\n", ans[n]);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; ++i) scanf("%d", a+i);
	int min_h=1, min_t=0, max_h=1, max_t=0;
	for (int i=1; i<=n; ++i)
	{
		while (min_h<=min_t && a[i]<a[min_q[min_t]]) --min_t;
		min_q[++min_t]=i;
		while (min_q[min_h]<=i-k) ++min_h;
		min_ans[i]=a[min_q[min_h]];
		
		while (max_h<=max_t && a[i]>a[max_q[max_t]]) --max_t;
		max_q[++max_t]=i;
		while (max_q[max_h]<=i-k) ++max_h;
		max_ans[i]=a[max_q[max_h]];
	}
	print(min_ans);
	print(max_ans);
	return 0;
}

