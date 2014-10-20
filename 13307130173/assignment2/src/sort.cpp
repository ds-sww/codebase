#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 1111111
using namespace std;
struct rec
{
	int a, b, c, d, e;
}data[maxn];
int n;
bool cmp(rec u,rec v)
{
	return u.d > v.d || (u.d == v.d && u.a > v.a) || (u.d == v.d && u.a == v.a && u.e < v.e);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &data[i].a, &data[i].b, &data[i].c);
		data[i].d = data[i].a + data[i].b + data[i].c;
		data[i].e = i + 1;
	}
	sort(data, data + n, cmp);
	for (int i = 0; i < 5; i++) printf("%d %d\n", data[i].e, data[i].d);	
    return 0;
}