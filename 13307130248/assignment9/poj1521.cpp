#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> cnt;
string text;
priority_queue<int> H;

void work()
{
	while(!H.empty()) H.pop();
	cnt.clear();
	cnt.resize(128, 0);

	int cost2 = 0;

	for(int i = 0; i < text.length(); i++)
	{
		cnt[text[i]]++;
	}

	for(int i = 0; i < 128; i++)
	{
		if(cnt[i])
		{
			H.push(-cnt[i]);
		}
	}

	if(H.size() == 1) cost2 += -H.top();
	while(H.size() > 1)
	{
		int num1 = -H.top();
		H.pop();

		int num2 = -H.top();
		H.pop();

		cost2 += num1 + num2;

		H.push(-(num1 + num2));
	}

	int cost1 = text.length() * 8;
	double ratio = (double)cost1 / cost2;

	printf("%d %d %.1lf\n", cost1, cost2, ratio);
}

int main()
{
	while(cin >> text, text != "END")
	{
		work();
	}
	return 0;
}