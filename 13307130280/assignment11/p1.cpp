#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
const int p = 9759391;
const int pp = 9476831;
const int q = 9978713;
char a[150][150];
int hash[10000007];
int rrhash[150][150][150];
int hashnum[150][150];
int lhash[30];
int n,m,ans;
int main()
{
	srand(time(NULL));
	for (int i = 0; i < 26; i++)
	{
		lhash[i] = rand() % 3137;
		//lhash[i] = i + 1;
	}
	
	int t;
	scanf("%d",&t);
	for (int o = 1; o <= t; o++)
	{
		scanf("%d %d\n",&n,&m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%c",&a[i][j]);
			}
			scanf("\n");
		}

		//rrhash
		for (int j = 1; j <= m; j++)
		{
			for (int i1 = 1; i1 <= n; i1++)
			{
				int tmp = (long long)(lhash[a[i1][j] - 'A']) * p % q;
				rrhash[j][i1][i1] = tmp;
				for (int i2 = i1 + 1; i2 <= n; i2++)
				{
					tmp = (long long)(rrhash[j][i1][i2 - 1] + lhash[a[i2][j] - 'A']) * p % q;
					rrhash[j][i1][i2] = tmp;
				}
			}

		}
		//hash
		ans = 0;

		for (int i1 = 1; i1 <= n; i1++)
		for (int i2 = i1; i2 <= n; i2++)
		{
			int tmp = 0;
			for (int j1 = 1; j1 <= m; j1++)
			{
				tmp = ((long long)rrhash[j1][i1][i2] * pp) % q;

				if (hash[tmp] != o)
				{
					hash[tmp] = o;
					ans++;
				}
				for (int j2 = j1 + 1; j2 <= m; j2++)
				{
					tmp = (long long)(tmp + rrhash[j2][i1][i2]) * pp % q;

					if (hash[tmp] != o)
					{
						hash[tmp] = o;
						ans++;
					}
				}
				
			}
		}
		printf("Case #%d: %d\n",o,ans);
	}
	
	return 0;
}

