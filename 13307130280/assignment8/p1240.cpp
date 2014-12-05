#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN = 30;
char s1[MAXN],s2[MAXN];
int c[MAXN],r[MAXN],t[MAXN];
long long ans;
void work(int x1, int y1, int x2, int y2)
{
	if (x1 >= y1 || x2 >= y2) return;
	int d = t[x1];
	int q1 = x1;
	int q2 = x2;
	q1++;
	while (q1 <= y1)
	{
		int dd = t[q1];
		work(q1,q1 + dd - q2,q2,dd);
		c[s1[x1] - 'a' + 1]++;
		q1 = q1 + dd - q2 + 1;
		q2 = dd + 1;
	}
	return;
}
int main()
{
	int m;
	scanf("%d",&m);
	while (m > 0)
	{
		memset(c,0,sizeof(c));
		scanf("%s %s",s1,s2);
		int l = strlen(s1);
		for (int i = 0; i < l; i++)
		{
			r[s2[i] - 'a'] = i;
		}
		for (int i = 0; i < l; i++)
		{
			t[i] = r[s1[i] - 'a'];
		}
		work(0,l-1,0,l-1);
		long long ans = 1;
		for (int i = 1; i <= l; i++)
		{
			long long tmp = 1;
			for (int j = 0; j < c[i]; j++)
			{
				tmp *= (m - j);
				tmp /= (j + 1);
			}
			ans *= tmp;
		}
		printf("%lld\n",ans);
		scanf("%d",&m);
	}
	return 0;
}
