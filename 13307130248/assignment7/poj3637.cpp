#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int T;
vector<int> A;

void init()
{
	A.clear();

	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		A.push_back(tmp);
	}
}

void work()
{
	sort(A.begin(), A.end());

	int sum = 0;

	for(int i = N - 3; i >= 0; i -= 3)
	{
		sum += A[i];	
	}

	cout << sum << endl;
}

int main()
{
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
	{
		init();
		work();
	}
	return 0;
}
