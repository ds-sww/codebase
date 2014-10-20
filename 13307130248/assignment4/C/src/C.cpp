#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Pair
{
public:
	int id, value;

	Pair(){}
	Pair(int _id, int _value)
	{
		id = _id;
		value = _value;
	}
};

class Pair2
{
public:
	int id, value;

	Pair2(){}
	Pair2(int _id, int _value)
	{
		id = _id;
		value = _value;
	}
};

bool operator< (const Pair &A, const Pair &B)
{
	return B.value < A.value;
}

bool operator< (const Pair2 &A, const Pair2 &B)
{
	return A.value < B.value;
}

int N, K;
vector<int> A, ansMax, ansMin;
priority_queue<Pair> H;
priority_queue<Pair2> H2;

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

void work()
{
	for(int i = 0; i < K; i++)
	{
		H.push(Pair(i, A[i]));
		H2.push(Pair2(i, A[i]));
	}
	printf("%d ", H.top().value);

	for(int i = K; i < N; i++)
	{
		H.push(Pair(i, A[i]));
		while(H.top().id <= i - K) H.pop();
		
		printf("%d ", H.top().value);
	}
	
	
	printf("\n");

	printf("%d ", H2.top().value);
	for(int i = K; i < N; i++)
	{
		H2.push(Pair2(i, A[i]));
		while(H2.top().id <= i - K) H2.pop();

		printf("%d ", H2.top().value);
	}
	printf("\n");
}

int main()
{
	init();
	work();
	return 0;
}
