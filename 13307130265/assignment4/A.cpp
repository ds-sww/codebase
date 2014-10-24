// File Name: A.cpp
// Author: YangYue
// Created Time: Mon Oct 20 18:37:27 2014
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
#include <stack>
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

bool instack[1111];
int a[1111];

int main()
{
	//freopen("in","r",stdin);

	int n = 0;
	while (scanf("%d", &n) != EOF && n) {
		while (1) {
			scanf("%d", &a[0]);
			if (a[0] == 0) break;
			for (int i = 1; i < n; ++i) scanf("%d", &a[i]);
			stack<int> STACK;
			memset(instack, 0, sizeof instack);
			int now = 1;
			bool yes = true;
			for (int i = 0; i < n; ++i) {
				for (; now <= a[i]; ++now) STACK.push(now);
				if (!STACK.empty() && STACK.top() == a[i]) {
					STACK.pop();
					continue;
				} else {
					yes = false;
					break;
				}
			}
			if (yes) puts("Yes"); else puts("No");
		}
		puts("");
	}
	
	return 0;
}

// hehe ~


