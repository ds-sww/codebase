#include <iostream>
#include <stack>

using namespace std;

struct Pair {
	int value;
	int x;
	Pair(int a, int b) {
		value = a;
		x = b;
	}
};

int main() {
	while(1) {
		int numbers, tmp;
		cin >> numbers;
		//cout << "......" << endl;
		if(numbers == 0)
			break;
		stack<Pair> cols;
		long long answer = 0;
		int i;
		for(i = 0; i < numbers; i++) {
			cin >> tmp;
			int x = i;
			while(!cols.empty() && cols.top().value > tmp) {
				x = cols.top().x;
				answer = max(answer, (long long)(i - x) * cols.top().value);
				cols.pop();
			}
			Pair temp(tmp, x);
			cols.push(temp);
		}
		tmp = 0;
		int x = i;
		while(!cols.empty() && cols.top().value > tmp) {
			x = cols.top().x;
			answer = max(answer, (long long)(i - x) * cols.top().value);
			cols.pop();
		}
		Pair temp(tmp, x);
		cols.push(temp);
		cout << answer << endl;
	}
	return 0;
}
