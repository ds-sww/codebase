#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int M;
string Prev, Succ;

long long pwr(int n)
{
	long long ret = 1;
	for(int i = 1; i <= n; i++) ret *= i;
	return ret;
}

int C(int n, int k)
{
	return pwr(n) / pwr(k) / pwr(n - k);
}

int find(char ch)
{
	for(int i = 0; i < Succ.length(); i++)
	{
		if(Succ[i] == ch) return i;
	}
	return -1;
}

int work(int pl, int pr, int sl, int sr)
{
	if(pl >= pr) return 1;

	//cerr << pl << " " << pr << " " << sl << " " << sr << endl;

	int ret = 1;
	int count = 0;

	for(int si = sl, pi = pl; pi < pr; )
	{
		count++;
		
		int d = find(Prev[pi]) - si;

		ret *= work(pi + 1, pi + d + 1, si, si + d);

		//cerr << d << " " << si << " " << pi  << endl;
		si += d + 1;
		pi += d + 1;
	}

	return ret * C(M, count);
}

int main()
{
	while(cin >> M >> Prev >> Succ, M != 0)
	{
		cout << work(1, Prev.length(), 0, Succ.length() - 1) << endl;
	}
	return 0;
}


