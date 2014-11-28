#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int N;
priority_queue<int> H;

void init()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		H.push(-tmp);
	}
}

void work()
{
	long long sum = 0;
	while(H.size() > 1)
	{
		int num1 = -H.top();
		H.pop();

		int num2 = -H.top();
		H.pop();

		H.push(-(num1 + num2));
		sum += num1 + num2;
	}

	cout << sum << endl;
}

int main()
{
	init();
	work();
	return 0;
}