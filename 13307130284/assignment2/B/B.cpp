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

multiset<int> S;
int n;
int main() {
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	int n; cin >> n;
	S.clear();
	For(i,1,n) {
		int c;
		scanf("%d", &c);
		S.insert(c);
	}
	int ans = 0;
	For(i,1,n - 1) {
		set<int> :: iterator it = S.begin();
		int a = *it;
		++it;
		int b = *it;
		ans += (a + b);
		S.erase(S.begin());
		S.erase(S.begin());
		S.insert(a + b);
	}
	cout << ans << endl;
	return 0;
}

