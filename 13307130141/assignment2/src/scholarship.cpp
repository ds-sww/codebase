#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 321;

pair <pair <int, int>, int> p[N];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int chn, math, eng;
		cin >> chn >> math >> eng;
		p[i].first.first = -(chn + math + eng);
		p[i].first.second = -chn;
		p[i].second = i + 1;
	}
	sort(p, p + n);
	for(int i = 0; i < 5; i++)
		cout << p[i].second << ' ' << -p[i].first.first << '\n';
	return 0;
}