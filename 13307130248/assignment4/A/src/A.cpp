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
	int tmp;
	vector<int> A;

	// input
	while(scanf("%d", &tmp), A.push_back(tmp), tmp != 0)
	{
		stack<int> S;
		for(int i = 1; i < N; i++) scanf("%d", &tmp), A.push_back(tmp);
		
		int j = 0;
		for(int i = 0; i < N; i++)
		{
			S.push(i + 1);
			while(!S.empty() && j < N && S.top() == A[j])
			{
				S.pop();
				j++;
			}
		}

		if(j == N)
			printf("Yes\n");
		else
			printf("No\n");

		A.clear();
	}

	printf("\n");
}

int main()
{
	while(scanf("%d", &N), N != 0)
	{
		work();
	}
	return 0;
}
