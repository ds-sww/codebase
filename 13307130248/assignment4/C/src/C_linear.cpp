#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N, K;
vector<int> A;
deque<int> Q;

void init()
{
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		A.push_back(tmp);
	}
}

void scan(int factor = 1)
{
	Q.clear();
	for(int i = 0; i < N; i++)
	{
		while(!Q.empty() && A[Q.back()] >= A[i]) Q.pop_back();
		
		Q.push_back(i);

		while(!Q.empty() && Q.front() <= i - K) Q.pop_front();

		if(i >= K - 1) printf("%d ", factor * A[Q.front()]);
	}
}

void work()
{
	scan();
	printf("\n");
	for(int i = 0; i < N; i++) A[i] *= -1;
	scan(-1);
	printf("\n");
}

int main()
{
	init();
	work();
	return 0;
}
