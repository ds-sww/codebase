#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1011111;

int segMax[N][14];
int segMin[N][14];

int log3[N];
int pow3[15];

int qMax(int left, int right)
{
	int tlog3 = log3[right - left];
	int tpow3 = pow3[tlog3];

	//cout << '*' << left << ' ' << right << ' ' << tlog3 << ' ' << tpow3 << '*' << '\n';

	if(tpow3 * 2 >= (right - left))
		return max(segMax[left][tlog3], segMax[right - tpow3][tlog3]);
	return max(segMax[left][tlog3],
		max(segMax[left + tpow3][tlog3], segMax[right - tpow3][tlog3]));
	/*
	int log2 = 31 - __builtin_clz(right - left);
	return max(segMax[left][log2], segMax[right - (1 << log2)][log2]);
	*/
}

int qMin(int left, int right)
{
	int tlog3 = log3[right - left];
	int tpow3 = pow3[tlog3];

	if(tpow3 * 2 >= (right - left))
		return min(segMin[left][tlog3], segMin[right - tpow3][tlog3]);
	return min(segMin[left][tlog3],
		min(segMin[left + tpow3][tlog3], segMin[right - tpow3][tlog3]));
	/*
	int log2 = 31 - __builtin_clz(right - left);
	return min(segMin[left][log2], segMin[right - (1 << log2)][log2]);
	*/
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	log3[0] = log3[1] = log3[2] = 0;
	for(int i = 3; i < N; i++)
	{
		log3[i] = log3[i / 3] + 1;
	}
	pow3[0] = 1;
	for(int i = 1; i < 15; i++)
		pow3[i] = pow3[i - 1] * 3;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", segMin[i]);
		segMax[i][0] = segMin[i][0];
	}
	for(int j = 1; j < 14; j++)
		for(int i = 0; i < n; i++)
		{
			segMax[i][j] = segMax[i][j - 1];
			segMin[i][j] = segMin[i][j - 1];
			if(i + pow3[j - 1] < n)
			{
				segMax[i][j] = max(segMax[i][j], segMax[i + pow3[j - 1]][j - 1]);
				segMin[i][j] = min(segMin[i][j], segMin[i + pow3[j - 1]][j - 1]);
			}

			if(i + 2 * pow3[j - 1] < n)
			{
				segMax[i][j] = max(segMax[i][j], segMax[i + 2 * pow3[j - 1]][j - 1]);
				segMin[i][j] = min(segMin[i][j], segMin[i + 2 * pow3[j - 1]][j - 1]);
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