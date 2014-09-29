// File Name: A.cpp
// Author: YangYue
// Created Time: Mon Sep 29 18:38:32 2014
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

const int ud[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


int n, m;
char s[33][33];
bool vis[5555][2];
int dis[5555][2];
PII que[MaxN];

int num(int x, int y) {
	return x * m + y;
}
int bfs(int S, int T) {
	int front, tail;
	que[front = tail = 0] = MP(S, 0);
	vis[S][0] = 1;
	for (int i = 0; i < n * m; ++i) dis[i][0] = dis[i][1] = INF;
	dis[S][0] = 0;
	for (; front <= tail; ++front) {
		int u = que[front].first;
		int p = que[front].second;
		int x = u / m;
		int y = u % m;
		for (int uk = 0; uk < 4; ++uk) {
			int nx = x + ud[uk][0];
			int ny = y + ud[uk][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '#') continue;
			if (p == 0 && s[nx][ny] == 'D') continue;
			int np = p;
			if (s[nx][ny] == 'K') {
				np = 1;
			}
			int v = num(nx, ny);
			if (!vis[v][np]) {
				vis[v][np] = 1;
				que[++tail] = MP(v, np);
				dis[v][np] = dis[u][p] + 1;
			}
		}
	}
	return min(dis[T][0], dis[T][1]);
}

int main()
{
	//freopen("in","r",stdin);


	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%s", s[i]);

	int T = 0;
	int S = 0;
	int K = 0;
	int D = 0;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'S') S = num(i, j);
			if (s[i][j] == 'T') T = num(i, j);
			if (s[i][j] == 'K') K = num(i, j);
			if (s[i][j] == 'D') D = num(i, j);
		}
	}
	int ans = bfs(S, T);
	if (ans > 100000) puts("-1");
	else printf("%d\n", ans);
	
	return 0;
}

// hehe ~


