//#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<int> A, temp;
int CNT, x0, y0;

void init()
{
	for(int i = 0; i < N * M; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if(i == A.size()) A.push_back(tmp); else A[i] = tmp;
		if(tmp == 0) y0 = i / M, x0 = i % M;
	}

	if(temp.size() < A.size()) temp.resize(A.size());
}

void merge(int left, int right)
{
	int mid = (left + right + 1) / 2;

	int i, j, cnt = 0;
	for(i = left, j = mid; i < mid && j < right; )
	{
		if(A[i] < A[j])
			temp[cnt++] = A[i++], CNT += j - mid;
		else
			temp[cnt++] = A[j++];
	}

	for(; i < mid; i++) temp[cnt++] = A[i], CNT += j - mid;
	for(; j < right; j++) temp[cnt++] = A[j];

	for(int k = left; k < right; k++) A[k] = temp[k - left];
}

void sort(int left, int right)
{
	if(left == right - 1) return;

	int mid = (left + right + 1) / 2;
	sort(left, mid);
	sort(mid, right);
	merge(left, right);
}

void work()
{
	CNT = 0;
	sort(0, A.size());

	//for(int i = 0; i < A.size(); i++) cout << A[i] << " ";
	//cout << endl;
	//cerr << x0 << " " << y0 << " " << CNT << endl;
	bool flag = (((x0 + y0 + CNT) % 2) == ((M - 1 + N - 1 + M * N - 1) % 2));
	printf("%s\n", (flag ? "YES" : "NO"));
}

int main()
{
	while(scanf("%d%d", &N, &M), N != 0 || M != 0)
	{
		init();
		work();
	}
	return 0;
}
