#include <iostream>
#include <stack>

using namespace std;

class SStack {
private:
	stack<int> content;
	stack<int> maximums;
	stack<int> minimums;
public:
	/*省略构造和析构函数*/
	void push(int anum) {
		content.push(anum);
		if(maximums.empty()) {
			maximums.push(anum);
			minimums.push(anum);
		} else {
			if(maximums.top() > anum)
				maximums.push(maximums.top());
			else
				maximums.push(anum);

			if(minimums.top() < anum)
				minimums.push(minimums.top());
			else
				minimums.push(anum);
		}
	}
	int top() { return content.top(); }
	void pop() {
		content.pop();
		maximums.pop();
		minimums.pop();
	}
	int max() { return maximums.top(); }
	int min() { return minimums.top(); }
	int empty() { return content.empty(); }
};

class SQueue {
private:
	SStack left;
	SStack right;
public:
	/*省略构造和析构函数*/
	void push (int anum) {
		right.push(anum);
	}
	int top() {
		if(left.empty()) {
			while(!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		return left.top();
	}
	void pop() {
		if(left.empty()) {
			while(!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		left.pop();
	}
	int max() {
		if(left.empty())
			return right.max();
		if(right.empty())
			return left.max();

		if(left.max() > right.max())
			return left.max();
		else
			return right.max();
	}
	int min() {
		if(left.empty())
			return right.min();
		if(right.empty())
			return left.min();

		if(left.min() < right.min())
			return left.min();
		else
			return right.min();
	}
	int empty() {
		if(left.empty() && right.empty())
			return 1;
		else
			return 0;
	}
};

int main() {
	int length, width, tmp;
	cin >> length >> width;
	SQueue window;
	int result_size = length - width + 1;
	int maxs[result_size], mins[result_size];
	for(int i = 0; i < width; i++) {
		cin >> tmp;
		window.push(tmp);
	}
	maxs[0] = window.max();
	mins[0] = window.min();
	for(int j = 1; j < result_size; j++) {
		window.pop();
		cin >> tmp;
		window.push(tmp);
		maxs[j] = window.max();
		mins[j] = window.min();
	}
	//cout << endl;
	for(int a = 0; a < result_size; a++) {
		cout << mins[a] << " ";
	}
	cout << endl;
	for(int b = 0; b < result_size; b++) {
		cout << maxs[b] << " ";
	}
	cout << endl;
	return 0;
}



