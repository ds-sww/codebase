// File Name: C.cpp
// Author: YangYue
// Created Time: Mon Sep 29 18:51:07 2014
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
struct Student {
	int score, chn, idx;
	Student(){}
	Student(int score, int chn, int idx) : score(score), chn(chn), idx(idx) {}
	bool operator < (const Student &b) const {
		if (score != b.score) return score > b.score;
		if (chn != b.chn) return chn > b.chn;
		return idx < b.idx;
	}
	void init(int i) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		score = a + b + c;
		chn = a;
		idx = i;
	}
} stu[33333];

int main()
{
	//freopen("in","r",stdin);

	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) stu[i].init(i+1);
	sort(stu, stu + n);
	for (int i = 0; i < 5; ++i) printf("%d %d\n", stu[i].idx, stu[i].score);
	
	return 0;
}

// hehe ~


