/*
*	Copyright (C)   Lyq root#lyq.me
*	File Name     : p2-2.cpp
*	Creation Time : 2014/10/20 18:45:43
*	Environment   : Ubuntu 14.04-64bit
*	Homepage      : http://www.lyq.me
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int a[10000], stack[10000];

int main(void)
{
	//freopen("p2-2-in", "r", stdin);
	//freopen("out", "w", stdout);

	int N, temp;

	cin >> N;
	while (N != 0)
	{
		cin >> temp;
		if (temp == 0)
		{
			cout << endl;
			cin >> N;
			continue;
		}

		a[0] = temp;
		for (int i = 1; i < N; i++) cin >> a[i];
		
		int i, j, top = -1;
		stack[++top] = 1;
		j = 2;
		for (i = 0; i < N; i++)
		{
			while (a[i] != stack[top])
			{
				if (j == N+1) break;
				stack[++top] = j;
				j++;
			}
			if (a[i] == stack[top])
			{
				top--;
			}else break;
		}
		if (i == N)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

