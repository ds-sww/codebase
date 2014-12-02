#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int fa[10004];
bool appeared[10004];

int getfa(int x)
{
	if(fa[x] == x) return x;
	fa[x] = getfa(fa[x]);
	return fa[x];
}

bool work(int T)
{
	for(int i = 0; i < 10000; i++)
	{
		fa[i] = i;
		appeared[i] = 0;
	}

	int x, y;
	scanf("%d%d", &x, &y);

	if(x == -1 && y == -1) return false;

	printf("Case %d ", T);

	bool flag = true;
	int cntE = 0;
	while(x != 0 && y != 0)
	{
		++cntE;
		appeared[x] = appeared[y] = true;
		int fx = getfa(x), fy = getfa(y);
		if(fx == fy)
		{
			flag = false;
		}
		fa[fx] = fy;

		scanf("%d%d", &x, &y);
	}

	int cntV = 0;
	for(int i = 1; i <= 10000; i++) if(appeared[i]) cntV++;

	if((flag && cntE == cntV - 1) || (cntV == 0 && cntE == 0))
	{
		printf("is a tree.\n");
	}
	else
	{
		printf("is not a tree.\n");
	}
	return true;
}

int main()
{
	int T = 0;
	while(work(++T))
	{
		;
	}
	return 0;
}
