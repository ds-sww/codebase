#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

typedef pair<long long, long> pairs;

int main(){
	while (1){
		long N, i, j;
		long long Max, *h;
		cin >> N;
		if (N == 0)break;
		h = new long long[N+1];
		for (i = 0; i < N; i++){
			cin >> h[i];
		}
		h[N] = 0;
		stack<pairs> Stack;
		for (i = Max = 0; i <= N; i++){
			j = i;
			while (Stack.size() != 0 && Stack.top().first > h[i]){
				j = Stack.top().second;
				Max = max(Max, Stack.top().first*(i - j));
				Stack.pop();
			}
			Stack.push(pairs(h[i], j));
		}

		cout << Max << endl;
	}
	return 0;
}
