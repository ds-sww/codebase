#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string pre, mid;

void work(int pl, int pr, int ml, int mr)
{
	if(pl >= pr) return;

	//cerr << "pl = " << pl << " pr = " << pr << "ml = " << ml << "mr = " << mr << endl;
	
	int i;
	for(i = ml; i < mr; i++)
	{
		if(mid[i] == pre[pl]) break;
	}

	work(pl + 1, pl + i - ml + 1, ml, i);
	work(pl + i - ml + 1, pr, i + 1, mr);
	cout << pre[pl];
}

int main()
{
	while(cin >> pre >> mid)
	{
		work(0, pre.length(), 0, pre.length());
		cout << endl;
	}
	return 0;
}
