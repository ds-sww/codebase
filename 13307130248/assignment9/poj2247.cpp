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

typedef long long ll;

int d[] = {2, 3, 5, 7};
vector<int> A;

void gen(int k, ll p)
{
	if(k == 4){
		A.push_back(p);
		return ;
	}

	for(int i = 0; p <= 2000000000; p *= d[k])
	{
		gen(k + 1, p);
	}
}

void init()
{
	gen(0, 1);

	sort(A.begin(), A.end());
}

void work()
{
	int n;
	while(scanf("%d", &n), n != 0)
	{
		int flag = n % 10;

		if(n % 100 >= 10 && n % 100 < 20) flag = -1;

		switch(flag)
		{
			case 1 : 
				printf("The %dst humble number is %d.\n", n, A[n - 1]);
				break;
			case 2 : 
				printf("The %dnd humble number is %d.\n", n, A[n - 1]);
				break;
			case 3 : 
				printf("The %drd humble number is %d.\n", n, A[n - 1]);
				break;
			default: 
				printf("The %dth humble number is %d.\n", n, A[n - 1]);
				break;
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}