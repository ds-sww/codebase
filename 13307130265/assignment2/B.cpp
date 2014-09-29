// File Name: B.cpp
// Author: YangYue
// Created Time: Mon Sep 29 18:36:37 2014
//headers 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<LL, LL>PLL;
typedef pair<LL,int>PLI;

#define lch(n) ((n<<1))
#define rch(n) ((n<<1)+1)
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define MP make_pair
#define PB push_back

const int MaxN = 1000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n;
priority_queue<int> heap;

int main()
{
	//freopen("in","r",stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		heap.push(-x);
	}

	int ans = 0;
	for (int i = 1; i < n; ++i) {
		int a = heap.top();
		heap.pop();
		int b = heap.top();
		heap.pop();
		ans -= a + b;
		heap.push(a+b);
	}
	
	printf("%d\n", ans);
	
	return 0;
}

// hehe ~


