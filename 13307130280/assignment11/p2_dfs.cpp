#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
char s[1010];
char a[110][1010],b[110][1010];
char p[1010][10100];
int hash[1000010];
int next[1010];
int num,ans;

int hashmake(char s[])
{
	int l = strlen(s);
	int tmp = 0;
	for (int o = 0; o < l; o++)
	{
		tmp = tmp * 10 + 319 * s[o] * (o + 1);
		tmp %= 1000007;
	}
	return tmp;
}
bool dfs(char s[])
{
	for (int o = 1; o <= num; o++)
	{
		int l = strlen(s);
		int l2 = strlen(b[o]);
		int l1 = strlen(a[o]);
		for (int i = 0; i + l1 <= l; i++)
		{
			if (strncmp(s + i, a[o] , l1) == 0)
			{
				ans++;
				for (int j = 0; j < i; j++)
					p[ans][j] = s[j];
				for (int j = 0; j < l2; j++)
					p[ans][i + j] = b[o][j];
				for (int j = i + l1; j < l; j++)
					p[ans][j - l1 + l2] = s[j];
				p[ans][l - l1 + l2] = '\0';
				int tmp = hashmake(p[ans]);
				int t = hash[tmp];
				bool ok = true;
				while (t > 0)
				{
					if (strcmp(p[t],p[ans]) == 0)
					{
						ok = false;
						break;
					}
					
					t = next[t];
				}
				if (ok)
				{
					next[ans] = hash[tmp];
					hash[tmp] = ans;
					if (ans > 1000) return false;
					if (!dfs(p[ans])) return false;
				}
				else ans--;
			}
		}
	}
	return true;
}
int main()
{
	scanf("\"%[^\"]\"\n",p[1]);
	
	int tmp = hashmake(p[1]);
	hash[tmp] = 1;
	ans = 1;
	
	while (scanf("%s",s) != -1)
	{
		num++;
		sscanf(s,"\"%[^\"]\"->\"%[^\"]\"",a[num],b[num]);
	
	}
	dfs(p[1]);
	if (ans > 1000) printf("Too many.\n");
	else printf("%d\n",ans);
	
	return 0;
}
