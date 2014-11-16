#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
struct node
{
	int l,r;
};
const int MAXN = 30;
char s[2][MAXN];
int r[MAXN];
int t[MAXN];
node c[MAXN];
void work(int x1, int y1, int x2, int y2)
{
	if ((x1 >= y1) || (x2 >= y2)) return ;
	int d = t[x1];
	int a,b;
	a = d;
	b = x1;
	for (int i = x1; i <= y1; i++)
	{
		if (a == d && t[i] > d)
		{
			a = t[i];
			b = i;
		}
	}
	if (b != x1 + 1)
	{
		c[s[0][x1] - 'A' + 1].l = s[0][x1 + 1] - 'A' + 1;
	}
	if (a != d)
	{
		c[s[0][x1] - 'A' + 1].r = s[0][b] - 'A' + 1;
	}
	if (a == d) b = y1 + 1;
	work(x1 + 1,b - 1,x2,d - 1);
	work(b,y1,d + 1,y2);
}

void post(int x)
{
	if (x == 0) return;
	post(c[x].l);
	post(c[x].r);
	char ch = x + 'A' - 1;
	printf("%c",ch);
	return;
}

int main()
{
	while (scanf("%s %s",s[0],s[1]) != -1)
	{
		memset(r,0,sizeof(r));
		memset(t,0,sizeof(t));
		int l = strlen(s[0]);
		for (int i = 0; i < l; i++)
		{
			r[s[1][i] - 'A'] = i;
			
		}
		for (int i = 0; i < l; i++)
		{
			t[i] = r[s[0][i] - 'A'];
		}
		memset(c,0,sizeof(c));
		
		work(0,l-1,0,l-1);
		
		post(s[0][0] - 'A' + 1);
		printf("\n");
	}
	return 0;
}
