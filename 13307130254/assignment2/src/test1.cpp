/*
*	Copyright (C)   Lyq root#lyq.me
*	File Name     : p1.cpp
*	Creation Time : 2014/09/29 19:23:37
*	Environment   : Ubuntu 14.04-64bit
*	Homepage      : http://www.lyq.me
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int st_i, st_j, n, m;
int ans;
bool flag[2][30][30];
char map[30][30];
const int route[4][2] = {{0,-1}, {0, 1}, {-1,0}, {1,0}};

void search(int idx, int idy, int step, bool door)
{
	if (map[idx][idy] == 'T')
	{
		if (ans == -1) ans = step;
			else ans = min(ans, step);
	}
	int x, y;
	for (int k = 0; k < 4; k++)
	{
		x = idx + route[k][0];
		y = idy + route[k][1];
		if (x < 0 || x >= n || y < 0 || y >= m) continue;
		if (flag[door][x][y]) continue;
		if (map[x][y] == '#') continue;
		if (map[x][y] == 'D' && !door) continue;

		if (map[x][y] == '*' || map[x][y] == 'T')
		{
			flag[door][x][y] = 1;
			search(x, y, step+1, door);
			flag[door][x][y] = 0;
		}else if (map[x][y] == 'K')
		{
			flag[door][x][y] = 1;
			map[x][y] = '*';
			search(x, y, step+1, true);
			map[x][y] = 'K';
			flag[door][x][y] = 0;
		}else if (map[x][y] == 'D' && door)
		{
			flag[door][x][y] = 1;
			map[x][y] = '*';
			search(x, y, step+1, door);
			map[x][y] = 'D';
			flag[door][x][y] = 0;
		}
	}
}
int main()
{
	//freopen("input1", "r", stdin);

	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'S')
			{
				st_i = i; st_j = j;
			}
		}
		scanf("\n");
	}
	
	memset(flag, 0, sizeof(flag));
	flag[0][st_i][st_j] = 1;
	ans = -1;
	search(st_i, st_j, 0, false);
	cout << ans;

	return 0;
}
