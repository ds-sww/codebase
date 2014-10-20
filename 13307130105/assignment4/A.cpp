#include <bits/stdc++.h>

using namespace std;

int seq[2333];

int main(void)
{
	int N = 0;
	bool haz = false;
	while(scanf("%d",&N) != EOF && N)
	{
		while(scanf("%d",&seq[0]) != EOF && seq[0])
		{
			for(int i = 1;i < N;i++) scanf("%d",&seq[i]);
			
			bool okay = true;
			stack<int> stacky;
			int cur = 1;
			int pos = 0;
			while(pos < N && (stacky.size() || cur <= N))
			{
				if(cur <= N && cur == seq[pos])
				{
					pos++;
					cur++;
				}
				else if(stacky.size() && stacky.top() == seq[pos])
				{
					pos++;
					stacky.pop();
				}
				else if(cur <= N) stacky.push(cur++);
				else { okay = false; break; }
			}
			puts(okay ? "Yes" : "No");
		}
		puts("");
	}
	return 0;
}
