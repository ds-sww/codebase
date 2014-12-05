#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<long long> dna;
vector<int> cnt;

int chg(char a)
{
	if(a == 'A') return 0;
	if(a == 'C') return 1;
	if(a == 'T') return 2;
	if(a == 'G') return 3;
	return -1;
}

void init()
{
	dna.clear();
	for(int i = 0; i < N; i++)
	{
		char s[21];
		scanf("%s", s);
		long long tmp = 0;
		for(int i = 0; i < M; i++) tmp = tmp * 4 + chg(s[i]);
		dna.push_back(tmp);
	}
}

void work()
{
	sort(dna.begin(), dna.end());

	cnt = vector<int>(N, 0);

	for(int i = 0; i < N; i++)
	{
		int j = i + 1;
		for(; j < N && dna[i] == dna[j]; j++) ;
		cnt[j - i - 1]++;
		i = j - 1;
	}

	for(int i = 0; i < N; i++)
	{
		printf("%d\n", cnt[i]);
	}
}

int main()
{
	while(scanf("%d%d", &N, &M), N != 0 && M !=0)
	{
		init();
		work();
	}
	return 0;
}
