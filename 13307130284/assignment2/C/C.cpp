#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

struct yy {
	int sum, chi, num;
	yy() {}
	yy(int _s, int _c, int _n) : sum(_s), chi(_c), num(_n) {}
	bool operator < (const yy &b) const {
		if (sum != b.sum) return sum < b.sum;
		if (chi != b.chi) return chi < b.chi;
		return num > b.num;
	}
}A[MaxN];

int n;
int main() {
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	cin >> n;
	For(i,1,n) {
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		A[i] = yy(a + b + c, a, i);
	}
	sort(A + 1, A + n + 1);
	reverse(A + 1, A + n + 1);
	For(i,1,min(n,5)) {
		printf("%d %d\n", A[i].num, A[i].sum);
	}
	return 0;
}

