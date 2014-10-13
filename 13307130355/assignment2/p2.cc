#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

multiset<int> S;
int ans = 0;

int main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	register int i;
	for(i = 0; i < n; ++ i) {
		int _;
		cin >> _;
		S.insert(_);
	}
	while(S.size() > 1) {
		int t1, t2;
		t1 = *S.begin();
		S.erase(S.begin());
		t2 = *S.begin();
		S.erase(S.begin());
		ans += t1 + t2;
		S.insert(t1 + t2);
	}
	cout << ans << endl;
	return 0;
}

