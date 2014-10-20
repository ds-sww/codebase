/*
*	Copyright (C)   Lyq root#lyq.me
*	File Name     : p2-2.cpp
*	Creation Time : 2014/10/20 19:03:20
*	Environment   : Ubuntu 14.04-64bit
*	Homepage      : http://www.lyq.me
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int a[100005], Left[100005], Right[100005];
int main(void)
{
	//freopen("p2-2-in", "r", stdin);

	int N, pos;
	long long temp, ans;
	cin >> N;
	while (N != 0)
	{
		for (int i = 0; i < N; i++) scanf("%d", &a[i]);
		
		ans = 0;
		Left[0] = 0;
		Right[N-1] = N-1;
		for (int i = 1; i < N; i++)
		{
			pos = i;
			while (pos > 0 && a[i] <= a[pos-1]) pos = Left[pos-1];
			Left[i] = pos;
		}
		for (int i = N-2; i >= 0; i--)
		{
			pos = i;
			while (pos < N-1 && a[i] <= a[pos+1]) pos = Right[pos+1];
			Right[i] = pos;
		}
		for (int i = 0; i < N; i++)
		{
			temp = (long long)a[i] * (Right[i]-Left[i]+1);
			ans = max(temp, ans);
		}
		cout << ans << endl;
		cin >> N;
	}
	return 0;
}
