#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

multiset <int> s;

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int w; cin >> w;
		s.insert(w);
	}
	int ans = 0;
	while(s.size() > 1)
	{
		multiset <int> :: iterator it1 = s.begin();
		int t = *it1; s.erase(it1);
		multiset <int> :: iterator it2 = s.begin();
		t += *it2; s.erase(it2);
		s.insert(t);
		ans += t;
	}
	cout << ans << '\n';
	return 0;
}