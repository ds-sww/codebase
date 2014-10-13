#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn=301;

struct Student
{
	int sum, id, chinese;
	bool operator<(const Student &temp) const
	{
		if (sum!=temp.sum) return sum>temp.sum;
		if (chinese!=temp.chinese) return chinese>temp.chinese;
		return id<temp.id;
	}
} a[Maxn];

int main()
{
	freopen("c.in", "r", stdin);
	int n, x, y, z;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[i].id=i+1;
		a[i].sum=x+y+z;
		a[i].chinese=x;
	}
	sort(a, a+n);
	for (int i=0; i<5; ++i) printf("%d %d\n", a[i].id, a[i].sum);
	return 0;
}

