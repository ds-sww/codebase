#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> A;

void init()
{
	A.resize(N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	sort(A.begin(), A.end());
}

long long calcNotSmaller(int dist)
{
	long long count = 0;
	for(vector<int>::iterator it = A.begin(); it != A.end(); it++)
	{
		if(*it + dist <= A[N - 1]) count += A.end() - lower_bound(it, A.end(), *it + dist);
	}
	return count;
}

void work()
{
	int l = 0, r = 1000000000;
	int bias = 1 - ((N - 1) * N / 2) % 2;
	long long HalfCN2 = (long long)((N - 1) * N / 2 + 1) / 2;
	
	while(l < r)
	{
		int mid = (l + r + 1) / 2;
		
		if(calcNotSmaller(mid) >= HalfCN2 + bias)
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	
 	cout << r << endl;
}

int main()
{
	while(scanf("%d", &N) != EOF)
	{
		init();
		work();
	}
	return 0;
}
