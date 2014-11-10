// File Name: C.cpp
// Author: YangYue
// Created Time: Mon Oct 20 18:59:06 2014
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

int que[MaxN];

void solve(int *a, int n, int K, int *ans) {
	int front = 1, tail = 0;
	for (int i = 1; i <= n; ++i) {
		while (front <= tail && a[i] >= a[que[tail]]) --tail;
		que[++tail] = i;
		if (i < K) continue;
		while (front <= tail && i - que[front] + 1 > K) ++front;
		ans[i] = a[que[front]];
	}
}

int a[MaxN];
int ans1[MaxN], ans2[MaxN];

int main()
{
	//freopen("in","r",stdin);

	int n, K; scanf("%d %d", &n, &K);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);

	solve(a, n, K, ans1);
	for (int i = 1; i <= n; ++i) a[i] *= -1;
	solve(a, n, K, ans2);

	for (int i = K; i <= n; ++i) printf("%d%c", -ans2[i], i == n ? '\n' : ' ');
	for (int i = K; i <= n; ++i) printf("%d%c", ans1[i], i == n ? '\n' : ' ');

	return 0;
}

// hehe ~


