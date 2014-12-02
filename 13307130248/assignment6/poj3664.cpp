#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int> > A;
vector<int> B;

void init()
{
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; i++)
	{
		int tmp1, tmp2;
		scanf("%d%d", &tmp1, &tmp2);

		pair<int, int> tmpp(tmp1, i);

		A.push_back(tmpp);
		B.push_back(tmp2);
	}
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first > b.first;
}

void work()
{
	sort(A.begin(), A.end(), cmp);

	int maxi = A[0].second;
	for(int i = 1; i < K; i++)
	{
		if(B[A[i].second] > B[maxi]) maxi = A[i].second;
	}

	cout << maxi + 1 << endl;
}

int main()
{
	init();
	work();
	return 0;
}
