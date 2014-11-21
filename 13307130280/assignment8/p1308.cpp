#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct edge
{
	int y,next;
};
int const MAXN = 200010;
edge b[MAXN];
int next[MAXN];
bool v[MAXN];
int t[MAXN];
int d[MAXN];
int dnum;
bool ok;
void mark(int x, int & num)
{
	if (!v[x])
	{
		num++;
		v[x] = true;
		t[x] = num;
	}
	return;
}
void dfs(int x)
{
	if (!ok) return;
	dnum++;
	v[x] = true;
	int k = next[x];
	while (k > 0)
	{
		if (!v[b[k].y])
		{
			dfs(b[k].y);
		}
		else
		{
			ok = false;
			return;
		}
		k = b[k].next;
	}
	return;
}
int main()
{
	int x,y;
	int o = 0;
	while (scanf("%d %d",&x,&y))
	{
		if (x < 0) break;
		o++;
		if (x + y == 0)
		{
			printf("Case %d is a tree.\n",o);
			continue;
		}
		memset(v,0,sizeof(v));
		memset(d,0,sizeof(d));
		memset(b,0,sizeof(b));
		memset(next,0,sizeof(next));
		int num = 0;
		int bnum = 0;
		int k = 0;
		ok = true;
		while (x + y > 0)
		{
			mark(x,num);
			mark(y,num);
			bnum ++;
			b[bnum].y = t[y];
			b[bnum].next = next[t[x]];
			next[t[x]] = bnum;
			d[t[y]]++;
			scanf("%d %d",&x,&y);
		}
		if (bnum != num - 1)
		{
			printf("Case %d is not a tree.\n",o);
			continue;
		}
		bnum = 0;
		for (int i = 1; i <= num; i++)
		if (d[i] == 0)
		{
			if (k == 0)
			{
				k = i;
			}
			else
			{
				printf("Case %d is not a tree.\n",o);
				ok = false;
				break;
			}
		}
		if (!ok) continue;
		memset(v,0,sizeof(v));
		dnum = 0;
		dfs(k);
		if (dnum == num) printf("Case %d is a tree.\n",o);
		else printf("Case %d is not a tree.\n",o);
	}
	return 0;
}
