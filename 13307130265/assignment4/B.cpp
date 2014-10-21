// File Name: B.cpp
// Author: YangYue
// Created Time: Mon Oct 20 18:43:53 2014
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

const int MaxN = 100005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;


int n;
int h[MaxN];
int seq[MaxN];
int len[MaxN];
int maxlen;
vector<int> events[MaxN];
int fa[MaxN];
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b) return;
	fa[a] = b;
	len[b] += len[a];
	maxlen = max(maxlen, len[b]);
}
int main()
{
	//freopen("in","r",stdin);


	while(scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &h[i]);
			seq[i] = h[i];
			fa[i] = i;
			len[i] = 1;
			events[i].clear();
		}
		sort(seq, seq + n);
		int m = unique(seq, seq + n) - seq;
		for (int i = 0; i < n; ++i) {
			int x = lower_bound(seq, seq + m, h[i]) - seq;
			events[x].push_back(i);
		}
		maxlen = 1;
		LL ans = 0;
		for (int i = m-1; i >= 0; --i) {
			for (auto x : events[i]) {
				if (x && h[x-1] >= h[x]) merge(x-1, x);
				if (x+1 < n && h[x+1] >= h[x]) merge(x+1, x);
			}
			ans = max(ans, (LL) seq[i] * maxlen);
		}
		cout << ans << endl;
	}

	return 0;
}

// hehe ~


