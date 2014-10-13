/*
*	Copyright (C)   Lyq root#lyq.me
*	File Name     : p3.cpp
*	Creation Time : 2014/09/29 18:36:31
*	Environment   : Ubuntu 14.04-64bit
*	Homepage      : http://www.lyq.me
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int score[301][4];
bool flag[300];
int ans[5];

int main()
{
	//freopen("input3", "r", stdin);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &score[i][0], &score[i][1], &score[i][2]);
		score[i][3] = score[i][0] + score[i][1] + score[i][2];
	}
	score[300][0] = 0;
	score[300][3] = 0;
	memset(flag, false, sizeof(flag));
	for (int num = 0; num < 5; num++)
	{
		int k = 300;
		for (int i = 0; i < n; i++)
		{
			if (flag[i]) continue;
			if (score[i][3] > score[k][3])
			{
				k = i;
			}else if (score[i][3] == score[k][3])
			{
				if (score[i][0] > score[k][0]) k = i;
			}
		}
		flag[k] = true;
		ans[num] = k;
	}

	for (int num = 0; num < 5; num++)
	{
		printf("%d %d\n", ans[num]+1, score[ans[num]][3]);
	}

	return 0;
}
