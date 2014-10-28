#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string a, b;
	while(cin >> a >> b)
	{
		int n = a.size();
		int m = b.size();
		vector <int> ans(0);
		for(int i = 0; i < n - m + 1; i++)
		{
			bool flag = true;
			for(int j = 0; j < m; j++)
				if(a[i + j] != b[j])
					flag = false;
			if(flag)
				ans.push_back(i);
		}
		if(ans.size() == 0)
			cout << -1 << '\n';
		else
		{
			for(int i = 0; i < ans.size(); i++)
				if(i == 0)
					cout << ans[i];
				else cout << ' ' << ans[i];
			cout << '\n';
		}
	}
	return 0;
}