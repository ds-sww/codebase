/*
*	Copyright (C)   Lyq root#lyq.me
*	File Name     : p2-3.cpp
*	Creation Time : 2014/10/20 19:41:43
*	Environment   : Ubuntu 14.04-64bit
*	Homepage      : http://www.lyq.me
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;

int N, K;
int a[1000005];
deque<int>q;
int _min[1000005], _max[1000005];

int main(void)
{
	freopen("p2-3-in", "r", stdin);

	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	
	for (int i = 0; i < K-1; i++)	
	{
		while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
	}
	for (int i = K-1; i < N; i++)
	{
		while (!q.empty() && q.front() <= i-K) q.pop_front();
		while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		_min[i] = a[q.front()];
	}
	
	while (!q.empty()) q.pop_back();
	for (int i = 0; i < K-1; i++)	
	{
		while (!q.empty() && a[q.back()] <= a[i]) q.pop_back();
		q.push_back(i);
	}
	for (int i = K-1; i < N; i++)
	{
		while (!q.empty() && q.front() <= i-K) q.pop_front();
		while (!q.empty() && a[q.back()] <= a[i]) q.pop_back();
		q.push_back(i);
		_max[i] = a[q.front()];
	}
	
	for (int i = K-1; i < N; i++) printf("%d ", _min[i]);
	printf("\n");
	for (int i = K-1; i < N; i++) printf("%d ", _max[i]);

	return 0;
}
