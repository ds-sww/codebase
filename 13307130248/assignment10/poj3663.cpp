#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int A[20005];

void init()
{
	scanf("%d%d", &N, &S);
	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A + N);
}

void work()
{
	int left = 0, right = N - 1;
	int count = 0;
	
	for(; right > 0; right--)
	{
		while(left < right && A[right] + A[left] <= S) left++;
		count += min(right, left);
	}
	
	cout << count << endl;
}

int main()
{
	init();
	work();
	return 0;
}
