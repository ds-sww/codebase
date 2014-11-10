#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN = 20010;
char s[2][MAXN][21];
int r[5];
int ans[MAXN];
int number(char c)
{
	switch (c)
	{
		case 'A': return 1;
		case 'C': return 2;
		case 'G': return 3;
		case 'T': return 4;
	}
}
int main()
{
	int n,m,k,l;
	scanf("%d %d",&n,&m);
	while (n + m > 0)
	{
		memset(ans,0,sizeof(ans));
		for (int i = 0; i < n; i++)
		{
			scanf("%s",s[0][i + 1]);
		}
		for (int i = m-1; i >= 0; i--)
		{
			for (int j = 0; j < 5; j++)
				r[j] = 0;
			k = (m - i + 1) % 2;
			for (int j = 1; j <= n; j++)
			{
				r[ number(s[k][j][i]) ] ++;
			}
			l = 1 - k;
			for (int j = 1; j <= 4; j++)
				r[j] += r[j - 1];
			for (int j = n; j >= 1; j--)
			{
				int x = number(s[k][j][i]);
				for (int u = 0; u < m; u++)
				s[l][ r[x] ][u] = s[k][j][u];
				r[number(s[k][j][i])]--;
			}
		}
		
		int num = 0;
		for (int i = 1; i <= n; i++)
		{
			bool ok = true;
			for (int j = 0; j < m; j++)
			{
				if (s[l][i][j] != s[l][i-1][j])
				{
					ok = false;
					break;
				}
			}
			if (ok) num++;
			else
			{
				ans[num]++;
				num = 0;
			}
		}
		ans[0]--;
		ans[num]++;
		for (int i = 0; i < n; i++)
		{
			printf("%d\n",ans[i]);
		}
		scanf("%d %d",&n,&m);
	}
	return 0;
}
