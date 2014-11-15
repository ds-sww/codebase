#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int a[2][26];
char c[2][110];
void qsort(int s,int x,int y)
{
	int i,j,k;
	i = x;
	j = y;
	k = a[s][(i + j) >> 1];
	while (i < j)
	{
		while (a[s][i] < k) i++;
		while (a[s][j] > k) j--;
		if (i <= j)
		{
			int t;
			t = a[s][i];
			a[s][i] = a[s][j];
			a[s][j] = t;
			i++;
			j--;
		}
	}
	if (i < y) qsort(s,i,y);
	if (x < j) qsort(s,x,j);
}
int main()
{
	scanf("%s",c[0]);
	scanf("%s",c[1]);
	int l = strlen(c[0]);
	for (int i = 0; i < l; i++)
	{
		a[0][c[0][i]-'A']++;
		a[1][c[1][i]-'A']++;
	}
	qsort(0,0,25);
	qsort(1,0,25);
	bool ok = true;
	for (int i = 0; i < 26; i++)
	{
		if (a[0][i] != a[1][i]) ok = false;
	}
	if (ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}
