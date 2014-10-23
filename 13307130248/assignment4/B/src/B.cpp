#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int N;

void work()
{
	vector<int> A, L(N), R(N);
	stack<int> S;

	for(int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		A.push_back(tmp);
	}

	long long ans = -1;

	for(int i = 0; i < N; i++)
	{
		while(!S.empty() && A[S.top()] > A[i])
		{
			R[S.top()] = i - 1;
			S.pop();
		}

		S.push(i);
	}

	while(!S.empty())
	{
		R[S.top()] = N - 1;
		S.pop();
	}

	for(int i = N - 1; i >= 0; i--)
	{
		while(!S.empty() && A[S.top()] > A[i])
		{
			L[S.top()] = i + 1;
			S.pop();
		}

		S.push(i);
	}

	while(!S.empty())
	{
		L[S.top()] = 0;
		S.pop();
	}

	for(int i = 0; i < N; i++) ans = max(ans, (long long)(R[i] - L[i] + 1) * A[i]);
	
	printf("%lld\n", ans);
}

int main()
{
	while(scanf("%d", &N), N != 0)
	{
		work();
	}
	return 0;
}
