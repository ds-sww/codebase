#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, T;
vector<int> V;

void init()
{
	scanf("%d%d", &T, &N);

	V = vector<int>(N);

	for(int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		V[i] = tmp;
	}
}

bool cmp(const int &a, const int &b)
{
	return abs(a) < abs(b);
}

void work()
{
	sort(V.begin(), V.end(), cmp);

	int count = 0, sum = 0;

	for(; count < N; count++)
	{
		int dist; 
		if(count != 0)
			dist = abs(V[count] - V[count - 1]);
		else
			dist = abs(V[count]);

		if(sum + dist > T) break;

		sum += dist;
	}

	cout << count << endl;
}

int main()
{
	init();
	work();
	return 0;
}
