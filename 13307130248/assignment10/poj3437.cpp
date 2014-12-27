#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int N;
char S[100000];
stack<pair<int, int> > depth;

void work()
{
	N = strlen(S);
	int ans1 = 0, ans2 = 0, d2 = 0;
	depth.push(make_pair(0, 0));
	for(int i = 0; i < N; i++)
	{
		pair<int, int> &d = depth.top();

		if(S[i] == 'd')
		{
			d2++;
			d.second++;
			depth.push(make_pair(d.second, d.second));
		}
		else
		{
			d2--;
			ans1 = max(ans1, d.first);
			depth.pop();
		}
		ans2 = max(ans2, d2);
	}
	cout << ans2 << " => " << ans1 << endl;
}

int main()
{
	int T = 0;
	while(scanf("%s", S), S[0] != '#')
	{
		cout << "Tree " << ++T << ": ";
		work();
	}
	return 0;
}
