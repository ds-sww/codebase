/*
*	Copyright (C)   Lyq root#lyq.me
*	File Name     : p2.cpp
*	Creation Time : 2014/09/29 18:50:02
*	Environment   : Ubuntu 14.04-64bit
*	Homepage      : http://www.lyq.me
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n;

priority_queue<int>q;

int main()
{
	//freopen("input2", "r", stdin);
	int a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &a);
		q.push(-a);
	}
	int ans = 0;
	for (int i = 0; i < n-1; i++)
	{
		int temp = q.top();
		q.pop();
		temp = temp + q.top();
		q.pop();
		ans += temp;
		q.push(temp);
	}
	cout << -ans;
	return 0;
}
