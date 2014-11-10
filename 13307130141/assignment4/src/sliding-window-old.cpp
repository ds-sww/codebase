#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1011111;

int segMax[N][20];
int segMin[N][20];

int qMax(int left, int right)
{
	int log2 = 31 - __builtin_clz(right - left);
	return max(segMax[left][log2], segMax[right - (1 << log2)][log2]);
}

int qMin(int left, int right)
{
	int log2 = 31 - __builtin_clz(right - left);
	return min(segMin[left][log2], segMin[right - (1 << log2)][log2]);
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", segMin[i]);
		segMax[i][0] = segMin[i][0];
	}
	for(int j = 1; j < 20; j++)
		for(int i = 0; i < n; i++)
		{
			if(i + (1 << (j - 1)) < n)
			{
				segMax[i][j] = max(segMax[i][j - 1], segMax[i + (1 << (j - 1))][j - 1]);
				segMin[i][j] = min(segMin[i][j - 1], segMin[i + (1 << (j - 1))][j - 1]);
			}
		}

	
	for(int i = 0; i < n - k + 1; i++)
	{
		if(i)
			printf(" ");
		printf("%d", qMin(i, i + k));
	}
	printf("\n");
	
	for(int i = 0; i < n - k + 1; i++)
	{
		if(i)
			printf(" ");
		printf("%d", qMax(i, i + k));
	}
	printf("\n");

	return 0;
}